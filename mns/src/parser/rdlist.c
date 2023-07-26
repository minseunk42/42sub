/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdlist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:49:50 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/26 19:00:03 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_atype	get_rd_type(t_ttype type)
{
	if (type == T_TYPE_IN)
		return (AT_TYPE_IN);
	if (type == T_TYPE_OUT)
		return (AT_TYPE_OUT);
	if (type == T_TYPE_APPEND)
		return (AT_TYPE_APPEND);
	if (type == T_TYPE_HEREDOC)
		return (AT_TYPE_HEREDOC);
	return (AT_TYPE_DATA);
}

t_astree	*redirection(void)
{
	t_astree	*result;
	char		*path;
	t_ttype		type;

	if (!g_data.curtoken || !(g_data.curtoken->next))
		return (0);
	type = g_data.curtoken->ttype;
	if (type == T_TYPE_IN || type == T_TYPE_OUT \
	|| type == T_TYPE_HEREDOC || type == T_TYPE_APPEND)
	{
		g_data.curtoken = g_data.curtoken->next;
	}
	else
		return (0);
	if (!is_term(T_TYPE_GENERAL, &path))
		return (0);
	result = malloc(sizeof(*result));
	create_node(result, (AT_TYPE_DATA | get_rd_type(type)), path);
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
	add_tree(rdnode, rdlnode, 0);
	return (rdnode);
}

t_astree	*rdlist2(t_astree	*rdnode)
{
	t_astree	*rdlnode;

	if (!(rdnode))
		return (0);
	rdlnode = rdlist();
	add_tree(rdnode, rdnode->left, rdlnode);
	return (rdnode);
}

t_astree	*rdlist(void)
{
	t_astree	*node;
	t_token		*save;

	save = g_data.curtoken;
	node = rdlist1();
	if (node)
		return (node);
	g_data.curtoken = save;
	return (0);
}
