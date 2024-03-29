/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:48:32 by gylim             #+#    #+#             */
/*   Updated: 2023/07/28 19:01:19 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "executor.h"
#include "minishell.h"

int	executor(t_astree *tree)
{
	if (tree == NULL)
		return (-1);
	if (heredoc(tree) == -1)
		return (-1);
	if (set_envp() == -1)
		return (-1);
	if (execute_job(tree) == -1)
		return (-1);
	wait_loop();
	destroy_envp();
	return (0);
}
