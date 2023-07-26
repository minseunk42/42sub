/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:14:35 by gylim             #+#    #+#             */
/*   Updated: 2023/07/26 18:38:58 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "executor.h"

void	destroy_cmd(t_cmd *cmd)
{
	if (cmd->path != NULL)
		free(cmd->path);
	if (cmd->argv != NULL)
		free(cmd->argv);
	cmd->envp = NULL;
}

void	init_cmd(t_cmd *cmd)
{
	cmd->path = NULL;
	cmd->argv = NULL;
	cmd->envp = NULL;
	cmd->in = STDIN_FILENO;
	cmd->out = STDOUT_FILENO;
	cmd->builtin = -1;
}
