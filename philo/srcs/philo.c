/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:38:06 by ubuntu            #+#    #+#             */
/*   Updated: 2023/09/22 08:41:19 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	if (philo->philon % 2 == 0)
	{
		if (take_lfork(philo) || take_rfork(philo))
			return ;
	}
	else
	{
		if (take_rfork(philo) || take_lfork(philo))
			return ;
	}
	pthread_mutex_lock(&(philo->arg->mutex));
	if (!philo->arg->isfin)
	{
		printf(EAT, (get_usec() - philo->arg->itime) / 1000, \
		philo->philon + 1);
	}
	pthread_mutex_unlock(&(philo->arg->mutex));
	if (spend_time(philo, philo->arg->tteat))
		return ;
	philo->eatcnt += 1;
	philo->ltteat = get_usec();
}

void	slp(t_philo *philo)
{	
	pthread_mutex_lock(&(philo->arg->mutex));
	if (!philo->arg->isfin)
	{
		printf(SLP, (get_usec() - philo->arg->itime) / 1000, \
		philo->philon + 1);
	}
	pthread_mutex_unlock(&(philo->arg->mutex));
	if (spend_time(philo, philo->arg->ttslp - backfork(philo)))
		return ;
}

void	thk(t_philo *philo)
{
	pthread_mutex_lock(&(philo->arg->mutex));
	if (!philo->arg->isfin)
	{
		printf(THK, (get_usec() - philo->arg->itime) / 1000, \
		philo->philon + 1);
	}
	pthread_mutex_unlock(&(philo->arg->mutex));
}

void	*routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	while (1)
	{
		if (is_fin(philo))
			break ;
		eat(philo);
		if (is_fin(philo))
			break ;
		slp(philo);
		if (is_fin(philo))
			break ;
		thk(philo);
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
