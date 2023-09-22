/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:38:06 by ubuntu            #+#    #+#             */
/*   Updated: 2023/09/22 10:03:39 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	if (!philo->philon || philo->philon == 1)
		usleep(100);
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
	print_action(EAT, philo);
	philo->ltteat = get_usec();
	if (spend_time(philo, philo->arg->tteat))
		return ;
	philo->eatcnt += 1;
	philo->ltteat = get_usec();
}

void	slp(t_philo *philo)
{	
	print_action(SLP, philo);
	if (spend_time(philo, philo->arg->ttslp - backfork(philo)))
		return ;
}

void	thk(t_philo *philo)
{
	print_action(THK, philo);
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
	while (i-- > 0)
		pthread_join(ths[i], 0);
	free(ths);
	free(pss);
	return (0);
}
