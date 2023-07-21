/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:18:23 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/21 15:49:34 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

extern t_token	*g_curtoks;

t_astree	*cmd(void)
{
	t_token		*save;
	t_astree	*node;

	save = g_curtoks;
	node = cmd1();
	if (node)
		return (node);
	g_curtoks = save;
	node = cmd2();
	if (node)
		return (node);
	g_curtoks = save;
	node = cmd3();
	if (node)
		return (node);
	g_curtoks = save;
	node = cmd4();
	if (node)
		return (node);
	return (0);
}

t_astree	*cmd4(void)
{
	return (simplecmd());
}

t_astree	*cmd1(void)
{
	t_astree	*rdnode;
	t_astree	*scmdnode;
	t_astree	*result;

	rdnode = rdlist();
	if (!rdnode)
		return (0);
	scmdnode = simplecmd();
	if (!scmdnode)
		return (0);
	rdnode = rdlist2(rdnode);
	if (!rdnode)
		return (0);
	result = malloc(sizeof(*result));
	create_node(result, AT_TYPE_RD, "RD");
	add_tree(result, rdnode, scmdnode);
	return (result);
}

t_astree	*cmd2(void)
{
	t_astree	*rdnode;
	t_astree	*scmdnode;
	t_astree	*result;

	rdnode = rdlist();
	if (!rdnode)
		return (0);
	scmdnode = simplecmd();
	if (!scmdnode)
		return (0);
	result = malloc(sizeof(*result));
	create_node(result, AT_TYPE_RD, "RD");
	add_tree(result, rdnode, scmdnode);
	return (result);
}

t_astree	*cmd3(void)
{
	t_astree	*rdnode;
	t_astree	*scmdnode;
	t_astree	*result;

	scmdnode = simplecmd();
	if (!scmdnode)
		return (0);
	rdnode = rdlist();
	if (!rdnode)
		return (0);
	result = malloc(sizeof(*result));
	create_node(result, AT_TYPE_RD, "RD");
	add_tree(result, rdnode, scmdnode);
	return (result);
}