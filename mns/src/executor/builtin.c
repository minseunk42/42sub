/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:13:05 by gylim             #+#    #+#             */
/*   Updated: 2023/07/28 19:45:25 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtin.h"
#include "executor.h"
#include "minishell.h"

static void	run_on_main_shell(const t_cmd *cmd)
{
	int	fildes[2];

	fildes[0] = dup(STDIN_FILENO);
	fildes[1] = dup(STDOUT_FILENO);
	dup2(cmd->in, STDIN_FILENO);
	dup2(cmd->out, STDOUT_FILENO);
	close_all_pipes();
	if (cmd->in != STDIN_FILENO)
		close(cmd->in);
	if (cmd->out != STDOUT_FILENO)
		close(cmd->out);
	g_data.last_exit_status = builtin_run(cmd);
	dup2(fildes[0], STDIN_FILENO);
	dup2(fildes[1], STDOUT_FILENO);
}

static void	run_on_subshell(const t_cmd *cmd)
{
	int	status;

	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	dup2(cmd->in, STDIN_FILENO);
	dup2(cmd->out, STDOUT_FILENO);
	close_all_pipes();
	if (cmd->in != STDIN_FILENO)
		close(cmd->in);
	if (cmd->out != STDOUT_FILENO)
		close(cmd->out);
	close(STDIN_FILENO);
	status = builtin_run(cmd);
	exit(status);
}

void	execute_builtin(const t_cmd *cmd, int is_subshell)
{
	pid_t	id;

	if (!is_subshell)
	{
		run_on_main_shell(cmd);
		return ;
	}
	id = fork();
	g_data.last_pid = id;
	if (id < 0)
	{
		perror("minishell");
		exit(EXIT_FAILURE);
	}
	if (id == 0)
		run_on_subshell(cmd);
}
