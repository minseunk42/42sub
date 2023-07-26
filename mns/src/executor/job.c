/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:15:06 by gylim             #+#    #+#             */
/*   Updated: 2023/07/26 15:24:53 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "executor.h"
#include "minishell.h"
#include "tree.h"

int	execute_job(const t_astree *tree)
{
	if (tree == NULL)
		return (0);
	if (is_pipeline(tree))
	{
		if (execute_pipeline(tree, -1, -1) == -1)
			return (-1);
	}
	else if (is_redirection(tree))
	{
		if (execute_rd(tree, -1, -1, 0) == -1)
			return (-1);
	}
	else if (is_data(tree))
	{
		if (execute_simplecmd(tree, -1, -1, 0) == -1)
			return (-1);
	}
	else
		return (-1);
	return (0);
}
