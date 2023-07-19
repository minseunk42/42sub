/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:14:28 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/19 19:20:11 by minseunk         ###   ########.fr       */
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

	<command>		::=		{<rdlist> <simple command> {<rdlist>}
						|	<simple command>

	<rdlist>		::=		<redirection>
						|	<redirection> <rdlist>
						|	(EMPTY)

	<redirection> 	::=		(< | << | > | >>) <path>

	<simple command>::=		<pathname> <token list>

	<token list>	::=		<token> <token list>
						|	(EMPTY)
**/

#include "parser.h"
#include "libft.h"

t_token	*g_curtoks;

int	parser(t_token *tokens, t_astree **atree)
{
	if (!tokens)
		return (-1);
	g_curtoks = tokens;
	*atree = cmdline();
	if (g_curtoks != 0 && g_curtoks->ttype != 0)
	{
		printf("Syntax Error near: %s\n", g_curtoks->data);
		return (-1);
	}
	return (0);
}
