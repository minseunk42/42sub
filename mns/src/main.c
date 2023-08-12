/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:42:18 by gylim             #+#    #+#             */
/*   Updated: 2023/07/28 19:38:38 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include "env_list.h"
#include "executor.h"
#include "expander.h"
#include "lexer.h"
#include "parser.h"
#include "libft.h"
#include "minishell.h"
#include "tree.h"
#include "readline/history.h"
#include "readline/readline.h"

t_gdata	g_data;

static void	declutter(char *input, t_token *lst, t_astree *tree)
{
	if (input != NULL)
		free(input);
	if (lst != NULL)
		destroy_token_list(lst);
	if (tree != NULL)
		delete_tree(tree);
}

static void	run_error(char *input, t_token *lst, t_astree *tree, char *msg)
{
	declutter(input, lst, tree);
	if (msg != NULL)
		ft_printf(STDERR_FILENO, "%s\n", msg);
}

static void	run(char *input)
{
	t_token		*lst;
	t_astree	*ast;

	lst = NULL;
	ast = NULL;
	if (lexer(input, &lst) == -1)
	{
		run_error(input, lst, ast, "minshell: lexer: quote_error");
		return ;
	}
	expander(g_data.env_list, lst);
	if (parser(lst, &ast) == -1)
	{
		run_error(input, lst, ast, "minishell: paser: syntax error");
		return ;
	}
	if (executor(ast) == -1)
	{
		run_error(input, lst, ast, NULL);
		return ;
	}
	declutter(input, lst, ast);
}

static void	loop(void)
{
	char	*input;

	while (1)
	{
		input = readline(DEFAULT_PROMPT);
		if (input == NULL)
		{
			printf("exit\n");
			break ;
		}
		if (*input)
			add_history(input);
		else
		{
			free(input);
			continue ;
		}
		run(input);
		rl_replace_line("", 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	struct termios	old_termios;

	(void)argc;
	(void)argv;
	shell_setup(&old_termios, envp);
	loop();
	if (tcsetattr(STDIN_FILENO, TCSANOW, &old_termios) == -1)
		return (EXIT_FAILURE);
	env_destroy_list(g_data.env_list);
	return (0);
}
