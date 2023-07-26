/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:13:05 by gylim             #+#    #+#             */
/*   Updated: 2023/07/26 19:02:41 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtin.h"
#include "executor.h"
#include "minishell.h"

static int	run_on_main_shell(const t_cmd *cmd)
{
	int	fildes[2];
	int	status;

	fildes[0] = dup(STDIN_FILENO);
	fildes[1] = dup(STDOUT_FILENO);
	dup2(cmd->in, STDIN_FILENO);
	dup2(cmd->out, STDOUT_FILENO);
	if (cmd->in != STDIN_FILENO)
		close(cmd->in);
	if (cmd->out != STDOUT_FILENO)
		close(cmd->out);
	status = builtin_run(cmd);
	dup2(fildes[0], STDIN_FILENO);
	dup2(fildes[1], STDOUT_FILENO);
	return (status);
}

static void	run_on_subshell(const t_cmd *cmd)
{
	int	status;

	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	dup2(cmd->in, STDIN_FILENO);
	dup2(cmd->out, STDOUT_FILENO);
	if (cmd->in != STDIN_FILENO)
		close(cmd->in);
	if (cmd->out != STDOUT_FILENO)
		close(cmd->out);
	close(STDIN_FILENO);
	status = builtin_run(cmd);
	exit(status);
}

static void	wait_in_mainshell(const t_cmd *cmd, int id)
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

int	execute_builtin(const t_cmd *cmd, int is_subshell)
{
	pid_t	id;

	if (!is_subshell)
		return (run_on_main_shell(cmd));
	id = fork();
	if (id < 0)
		exit(EXIT_FAILURE);
	if (id == 0)
		run_on_subshell(cmd);
	else
		wait_in_mainshell(cmd, id);
	return (0);
}
