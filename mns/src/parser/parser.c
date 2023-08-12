/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:14:28 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/27 17:52:16 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 *
	<command line>	::= 	<job> '&&' <command line>
						|	<job> '||' <command line>
                        |   '(' <command line> ')' <command line>
                        |   '(' <command line> ')'
						|	<job>

	<job>			::=		<command> '|' <job>
						|	<command>

	<command>		::=		<rdlist> <simple command> <rdlist> <token list>
							<simple command> <rdlist> <token list>
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

int	is_term(int type, char **buf)
{
	if (!g_data.curtoken)
		return (0);
	if ((int)g_data.curtoken->ttype == type)
	{
		if (buf)
		{
			*buf = (char *)malloc(ft_strlen(g_data.curtoken->data) + 1);
			*buf = ft_strdup(g_data.curtoken->data);
		}
		g_data.curtoken = g_data.curtoken->next;
		return (1);
	}
	g_data.curtoken = g_data.curtoken->next;
	return (0);
}

int	parser(t_token *tokens, t_astree **atree)
{
	if (!tokens)
		return (-1);
	g_data.curtoken = tokens;
	*atree = cmdline();
	if (!(*atree))
		return (-1);
	if (g_data.curtoken != 0 && g_data.curtoken->ttype != 0)
		return (-1);
	return (0);
}
