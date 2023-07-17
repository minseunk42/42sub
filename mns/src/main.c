/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:42:18 by gylim             #+#    #+#             */
/*   Updated: 2023/07/17 19:34:09 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include "env_list.h"
#include "expander.h"
#include "lexer.h"
#include "libft.h"
#include "tree.h"
#include "parser.h"
#include "minishell.h"
#include "readline/history.h"
#include "readline/readline.h"

static int	check_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	is_exit(const char *input)
{
	int	i;
	int	j;

	i = 0;
	while (input[i] != '\0' && check_set(input[i], WHITESPACE))
		i++;
	if (input[i] == '\0')
		return (FALSE);
	j = 0;
	while (j < 4)
	{
		if (input[i] != "exit"[j])
			return (FALSE);
		i++;
		j++;
	}
	if (input[i] == '\0' || check_set(input[i], WHITESPACE))
		return (TRUE);
	return (FALSE);
}

void printast(t_astree		*ast)
{
	if (ast)
		return ;
	printf("%s\n",ast->data);
	printast(ast->left);
	printast(ast->right);
}

int	main(int argc, char *argv[])
{
	char			*input;
	t_token			*tokens;
	t_env_list		*env_list;
	struct termios	old_termios;
	t_astree		*ast;

	if (initial_setup(argc, argv, &old_termios) == -1)
		return (EXIT_FAILURE);
	env_list = env_new_list();
	if (env_list == NULL)
		return (EXIT_FAILURE);
	while (1)
	{
		input = readline(DEFAULT_PROMPT);
		if (!input || is_exit(input))
		{
			printf("exit...\n");
			free(input);
			break ;
		}
		if (*input)
			add_history(input);
		if (lexer(input, &tokens) == -1)
			return (printf("exit...\n"));
		expander(env_list, tokens);
		/* lexer list print - for debug */
		while (tokens)
		{
			//printf("data = %s, ttype = %d, qtype = %d\n", tokens->data, tokens->ttype, tokens->qtype);
			tokens = tokens->next;
		}
		/* lexer list print - for debug */
		free(input);
		parser(tokens, &ast);
		printast(ast);
		destroy_token_list(tokens);
		tokens = NULL;
		input = NULL;
	}
	if (tcsetattr(STDIN_FILENO, TCSANOW, &old_termios) == -1)
		return (EXIT_FAILURE);
	return (0);
}
