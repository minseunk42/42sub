/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:14:47 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/21 15:45:44 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "tree.h"
# include "lexer.h"
# include "libft.h"
# include "tree.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

extern t_token	*g_curtoks;

int			parser(t_token *tokens, t_astree **atree);
int			is_term(int type, char **buf);
t_astree	*cmdline(void);
t_astree	*cmdline1(void);
t_astree	*job(void);
t_astree	*job1(void);
t_astree	*job2(void);
t_astree	*cmd(void);
t_astree	*cmd1(void);
t_astree	*cmd2(void);
t_astree	*cmd3(void);
t_astree	*cmd4(void);
t_astree	*simplecmd(void);
t_astree	*simplecmd1(void);
t_astree	*tokenlist(void);
t_astree	*tokenlist1(void);
t_astree	*rdlist(void);
t_astree	*rdlist1(void);
t_astree	*rdlist2(t_astree	*rdnode);
t_astree	*redirection(void);
t_astree	*redirection1(void);


#endif