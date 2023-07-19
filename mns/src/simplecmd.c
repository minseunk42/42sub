/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplecmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:26:51 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/19 19:18:37 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

extern t_token	*g_curtoks;

t_astree	*simplecmd(void)
{
	return (simplecmd1());
}

t_astree	*simplecmd1(void)
{
	t_astree	*tltnode;
	t_astree	*result;
	char		*cmd;

	if (!is_term(T_TYPE_GENERAL, &cmd))
		return (0);
	tltnode = tokenlist();
	result = malloc(sizeof(*result));
	create_node(result, AT_TYPE_DATA, cmd);
	add_tree(result, 0, tltnode);
	return (result);
}
