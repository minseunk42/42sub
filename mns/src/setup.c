/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:19:55 by gylim             #+#    #+#             */
/*   Updated: 2023/07/28 19:11:31 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include "env_list.h"
#include "minishell.h"
#include "readline/history.h"
#include "readline/readline.h"

static void	shell_setup_handler(int signum)
{
	(void)signum;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static int	set_signal(void)
{
	struct sigaction	sa;

	sigfillset(&sa.sa_mask);
	sa.__sigaction_u.__sa_handler = shell_setup_handler;
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		return (-1);
	if (sigaction(SIGINT, &sa, NULL) == -1)
		return (-1);
	return (0);
}

static int	set_termios(void)
{
	struct termios	new;

	if (tcgetattr(STDIN_FILENO, &new) == -1)
		return (-1);
	new.c_lflag &= ~ECHOCTL;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &new) == -1)
		return (-1);
	return (0);
}

static int	shell_init(struct termios *old, char **envp)
{
	if (set_signal() == -1)
		return (-1);
	if (tcgetattr(STDIN_FILENO, old) == -1)
	{
		perror("minishell");
		exit(EXIT_FAILURE);
	}
	if (set_termios() == -1)
	{
		perror("minishell");
		return (-1);
	}
	g_data.env_list = env_new_list(envp);
	if (g_data.env_list == NULL)
	{
		perror("minishell");
		return (-1);
	}
	g_data.last_exit_status = 0;
	g_data.internal_envp = NULL;
	return (0);
}

void	shell_setup(struct termios *old, char **envp)
{
	if (shell_init(old, envp) == -1)
	{
		if (tcsetattr(STDIN_FILENO, TCSANOW, old) == -1)
			perror("minishell");
		exit(EXIT_FAILURE);
	}
}
