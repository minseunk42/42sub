/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:17:31 by gylim             #+#    #+#             */
/*   Updated: 2023/07/26 20:27:16 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "executor.h"
#include "libft.h"
#include "minishell.h"
#include "tree.h"

int	execute_rd(const t_astree *tree, int in, int out, int is_subshell)
{
	t_cmd	cmd;

	if (tree == NULL)
		return (0);
	init_cmd(&cmd);
	if (in != -1)
		cmd.in = in;
	if (out != -1)
		cmd.out = out;
	set_cmd(&cmd, tree->right, tree->right);
	if (set_rd_recursive(tree->left, &cmd) == -1)
	{
		g_data.last_exit_status = 1;
		return (-1);
	}
	run_cmd(&cmd, is_subshell);
	destroy_cmd(&cmd);
	return (0);
}

void	rd_perror(const char *filepath)
{
	ft_printf(STDERR_FILENO, "minishell: %s: %s\n", filepath, strerror(ENOENT));
}
