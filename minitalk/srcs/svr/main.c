/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:32:28 by minseunk          #+#    #+#             */
/*   Updated: 2023/05/01 20:53:17 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

extern char	*g_str;

void	sig_hander(int sig)
{
	static char	idx;
	static char	temp;

	(void)sig;
	idx = 7;
	temp = 0;
	ft_printf("hi");
}

int	main(void)
{
	struct sigaction	act;

	act.sa_handler = sig_hander;
	act.sa_mask = 0;
	act.sa_flags = (SA_RESTART | SA_SIGINFO);
	ft_printf("%d", getpid());
	sigaction(SIGUSR1, &act, 0);
	while (1)
	{
		pause();
	}
}
