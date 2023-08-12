/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:34:26 by gylim             #+#    #+#             */
/*   Updated: 2023/07/28 19:14:42 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "executor.h"
#include "minishell.h"

static void	run_cmd_subshell(const t_cmd *cmd)
{
	signal(SIGQUIT, SIG_DFL);
	dup2(cmd->in, STDIN_FILENO);
	dup2(cmd->out, STDOUT_FILENO);
	close_all_pipes();
	if (cmd->in != STDIN_FILENO)
		close(cmd->in);
	if (cmd->out != STDOUT_FILENO)
		close(cmd->out);
	close_all_pipes();
	if (execve(cmd->path, cmd->argv, cmd->envp) == -1)
		rd_perror(cmd->path);
	exit(EXIT_FAILURE);
}

void	run_cmd(const t_cmd *cmd, int is_subshell)
{
	pid_t	id;

	if (cmd->builtin != -1)
	{
		execute_builtin(cmd, is_subshell);
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
		run_cmd_subshell(cmd);
}
