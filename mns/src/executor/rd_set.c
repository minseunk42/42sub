/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:18:02 by gylim             #+#    #+#             */
/*   Updated: 2023/07/26 19:02:58 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "executor.h"
#include "minishell.h"
#include "tree.h"

static int	redirection_stdin(t_astree *tree, t_cmd *cmd)
{
	int	fd;

	fd = open(tree->data, O_RDONLY);
	if (fd == -1)
	{
		rd_perror(tree->data);
		return (-1);
	}
	if (cmd->in != STDIN_FILENO)
		close(cmd->in);
	cmd->in = fd;
	return (0);
}

static int	redirection_stdout(t_astree *tree, t_cmd *cmd)
{
	int	fd;

	fd = open(tree->data, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		rd_perror(tree->data);
		return (-1);
	}
	if (cmd->out != STDOUT_FILENO)
		close(cmd->out);
	cmd->out = fd;
	return (0);
}

static int	redirection_stdout_append(t_astree *tree, t_cmd *cmd)
{
	int	fd;

	fd = open(tree->data, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd == -1)
	{
		rd_perror(tree->data);
		return (-1);
	}
	if (cmd->out != STDOUT_FILENO)
		close(cmd->out);
	cmd->out = fd;
	return (0);
}

static int	redirection_heredoc(t_cmd *cmd)
{
	int				fd;

	fd = heredoc_open_file2(g_data.heredoc_idx++);
	if (fd == -1)
	{
		perror("minishell");
		return (-1);
	}
	if (cmd->in != STDIN_FILENO)
		close(cmd->in);
	cmd->in = fd;
	return (0);
}

int	set_rd_recursive(t_astree *tree, t_cmd *cmd)
{
	int	ret;

	ret = 0;
	if (tree == NULL)
		return (0);
	if (is_stdin(tree))
		ret = redirection_stdin(tree, cmd);
	else if (is_stdout(tree))
		ret = redirection_stdout(tree, cmd);
	else if (is_stdout_append(tree))
		ret = redirection_stdout_append(tree, cmd);
	else if (is_stdin_heredoc(tree))
		ret = redirection_heredoc(cmd);
	if (ret == -1)
		return (-1);
	if (tree->left != NULL && set_rd_recursive(tree->left, cmd) == -1)
		return (-1);
	if (tree->right != NULL && set_rd_recursive(tree->right, cmd) == -1)
		return (-1);
	return (0);
}
