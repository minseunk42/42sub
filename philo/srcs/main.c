/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:36:33 by minseunk          #+#    #+#             */
/*   Updated: 2023/09/19 19:24:48 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init(t_arg *arg, int ac, char **av)
{
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) <= 0 || \
		ft_atoi(av[3]) <= 0 || ft_atoi(av[4]) <= 0)
		return (-1);
	if (ac == 6 && ft_atoi(av[5]) <= 0)
		return (-1);
	arg->isfin = 0;
	arg->itime = get_usec();
	arg->nofpl = ft_atoi(av[1]);
	arg->tteat = ft_atoi(av[2]);
	arg->ttdie = ft_atoi(av[3]);
	arg->ttslp = ft_atoi(av[4]);
	arg->mxeat = -1;
	if (ac == 6)
		arg->mxeat = ft_atoi(av[5]);
	arg->fork = (int *)malloc(sizeof(int) * arg->nofpl);
	if (!arg->fork)
		return (-1);
	memset(arg->fork, 0, sizeof(int) * arg->nofpl);
	pthread_mutex_init(&(arg->mutex), 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_arg	arg;

	if (ac < 5 || ac > 6)
		return (-1);
	if (init(&arg, ac, av))
		return (free_arg(&arg));
	if (philo(&arg))
		return (free_arg(&arg));
	free_arg(&arg);
	return (0);
}
