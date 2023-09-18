/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:38:06 by ubuntu            #+#    #+#             */
/*   Updated: 2023/09/18 10:00:21 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	printf("hi%d",philo->philon);
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
		pss[i].arg = *arg;
		pss[i].ltteat = arg->itime;
		pthread_create(&ths[i], 0, routine, &pss[i]);
	}
	i = -1;
	while (++i < arg->nofpl)
		pthread_join(ths[i], 0);
	return (0);
}
