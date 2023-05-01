/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:32:28 by minseunk          #+#    #+#             */
/*   Updated: 2023/05/01 21:22:26 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

int	g_flag;

void	sig_hander(int sig, siginfo_t *info, void *context)
{
	static int	offset;
	static char	temp;

	(void)context;
	if (!g_flag)
		g_flag = info->si_pid;
	if (g_flag != info->si_pid)
	{
		kill(info->si_pid, SIGUSR2);
		return ;
	}
	if (sig == SIGUSR1)
		temp |= (1 << (7 - offset));
	offset++;
	if (offset == 8)
	{
		if (!temp)
		{
			kill(info->si_pid, SIGUSR1);
			g_flag = 0;
		}
		write(1, &temp, 1);
		offset = 0;
		temp = 0;
	}
}

int	main(void)
{
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	act.sa_flags = SA_SIGINFO | SA_RESTART;
	act.sa_sigaction = sig_hander;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	ft_printf("%d\n", getpid());
	while (1)
		pause();
}
