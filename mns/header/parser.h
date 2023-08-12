/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:14:47 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/27 17:55:51 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"
# include "tree.h"
# include "lexer.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

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
t_astree	*tokenlist2(t_astree	*scnode);
t_astree	*rdlist(void);
t_astree	*rdlist1(void);
t_astree	*rdlist2(t_astree	*rdnode);
t_astree	*redirection(void);
t_astree	*redirection1(void);

#endif