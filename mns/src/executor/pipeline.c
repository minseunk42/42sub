/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:17:08 by gylim             #+#    #+#             */
/*   Updated: 2023/07/28 20:30:34 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "executor.h"
#include "libft.h"
#include "minishell.h"
#include "tree.h"

static int	execute_left(const t_astree *tree, int in, int out)
{
	if (is_redirection(tree->left))
	{
		if (execute_rd(tree->left, in, out, 1) == -1)
			return (-1);
	}
	else
	{
		if (execute_simplecmd(tree->left, in, out, 1) == -1)
			return (-1);
	}
	return (0);
}

static int	execute_right(const t_astree *tree, int in, int out)
{
	if (is_pipeline(tree->right))
	{
		if (execute_pipeline(tree->right, in, out) == -1)
			return (-1);
	}
	else if (is_redirection(tree->right))
	{
		if (execute_rd(tree->right, in, out, 1) == -1)
			return (-1);
	}
	else
	{
		if (execute_simplecmd(tree->right, in, out, 1) == -1)
			return (-1);
	}
	return (0);
}

static void	add_pipe_info_into_global_arr(int fildes[2])
{
	if (g_data.pipe_idx >= PIPE_MAX)
	{
		ft_printf(STDERR_FILENO, "minishell: too many pipes\n");
		exit(EXIT_FAILURE);
	}
	g_data.pipes[g_data.pipe_idx][READ] = fildes[READ];
	g_data.pipes[g_data.pipe_idx][WRITE] = fildes[WRITE];
	g_data.pipe_idx++;
}

int	execute_pipeline(const t_astree *tree, int in, int out)
{
	int	fildes[2];

	if (tree == NULL)
		return (0);
	if (tree->left == NULL || tree->right == NULL)
		return (-1);
	if (pipe(fildes) == -1)
	{
		perror("minishell");
		exit(EXIT_FAILURE);
	}
	add_pipe_info_into_global_arr(fildes);
	if (execute_left(tree, in, fildes[WRITE]) == -1)
		return (-1);
	if (execute_right(tree, fildes[READ], out) == -1)
		return (-1);
	close(fildes[READ]);
	close(fildes[WRITE]);
	return (0);
}
