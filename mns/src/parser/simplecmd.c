/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplecmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:26:51 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/26 19:00:08 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
