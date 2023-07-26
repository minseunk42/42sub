/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:46:19 by gylim             #+#    #+#             */
/*   Updated: 2023/07/26 14:46:44 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "builtin.h"
#include "env_list.h"
#include "libft.h"
#include "minishell.h"

int	change_directory(const char *path);

static int	is_dir(const char *path)
{
	struct stat	st;

	if (stat(path, &st) == -1)
		return (0);
	return (((st.st_mode) & S_IFMT) == S_IFDIR);
}

static int	ft_cd_error_handler(const char *path, int errnum)
{
	ft_printf(STDERR_FILENO, "minishell: cd: %s: %s\n", path, strerror(errnum));
	return (EXIT_FAILURE);
}

static int	go_to_home(void)
{
	char			*home_path;
	extern t_gdata	g_data;

	home_path = env_get_value_or_null(g_data.env_list, "HOME");
	if (home_path == NULL)
	{
		ft_printf(STDERR_FILENO, "minishell: cd: HOME not set\n");
		return (EXIT_FAILURE);
	}
	if (!is_dir(home_path))
	{
		free(home_path);
		return (ft_cd_error_handler(home_path, ENOENT));
	}
	if (chdir(home_path) == -1)
	{
		free(home_path);
		perror("minishell: cd");
		return (EXIT_FAILURE);
	}
	free(home_path);
	return (EXIT_SUCCESS);
}

int	ft_cd(char **argv)
{
	int				argc;
	extern t_gdata	g_data;

	argc = get_argc(argv);
	if (argc == 1)
		return (go_to_home());
	if (!is_dir(argv[1]))
		return (ft_cd_error_handler(argv[1], ENOENT));
	if (change_directory(argv[1]) == -1)
	{
		perror("minishell: cd");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
