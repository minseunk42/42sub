/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:37:42 by gylim             #+#    #+#             */
/*   Updated: 2023/07/26 19:02:41 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "builtin.h"
#include "executor.h"
#include "minishell.h"
#include "tree.h"

char	*get_path(const t_astree *tree);

static int	count_arg(const t_astree *tree)
{
	int	i;

	i = 0;
	while (tree != NULL)
	{
		i++;
		tree = tree->right;
	}
	return (i);
}

static char	**get_argv(const t_astree *tree)
{
	int			i;
	int			argc;
	char		**argv;

	argc = count_arg(tree);
	argv = (char **)malloc(sizeof(char *) * (argc + 1));
	if (argv == NULL)
		return (NULL);
	i = 0;
	while (tree != NULL)
	{
		argv[i] = tree->data;
		tree = tree->right;
		i++;
	}
	argv[i] = NULL;
	return (argv);
}

void	set_cmd(t_cmd *cmd, t_ctree *argv, t_ctree *path)
{
	cmd->argv = get_argv(argv);
	cmd->path = get_path(path);
	cmd->envp = g_data.internal_envp;
	cmd->builtin = builtin_check(cmd->path);
}
