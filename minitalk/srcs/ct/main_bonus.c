/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:32:32 by minseunk          #+#    #+#             */
/*   Updated: 2023/05/20 15:52:26 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

int	g_flag;

void	sig_hander(int sig)
{
	if (sig == SIGUSR1)
	{
		g_flag = 0;
		write(1, "sucess\n", 7);
	}
	if (sig == SIGUSR2)
		g_flag++;
	if (g_flag == 1)
		write(1, "fail\n", 5);
}

int	check_pid(char *str, int *pid)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
	}
	*pid = ft_atoi(str);
	return (0);
}

void	send_sig(char c, int svpid)
{
	int	offset;

	offset = 8;
	if (g_flag)
		return ;
	while (--offset >= 0)
	{
		usleep(10);
		if (1 & (c >> offset))
			kill(svpid, SIGUSR1);
		else
			kill(svpid, SIGUSR2);
	}
}

int	main(int ac, char **av)
{
	int					svpid;
	int					i;
	struct sigaction	act;

	svpid = 0;
	if (ac != 3 || check_pid(av[1], &svpid))
	{
		write(2, "input arg error\n", 16);
		return (-1);
	}
	sigemptyset(&act.sa_mask);
	act.sa_handler = sig_hander;
	act.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	i = -1;
	while (av[2][++i])
		send_sig(av[2][i], svpid);
	send_sig(0, svpid);
	return (0);
}
