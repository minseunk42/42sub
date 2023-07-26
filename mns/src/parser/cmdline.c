/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:12:34 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/26 18:59:41 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_astree	*cmdline1(void)
{
	return (job());
}

t_astree	*cmdline(void)
{
	t_astree	*node;

	node = cmdline1();
	if (node)
		return (node);
	return (0);
}
