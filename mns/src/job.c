/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:14:44 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/17 19:31:14 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_token	*g_curtoks;

t_astree	*job1(void)
{
	return (cmd());
}

t_astree	*job2(void)
{
	t_astree	*cmdnode;
	t_astree	*jobnode;
	t_astree	*result;

	cmdnode = cmd();
	if (!cmdnode)
		return (0);
	if (!is_term(T_TYPE_PIPE, 0))
	{
		delete_tree(cmdnode);
		return (0);
	}
	jobnode = job();
	if (!jobnode)
	{
		delete_tree(cmdnode);
		return (0);
	}
	result = malloc(sizeof(*result));
	create_node(result, AT_TYPE_PIPE, "|");
	add_tree(result, cmdnode, jobnode);
	return (result);
}

t_astree	*job(void)
{
	t_token		*save;
	t_astree	*node;

	save = g_curtoks;
	node = job1();
	if (node)
		return (node);
	save = g_curtoks;
	node = job2();
	if (node)
		return (node);
	return (0);
}
