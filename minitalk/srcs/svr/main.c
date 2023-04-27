/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:32:28 by minseunk          #+#    #+#             */
/*   Updated: 2023/04/27 20:57:20 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

extern char	*g_str;

void	sig_handler0(int sig)
{
	ft_printf("sig1%d",sig);
}

void	sig_handler1(int sig)
{
	ft_printf("sig2%d",sig);
}

int	main(void)
{
	void	(*sig_handler[2])(int);

	sig_handler[0] = sig_handler0;
	sig_handler[1] = sig_handler1;
	ft_printf("%d", getpid());
	while (1)
	{
		signal(SIGUSR1, sig_handler[0]);
		signal(SIGUSR2, sig_handler[1]);
		usleep(1000000);
	}
}
