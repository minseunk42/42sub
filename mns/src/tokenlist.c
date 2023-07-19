/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:33:27 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/17 19:24:34 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_token	*g_curtoks;

t_astree	*tokenlist1(void)
{
	t_astree	*tltnode;
	t_astree	*result;
	char		*arg;

	if (!is_term(T_TYPE_GENERAL, &arg))
		return (0);
	tltnode = tokenlist();
	result = malloc(sizeof(*result));
	create_node(result, AT_TYPE_DATA, arg);
	add_tree(result, 0, tltnode);
	return (result);
}

t_astree	*tokenlist2(void)
{
	return (0);
}

t_astree	*tokenlist(void)
{
	t_token		*save;
	t_astree	*node;

	save = g_curtoks;
	node = tokenlist1();
	if (node)
		return (node);
	g_curtoks = save;
	node = tokenlist2();
	if (!node)
		return (node);
	return (0);
}
