/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:59:38 by gylim             #+#    #+#             */
/*   Updated: 2023/07/26 19:02:41 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "executor.h"
#include "minishell.h"
#include "tree.h"

int	heredoc_input(char *delimiters[], int heredoc_cnt);

static void	get_heredoc_cnt(t_astree *tree, int *cnt)
{
	if (is_stdin_heredoc(tree))
		(*cnt)++;
	if (tree->left != NULL)
		get_heredoc_cnt(tree->left, cnt);
	if (tree->right != NULL)
		get_heredoc_cnt(tree->right, cnt);
}

static void	get_delimiters(t_astree *tree, char **dlmts, int *idx)
{
	if (is_stdin_heredoc(tree))
	{
		dlmts[*idx] = tree->data;
		(*idx)++;
	}
	if (tree->left != NULL)
		get_delimiters(tree->left, dlmts, idx);
	if (tree->right != NULL)
		get_delimiters(tree->right, dlmts, idx);
}

int	heredoc(t_astree *tree)
{
	int				cnt;
	int				idx;
	char			**delimiters;

	cnt = 0;
	get_heredoc_cnt(tree, &cnt);
	g_data.heredoc_idx = 0;
	g_data.heredoc_cnt = cnt;
	delimiters = (char **)malloc(sizeof(char *) * (cnt));
	if (delimiters == NULL)
		return (-1);
	idx = 0;
	get_delimiters(tree, delimiters, &idx);
	if (heredoc_input(delimiters, cnt) == -1)
		return (-1);
	free(delimiters);
	return (0);
}
