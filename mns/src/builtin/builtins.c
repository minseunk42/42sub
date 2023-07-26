/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:44:56 by gylim             #+#    #+#             */
/*   Updated: 2023/07/25 20:08:16 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "builtin.h"
#include "executor.h"
#include "libft.h"

int	builtin_exit_or_return(int exit_status)
{
	if (isatty(STDIN_FILENO) == 0)
		exit(exit_status);
	return (exit_status);
}

static void	builtin_init_arr(int (*arr[])(char **))
{
	arr[BUILTIN_CD] = ft_cd;
	arr[BUILTIN_ECHO] = ft_echo;
	arr[BUILTIN_ENV] = ft_env;
	arr[BUILTIN_EXIT] = ft_exit;
	arr[BUILTIN_EXPORT] = ft_export;
	arr[BUILTIN_PWD] = ft_pwd;
	arr[BUILTIN_UNSET] = ft_unset;
}

int	builtin_check(const char *cmd)
{
	size_t	len;

	len = ft_strlen(cmd);
	if (!ft_strncmp("cd", cmd, 2) && len == 2)
		return (BUILTIN_CD);
	if (!ft_strncmp("echo", cmd, 4) && len == 4)
		return (BUILTIN_ECHO);
	if (!ft_strncmp("env", cmd, 3) && len == 3)
		return (BUILTIN_ENV);
	if (!ft_strncmp("exit", cmd, 4) && len == 4)
		return (BUILTIN_EXIT);
	if (!ft_strncmp("export", cmd, 6) && len == 6)
		return (BUILTIN_EXPORT);
	if (!ft_strncmp("pwd", cmd, 3) && len == 3)
		return (BUILTIN_PWD);
	if (!ft_strncmp("unset", cmd, 5) && len == 5)
		return (BUILTIN_UNSET);
	return (-1);
}

int	builtin_run(const t_cmd *cmd)
{
	int			exit_status;
	int			(*funcs[7])(char **);
	t_builtin	idx;

	builtin_init_arr(funcs);
	idx = cmd->builtin;
	if (idx == BUILTIN_ERR)
		return (1);
	exit_status = funcs[idx](cmd->argv);
	return (exit_status);
}
