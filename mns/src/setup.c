/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:19:55 by gylim             #+#    #+#             */
/*   Updated: 2023/07/15 20:15:09 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include "readline/history.h"
#include "readline/readline.h"
/*
static void	handler(int signum)
{
	if (signum == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (signum == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

static int	set_signal(void)
{
	struct sigaction	sa;

	sigfillset(&sa.sa_mask);
	sa.__sigaction_u.__sa_handler = handler;
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		return (-1);
	if (sigaction(SIGINT, &sa, NULL) == -1)
		return (-1);
	return (0);
}
*/
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

/*
 * 1. check argc
 * 2. save current terminal attribute.
 * 3. set_termios: turn off echo.
 * 4. set_signal: ignore SIGQUIT(ctrl-\), display a new prompt for SIGINT(ctrl-C).
 */
int	initial_setup(int argc, char *argv[], struct termios *old)
{
	(void)argv;
	if (argc != 1)
		exit(EXIT_SUCCESS); /* argument number error: print usage */
	if (tcgetattr(STDIN_FILENO, old) == -1)
		exit(EXIT_FAILURE); /* print error msg */
	if (set_termios() == -1)
		exit(EXIT_FAILURE);
//	if (set_signal() == -1)
//		return (-1);
	return (0);
}
