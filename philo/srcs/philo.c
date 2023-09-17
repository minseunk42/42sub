/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:38:06 by ubuntu            #+#    #+#             */
/*   Updated: 2023/09/17 22:05:09 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine(void *arg)
{
	t_arg	*ag;
	
	ag = (t_arg*)arg;
	if (ag->phid[0] == 1)
		printf("hi");
	return 0;
}

int	philo(t_arg *arg)
{
	int			i;
	pthread_t	threads;
	
	i = -1;
	while (++i < arg->nofpl)
	{
		arg->phid[i] = 1;
		pthread_create(&threads, 0, routine, arg);
	}
	i = 0;
	while (++i < arg->nofpl)
		pthread_join(threads, 0);
	return (0);
}