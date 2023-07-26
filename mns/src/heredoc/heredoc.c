/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:56:58 by gylim             #+#    #+#             */
/*   Updated: 2023/07/26 19:02:41 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "executor.h"
#include "libft.h"
#include "minishell.h"
#include "readline/readline.h"

static int	heredoc_prompt(char *delimiters[], int heredoc_cnt)
{
	int				i;
	int				fd;
	char			*input;

	i = 0;
	while (i < heredoc_cnt)
	{
		fd = heredoc_open_file(i);
		while (TRUE)
		{
			input = readline("> ");
			if (input == NULL)
				exit(EXIT_FAILURE);
			if (is_same_string(input, delimiters[i]))
				break ;
			write(fd, input, ft_strlen(input));
			write(fd, "\n", 1);
			free(input);
		}
		close(fd);
		i++;
	}
	return (0);
}

static void	input_child(char *dlmts[], int cnt)
{
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	if (heredoc_prompt(dlmts, cnt) == -1)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

int	heredoc_input(char *delimiters[], int heredoc_cnt)
{
	pid_t			id;
	int				status;

	id = fork();
	if (id < 0)
		return (-1);
	if (id == 0)
		input_child(delimiters, heredoc_cnt);
	else
	{
		waitpid(id, &status, 0);
		if (ft_wifexited(status))
		{
			g_data.last_exit_status = ft_wexitstatus(status);
			return (0);
		}
		g_data.last_exit_status = 1;
		return (-1);
	}
	return (0);
}
