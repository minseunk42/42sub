/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:44:56 by gylim             #+#    #+#             */
/*   Updated: 2023/07/16 17:56:48 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include "minishell.h"

static int is_zero(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	while (str[i] == ' ')
		i++;
	return (str[i] == '\0');
}

static int is_valid_range(const char *str)
{
	long long	num;

	num = ft_atoll(str);
	if (num < 0 && str[0] != '-')
		return (0);
	if (num == 0 && !is_zero(str))
		return (0);
	return (1);
}

static int is_valid_argument(const char *str)
{
	int				i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (ms_check_set(str[i], "0123456789") == 0)
			break ;
		i++;
	}
	if (str[i] != '\0' && str[i] != ' ')
		return (0);
	while (str[i] != '\0' && str[i] == ' ')
		i++;
	return (str[i] == '\0');
}

static void ft_exit_return(int exit_status, int ret_value, int exit_flag, const char *err_msg_or_null)
{
	if (err_msg_or_null != NULL)
		ft_printf(STDERR_FILENO, "%s", err_msg_or_null);
	if (isatty(STDIN_FILENO) == 0)
		exit((unsigned char)exit_status);
	//set global_exit status=(unsigned char)exit_status
	if (exit_flag == 1)
		exit((unsigned char)exit_status);
	return (ret_value);
}

void	ft_exit(char **argv)
{
	int 		argc;
	long long 	arg;

	argc = 1;
	if (argv[argc] == NULL)
	{
		if (isatty(STDIN_FILENO) == 0)
			exit(EXIT_SUCCESS); // exit status of the last command excuted.
		// set global exit status to the exit status of the last command excuted.
		return (0);
	}
	while (argv[argc] != NULL)
		argc++;
	if (argc > 2)
	{
		ft_printf(STDERR_FILENO, "minishell: exit: too many arguments\n");
		if (isatty(STDIN_FILENO) == 0)
			exit(EXIT_FAILURE);
		// set global exit status to 1.
		// return on tty process, not terminate the process.
		return (0);
	}
	if (!is_valid_argument(argv[1]) || !is_valid_range(argv[1]))
	{
		ft_printf(STDERR_FILENO, "minishell: exit: %s: numeric argument required\n", argv[1]);
		if (isatty(STDIN_FILENO) == 0)
			exit(255);
		// set global exit status to 255.
		return (0);
	}
	arg = ft_atoll(argv[1]);
	if (isatty(STDIN_FILENO) == 0)
		exit((unsigned char)arg);
	// set exit status=(unsigned char)arg
	return (0);
}

void ft_exit(char **argv)
{
	int argc;

	argc = get_argc(argv);
	if (argc == 1)
	


}
