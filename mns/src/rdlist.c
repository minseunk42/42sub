/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdlist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:49:50 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/20 20:16:48 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

extern t_token	*g_curtoks;

t_astree	*redirection(void)
{
	t_astree	*result;
	char		*path;
	int			type;

	if (!g_curtoks || !(g_curtoks->next))
		return (0);
	type = g_curtoks->ttype;
	if (type == T_TYPE_IN || type == T_TYPE_OUT \
	|| type == T_TYPE_HEREDOC || type == T_TYPE_APPEND)
	{
		g_curtoks = g_curtoks->next;
	}
	else
		return (0);
	if (!is_term(T_TYPE_GENERAL, &path))
		return (0);
	result = malloc(sizeof(*result));
	create_node(result, (AT_TYPE_DATA | type), path);
	add_tree(result, 0, 0);
	return (result);
}

t_astree	*rdlist1(void)
{
	t_astree	*rdnode;
	t_astree	*rdlnode;

	rdnode = redirection();
	if (!rdnode)
		return (0);
	rdlnode = rdlist();
	add_tree(rdnode, 0, rdlnode);
	return (rdnode);
}

t_astree	*rdlist(void)
{
	t_astree	*node;
	t_token		*save;

	save = g_curtoks;
	node = rdlist1();
	if (node)
		return (node);
	g_curtoks = save;
	return (0);
}
