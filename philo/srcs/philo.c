/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:38:06 by ubuntu            #+#    #+#             */
/*   Updated: 2023/09/20 13:27:22 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	if (philo->philon % 2 == 0)
	{
		if (take_lfork(philo))
			return ;
		if (take_rfork(philo))
			return ;
	}
	else
	{
		if (take_rfork(philo))
			return ;
		if (take_lfork(philo))
			return ;
	}
	if (philo->arg->isfin)
			return ;
	philo->ltteat = get_usec();
	printf("%lu %d is eating\n" , (get_usec() - philo->arg->itime) / 1000,\
			 philo->philon);
	usleep(500000);
	backfork(philo);
}

void	sleep_think(t_philo *philo)
{
	if (philo->arg->isfin)
			return ;
	printf("%lu %d is sleeping\n" , (get_usec() - philo->arg->itime) / 1000,\
			 philo->philon);
	usleep(100000);
	if (philo->arg->isfin)
			return ;
	printf("%lu %d is thinking\n" , (get_usec() - philo->arg->itime) / 1000,\
			 philo->philon);
}

void	*routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	while (1)
	{
		if (philo->arg->isfin)
			break ;
		eat(philo);
		sleep_think(philo);		
	}
	return (0);
}

int	philo(t_arg *arg)
{
	int			i;
	t_philo		*pss;
	pthread_t	*ths;

	ths = (pthread_t *)malloc(sizeof(pthread_t) * arg->nofpl);
	if (!ths)
		return (-1);
	pss = (t_philo *)malloc(sizeof(t_philo) * arg->nofpl);
	if (!pss)
		return (-1);
	i = -1;
	while (++i < arg->nofpl)
	{
		pss[i].thread = ths[i];
		pss[i].philon = i;
		pss[i].arg = arg;
		pss[i].ltteat = arg->itime;
		pthread_create(&ths[i], 0, routine, &pss[i]);
	}
	i = -1;
	while (++i < arg->nofpl)
		pthread_join(ths[i], 0);
	return (0);
}
