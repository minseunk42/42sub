/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:18:23 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/26 19:00:47 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_astree	*cmd(void)
{
	t_token		*save;
	t_astree	*node;

	save = g_data.curtoken;
	node = cmd1();
	if (node)
		return (node);
	g_data.curtoken = save;
	node = cmd2();
	if (node)
		return (node);
	g_data.curtoken = save;
	node = cmd3();
	if (node)
		return (node);
	g_data.curtoken = save;
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
	t_astree	*scnode;
	t_astree	*result;

	rdnode = rdlist();
	if (!rdnode)
		return (0);
	scnode = simplecmd();
	if (!scnode)
		return (0);
	rdnode = rdlist2(rdnode);
	if (!rdnode)
		return (0);
	scnode = tokenlist2(scnode);
	result = malloc(sizeof(*result));
	create_node(result, AT_TYPE_RD, "RD");
	add_tree(result, rdnode, scnode);
	return (result);
}

t_astree	*cmd2(void)
{
	t_astree	*rdnode;
	t_astree	*scnode;
	t_astree	*result;

	rdnode = rdlist();
	if (!rdnode)
		return (0);
	scnode = simplecmd();
	if (!scnode)
		return (0);
	result = malloc(sizeof(*result));
	create_node(result, AT_TYPE_RD, "RD");
	add_tree(result, rdnode, scnode);
	return (result);
}

t_astree	*cmd3(void)
{
	t_astree	*rdnode;
	t_astree	*scnode;
	t_astree	*result;

	scnode = simplecmd();
	if (!scnode)
		return (0);
	rdnode = rdlist();
	if (!rdnode)
		return (0);
	scnode = tokenlist2(scnode);
	result = malloc(sizeof(*result));
	create_node(result, AT_TYPE_RD, "RD");
	add_tree(result, rdnode, scnode);
	return (result);
}
