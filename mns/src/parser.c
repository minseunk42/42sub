/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:14:28 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/21 18:26:18 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 *
	<command line>	::= 	<job> '&&' <command line>
						|	<job> '||' <command line>
                        |   '(' <job> ')'
						|	<job>

	<job>			::=		<command> '|' <job>
						|	<command>

	<command>		::=		<rdlist> <simple command> <rdlist>
							<simple command> <rdlist>
							<rdlist> <simple command>
						|	<simple command>

	<rdlist>		::=		<redirection> <rdlist>
						|	(EMPTY)

	<redirection> 	::=		(< | << | > | >>) <path>

	<simple command>::=		<pathname> <token list>

	<token list>	::=		<token> <token list>
						|	(EMPTY)
**/

#include "parser.h"
#include "libft.h"

t_token	*g_curtoks;

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

int	parser(t_token *tokens, t_astree **atree)
{
	t_token	*head_temp;

	if (!tokens)
		return (-1);
	head_temp = tokens;
	g_curtoks = tokens;
	*atree = cmdline();
	if (g_curtoks != 0 && g_curtoks->ttype != 0)
		return (-1);
	destroy_token_list(head_temp);
	return (0);
}
