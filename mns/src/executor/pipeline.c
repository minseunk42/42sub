/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:17:08 by gylim             #+#    #+#             */
/*   Updated: 2023/07/26 19:02:41 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "executor.h"
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

int	execute_pipeline(const t_astree *tree, int in, int out)
{
	int				fildes[2];

	if (tree == NULL)
		return (0);
	if (tree->left == NULL || tree->right == NULL)
		return (-1);
	if (pipe(fildes) == -1)
		return (-1);
	if (execute_left(tree, in, fildes[WRITE]) == -1)
		return (-1);
	if (execute_right(tree, fildes[READ], out) == -1)
		return (-1);
	close(fildes[READ]);
	close(fildes[WRITE]);
	return (0);
}
