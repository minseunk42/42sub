/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:35:15 by gylim             #+#    #+#             */
/*   Updated: 2023/07/17 19:49:59 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "builtin.h"
#include "env_list.h"
#include "libft.h"
#include "minishell.h"

static int is_dir(const char *path)
{
	struct stat	st;

	if (stat(path, &st) == -1)
		return (0);
	return (FT_S_ISDIR(st.st_mode));
}

static int update_cwd(const char *path)
{
	extern t_gdata	g_data;

	if (g_data.cwd != NULL)
		free(g_data.cwd);
	cwd = ft_strdup(path);
	if (cwd == NULL)
		return (-1);
	return (0);
}

static int ft_cd_error_handler(const char *path, int errnum)
{
	ft_printf(STDERR_FILENO, "minishell: cd: %s: %s\n", path, strerror(errnum));
	if (!isatty(STDIN_FILENO))
		exit(EXIT_FAILURE);
	return (-1);
}

static int go_to_home(void)
{
	char			*home_path;
	extern t_gdata	g_data;

	if (isatty(STDIN_FILENO) == 1)
		home_path = env_get_value_or_null(g_data.env_list, "HOME");
	else
		home_path = getenv("HOME");
	if (home_path == NULL)
	{
		ft_printf(STDERR_FILENO, "minishell: cd: HOME not set\n");
		return (EXIT_FAILURE);
	}
	if (!is_dir(home_path))
		return (ft_cd_error_handler(path, ENOENT));
	if (chdir(home_path) == -1)
	{
		perror("minishell: cd");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int ft_cd(char **argv)
{
	int				argc;
	char			*path;
	extern t_gdata	g_data;

	argc = get_argc(argv);
	if (argc == 1)
	{
		if (go_to_home() != EXIT_SUCCESS)
			return (builtin_exit_or_return(EXIT_FAILURE));
		return (builtin_exit_or_return(EXIT_SUCCESS));
	
}
