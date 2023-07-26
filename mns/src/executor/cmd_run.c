/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:34:26 by gylim             #+#    #+#             */
/*   Updated: 2023/07/26 19:02:41 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
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
	if (cmd->in != STDIN_FILENO)
		close(cmd->in);
	if (cmd->out != STDOUT_FILENO)
		close(cmd->out);
	if (execve(cmd->path, cmd->argv, cmd->envp) == -1)
		rd_perror(cmd->path);
	exit(EXIT_FAILURE);
}

static void	run_cmd_wait(const t_cmd *cmd, int id)
{
	int				status;

	if (cmd->in != STDIN_FILENO)
		close(cmd->in);
	if (cmd->out != STDOUT_FILENO)
		close(cmd->out);
	waitpid(id, &status, 0);
	if (ft_wifexited(status))
		g_data.last_exit_status = ft_wexitstatus(status);
	else
		g_data.last_exit_status = 1;
}

void	run_cmd(const t_cmd *cmd, int is_subshell)
{
	pid_t			id;
	int				builtin_ret;

	if (cmd->builtin != -1)
	{
		builtin_ret = 0;
		builtin_ret = execute_builtin(cmd, is_subshell);
		g_data.last_exit_status = builtin_ret;
		return ;
	}
	id = fork();
	if (id < 0)
		exit(EXIT_FAILURE);
	if (id == 0)
		run_cmd_subshell(cmd);
	else
		run_cmd_wait(cmd, id);
}
