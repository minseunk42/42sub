/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:18:23 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/17 19:24:20 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_token	*g_curtoks;

t_astree	*cmd(void)
{
	t_token		*save;
	t_astree	*node;

	save = g_curtoks;
	node = cmd1();
	if (node)
		return (node);
	save = g_curtoks;
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
	if (!rdnode)
		return (0);
	add_tree(scmdnode, 0, rdnode);
	return (scmdnode);
}
