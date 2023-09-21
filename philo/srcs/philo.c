/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:38:06 by ubuntu            #+#    #+#             */
/*   Updated: 2023/09/21 20:40:07 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	est(t_philo *philo)
{
	if (philo->philon % 2 == 0 && usleep(10))
	{
		if (take_lfork(philo) || take_rfork(philo))
			return ;
	}
	else
	{
		if (take_rfork(philo) || take_lfork(philo))
			return ;
	}
	printf(EAT);
	if (spend_time(philo , philo->arg->tteat))
		return ;
	philo->eatcnt += 1;
	philo->ltteat = get_usec();
	if (is_fin(philo))
		return ;
	printf(SLP);
	if (spend_time(philo , philo->arg->ttslp - backfork(philo)))
		return ;
	if (is_fin(philo))
		return ;
	printf(THK);
}

void	*routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	while (1)
	{
		if (is_fin(philo))
			break ;
		est(philo);
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
		pss[i].eatcnt = 0;
		pthread_create(&ths[i], 0, routine, &pss[i]);
	}
	i = -1;
	while (++i < arg->nofpl)
		pthread_join(ths[i], 0);
	return (0);
}
