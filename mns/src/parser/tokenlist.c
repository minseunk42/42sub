/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:33:27 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/26 19:00:16 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_astree	*tokenlist1(void)
{
	t_astree	*tlnode;
	t_astree	*result;
	char		*arg;

	if (!is_term(T_TYPE_GENERAL, &arg))
		return (0);
	result = malloc(sizeof(*result));
	create_node(result, AT_TYPE_DATA, arg);
	tlnode = tokenlist();
	add_tree(result, 0, tlnode);
	return (result);
}

t_astree	*tokenlist2(t_astree	*scnode)
{
	t_astree	*tlnode;
	t_astree	*sclast;

	sclast = get_lastnode(scnode);
	tlnode = tokenlist();
	add_tree(sclast, 0, tlnode);
	return (scnode);
}

t_astree	*tokenlist(void)
{
	t_token		*save;
	t_astree	*node;

	save = g_data.curtoken;
	node = tokenlist1();
	if (node)
		return (node);
	g_data.curtoken = save;
	return (0);
}
