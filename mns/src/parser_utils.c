/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:43:21 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/19 19:11:49 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

extern t_token	*g_curtoks;

int	is_term(int type, char **buf)
{
	if (!g_curtoks)
		return (0);
	if ((int)g_curtoks->ttype == type)
	{
		if (buf)
		{
			*buf = (char *)malloc(ft_strlen(g_curtoks->data) + 1);
			*buf = ft_strdup(g_curtoks->data);
		}
		g_curtoks = g_curtoks->next;
		return (1);
	}
	g_curtoks = g_curtoks->next;
	return (0);
}