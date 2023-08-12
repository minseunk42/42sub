/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:06:13 by gylim             #+#    #+#             */
/*   Updated: 2023/07/28 18:07:31 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "executor.h"
#include "minishell.h"

void	close_all_pipes(void)
{
	int	i;

	i = 0;
	while (i < g_data.pipe_idx)
	{
		close(g_data.pipes[i][READ]);
		close(g_data.pipes[i][WRITE]);
		i++;
	}
}
