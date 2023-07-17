/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdlist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:49:50 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/17 19:24:27 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_token	*g_curtoks;

t_astree	*rdlist1(void)
{
	return (redirection());
}

t_astree	*rdlist2(void)
{
	t_astree	*rdnode;
	t_astree	*rdlnode;

	rdnode = redirection();
	rdlnode = rdlist();
	add_tree(rdnode, 0, rdlnode);
	return (rdnode);
}

t_astree	*rdlist3(void)
{
	return (0);
}

t_astree	*rdlist(void)
{
	t_token		*save;
	t_astree	*node;

	save = g_curtoks;
	node = rdlist1();
	if (node)
		return (node);
	save = g_curtoks;
	node = rdlist2();
	if (node)
		return (node);
	save = g_curtoks;
	node = rdlist3();
	if (node)
		return (node);
	return (0);
}