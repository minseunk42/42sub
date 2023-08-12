/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:15:52 by gylim             #+#    #+#             */
/*   Updated: 2023/07/26 20:27:16 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtin.h"
#include "env_list.h"
#include "executor.h"
#include "libft.h"
#include "minishell.h"
#include "tree.h"

static char	*return_path_string(char *ret, char **arr, char *str)
{
	free(str);
	destroy_arr(arr);
	return (ret);
}

static char	*set_cmdpath_with_slash(const char *command)
{
	char	*ret;

	ret = ft_strjoin("/", command);
	if (ret == NULL)
		exit(EXIT_FAILURE);
	return (ret);
}

static char	*get_command_path(const char *path_env, const char *command)
{
	char	*tmp_cmd;
	char	*full_cmd_path;
	char	**arr;
	int		i;

	arr = ft_split(path_env, ':');
	if (arr == NULL)
		exit(EXIT_FAILURE);
	tmp_cmd = set_cmdpath_with_slash(command);
	if (tmp_cmd == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	while (arr[i] != NULL)
	{
		full_cmd_path = ft_strjoin(arr[i], tmp_cmd);
		if (full_cmd_path == NULL)
			exit(EXIT_FAILURE);
		if (access(full_cmd_path, F_OK | X_OK) == 0)
			return (return_path_string(full_cmd_path, arr, tmp_cmd));
		free(full_cmd_path);
		i++;
	}
	return (return_path_string(ft_strdup(command), arr, tmp_cmd));
}

char	*get_path(const t_astree *tree)
{
	char	*path_value;
	char	*ret;
	char	*command;

	command = tree->data;
	if (builtin_check(command) != -1)
		return (ft_strdup(command));
	path_value = env_get_value_or_null(g_data.env_list, "PATH");
	if (path_value == NULL)
	{
		free(path_value);
		return (ft_strdup(command));
	}
	ret = get_command_path(path_value, command);
	free(path_value);
	return (ret);
}
