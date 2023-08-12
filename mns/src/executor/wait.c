/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:34:10 by gylim             #+#    #+#             */
/*   Updated: 2023/07/28 18:55:42 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <unistd.h>
#include "executor.h"
#include "minishell.h"

void	wait_loop(void)
{
	pid_t	id;
	int		stat;

	while (1)
	{
		id = wait(&stat);
		if (id == -1)
			break ;
		if (id == g_data.last_pid)
		{
			if (ft_wifexited(stat))
				g_data.last_exit_status = ft_wexitstatus(stat);
			else
				g_data.last_exit_status = 128 + ft_wtermsig(stat);
		}
	}
}
