/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:36:33 by minseunk          #+#    #+#             */
/*   Updated: 2023/09/22 15:41:29 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	m_init(t_arg *arg)
{
	int	i;

	arg->fmtx = 0;
	arg->fmtx = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
	arg->nofpl);
	if (!arg->fmtx)
		return (-1);
	memset(arg->fmtx, 0, sizeof(pthread_mutex_t) * arg->nofpl);
	i = -1;
	pthread_mutex_init(&(arg->mutex), 0);
	while (++i < arg->nofpl)
		pthread_mutex_init(&(arg->fmtx[i]), 0);
	return (0);
}

int	init(t_arg *arg, int ac, char **av)
{
	arg->fork = 0;
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) <= 0 || \
		ft_atoi(av[3]) <= 0 || ft_atoi(av[4]) <= 0)
		return (-1);
	if (ac == 6 && ft_atoi(av[5]) <= 0)
		return (-1);
	arg->isfin = 0;
	arg->itime = get_usec();
	arg->nofpl = ft_atoi(av[1]);
	arg->ttdie = ft_atoi(av[2]);
	arg->tteat = ft_atoi(av[3]);
	arg->ttslp = ft_atoi(av[4]);
	arg->mxeat = -1;
	if (ac == 6)
		arg->mxeat = ft_atoi(av[5]);
	arg->fork = (int *)malloc(sizeof(int) * arg->nofpl);
	if (!arg->fork)
		return (-1);
	memset(arg->fork, 0, sizeof(int) * arg->nofpl);
	if (m_init(arg))
		return (-1);
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
