/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:18:23 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/19 19:37:52 by minseunk         ###   ########.fr       */
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
	return (0);
}

t_astree	*cmd1(void)
{
	return (simplecmd());
}

t_astree	*cmd2(void)
{
	t_astree	*rdnode;
	t_astree	*scmdnode;

	scmdnode = simplecmd();
	if (!scmdnode)
		return (0);
	rdnode = rdlist();
	add_tree(scmdnode, 0, rdnode);
	return (scmdnode);
}
