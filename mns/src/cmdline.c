/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:12:34 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/17 19:34:05 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_token	*g_curtoks;

t_astree	*cmdline1(void)
{
	return (job());
}

t_astree	*cmdline(void)
{
	t_token		*save;
	t_astree	*node;

	save = g_curtoks;
	node = cmdline1();
	if (node)
		return (node);
	return (0);
}
