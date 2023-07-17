/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:40:15 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/17 19:24:29 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_token	*g_curtoks;

t_astree	*redirection1(void)
{
	t_astree	*result;
	char		*cmd;
	int			type;

	if (!g_curtoks)
		return (0);
	type = g_curtoks->ttype;
	if (type == T_TYPE_IN || type == T_TYPE_OUT \
	|| type == T_TYPE_HEREDOC || type == T_TYPE_APPEND)
	{
		g_curtoks = g_curtoks->next;
	}
	else
		return (0);
	if (!is_term(T_TYPE_GENERAL, &cmd))
		return (0);
	result = malloc(sizeof(*result));
	create_node(result, (AT_TYPE_DATA | type), cmd);
	add_tree(result, 0, 0);
	return (result);
}

t_astree	*redirection(void)
{
	return (redirection1());
}
