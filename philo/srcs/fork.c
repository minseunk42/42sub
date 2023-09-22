/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:50:16 by ubuntu            #+#    #+#             */
/*   Updated: 2023/09/22 09:25:44 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_fin(t_philo *philo)
{
	pthread_mutex_lock(&(philo->arg->mutex));
	if (philo->arg->isfin)
	{
		pthread_mutex_unlock(&(philo->arg->mutex));
		return (-1);
	}
	pthread_mutex_unlock(&(philo->arg->mutex));
	if ((int)((get_usec() - philo->ltteat) / 1000) > philo->arg->ttdie)
	{
		print_action(DED, philo);
		pthread_mutex_lock(&(philo->arg->mutex));
		philo->arg->isfin = 1;
		pthread_mutex_unlock(&(philo->arg->mutex));
		return (-1);
	}
	if (philo->eatcnt == philo->arg->mxeat)
	{
		pthread_mutex_lock(&(philo->arg->mutex));
		philo->arg->isfin = 1;
		pthread_mutex_unlock(&(philo->arg->mutex));
		return (-1);
	}
	return (0);
}

int	take_rfork(t_philo *philo)
{
	int	fnum;

	fnum = (philo->philon + 1) % philo->arg->nofpl;
	while (1)
	{
		if (is_fin(philo))
			return (-1);
		pthread_mutex_lock(&(philo->arg->fmtx[fnum]));
		if (!(philo->arg->fork[fnum]))
		{
			print_action(TKF, philo);
			philo->arg->fork[fnum] = 1;
			break ;
		}
		pthread_mutex_unlock(&(philo->arg->fmtx[fnum]));
		usleep(5);
	}
	pthread_mutex_unlock(&(philo->arg->fmtx[fnum]));
	return (0);
}

int	take_lfork(t_philo *philo)
{
	while (1)
	{
		if (is_fin(philo))
			return (-1);
		pthread_mutex_lock(&(philo->arg->fmtx[philo->philon]));
		if (!(philo->arg->fork[philo->philon]))
		{
			print_action(TKF, philo);
			philo->arg->fork[philo->philon] = 1;
			break ;
		}
		pthread_mutex_unlock(&(philo->arg->fmtx[philo->philon]));
		usleep(5);
	}
	pthread_mutex_unlock(&(philo->arg->fmtx[philo->philon]));
	return (0);
}

int	backfork(t_philo *philo)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	pthread_mutex_lock(&(philo->arg->mutex));
	philo->arg->fork[(philo->philon + 1) % philo->arg->nofpl] = 0;
	philo->arg->fork[philo->philon] = 0;
	pthread_mutex_unlock(&(philo->arg->mutex));
	return ((get_usec() - (now.tv_sec * 1000000 + now.tv_usec)) / 1000);
}
