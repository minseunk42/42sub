/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:51:24 by gylim             #+#    #+#             */
/*   Updated: 2023/07/26 14:52:24 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include "minishell.h"

#define WRONG_ARGC_MSG ("minishell: exit: too many arguments\n")
#define WRONG_ARG_MSG ("minishell: exit: numeric argument required\n")

static int	is_zero(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] != '0')
		return (0);
	while (str[i] == '0')
		i++;
	while (str[i] == ' ')
		i++;
	return (str[i] == '\0');
}

static int	is_valid_range(const char *str)
{
	int			i;
	long long	num;

	num = ft_atoll(str);
	i = 0;
	while (str[i] == ' ')
		i++;
	if (num < 0 && str[i] != '-')
		return (0);
	if (num == 0 && !is_zero(str))
		return (0);
	return (1);
}

static int	is_valid_argument(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (ms_check_set(str[i], DECIMAL) == 0)
			break ;
		i++;
	}
	if (str[i] != '\0' && str[i] != ' ')
		return (0);
	while (str[i] == ' ')
		i++;
	return (str[i] == '\0');
}

/*
 * status: exit status
 * flag: exit flag
 */
static int	ft_exit_return(t_ll status, int flag, const char *msg_or_null)
{
	extern t_gdata	g_data;

	if (msg_or_null != NULL)
		ft_printf(STDERR_FILENO, "%s", msg_or_null);
	if (isatty(STDIN_FILENO) == 0)
		exit(status);
	g_data.last_exit_status = status;
	if (flag == 1)
		exit(status);
	return (status);
}

int	ft_exit(char **argv)
{
	int				argc;
	t_ll			arg;
	extern t_gdata	g_data;

	argc = get_argc(argv);
	if (argc == 1)
		return (ft_exit_return(g_data.last_exit_status, TRUE, NULL));
	if (argc > 2)
		return (ft_exit_return(EXIT_FAILURE, FALSE, WRONG_ARGC_MSG));
	printf("exit\n");
	if (!is_valid_argument(argv[1]) || !is_valid_range(argv[1]))
		return (ft_exit_return(255, TRUE, WRONG_ARG_MSG));
	arg = ft_atoll(argv[1]);
	return (ft_exit_return(arg, TRUE, NULL));
}
