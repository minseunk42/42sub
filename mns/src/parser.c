/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:14:28 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/15 19:51:06 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 *
	<command line>	::= 	<job> '&&' <command line>
						|	<job> '||' <command line>
                        |   '(' <job> ')'

	<job>			::=		<command> '|' <job>
						|	<command>

	<command>		::=		{<redirection>} <simple command> {<redirection>}
						|	<simple command>

	<redirection>	::=		(< | << | > | >>) <pathname>

	<simple command>::=		<pathname> <token list>

	<token list>	::=		<token> <token list>
						|	(EMPTY)
**/