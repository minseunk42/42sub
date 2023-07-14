/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:42:18 by gylim             #+#    #+#             */
/*   Updated: 2023/07/13 19:57:25 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include "env_list.h"
#include "lexer.h"
#include "libft.h"
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

int	main(int argc, char *argv[])
{
	char			*input;
	struct termios	old_termios;
	t_token			*tokens;


	if (initial_setup(argc, argv, &old_termios) == -1)
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
		lexer(input, &tokens);
		/* lexer list print - for debug */
		while (tokens)
		{
			printf("data = %s, type = %d\n", tokens->data, tokens->type);
			tokens = tokens->next;
		}
		/* lexer list print - for debug */
		free(input);
	}
	if (tcsetattr(STDIN_FILENO, TCSANOW, &old_termios) == -1)
		return (EXIT_FAILURE);
	return (0);
}
