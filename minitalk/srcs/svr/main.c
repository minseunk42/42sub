/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:32:28 by minseunk          #+#    #+#             */
/*   Updated: 2023/04/26 20:51:27 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"



void sig_handler1(int signo)
{
  ft_printf("I Received SIG(%d)\n", signo);
}

int	main(void)
{
	void	(*sig_handler)(int signo);

	sig_handler = sig_handler1;
	ft_printf("%d", getpid());
	while (1)
	{
		signal(SIGUSR1, sig_handler);
		usleep(1000000);
	}
}


