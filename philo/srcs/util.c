/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:18:41 by minseunk          #+#    #+#             */
/*   Updated: 2023/09/18 08:40:07 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	val;
	int	sign;
	int	i;

	val = 0;
	i = 0;
	sign = 1;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || ((str[i] == '-') && ++i && sign-- && sign--))
		i++;
	while ('0' <= str[i] && str[i] <= '9')
		val = 10 * val + (str[i++] - '0');
	return (sign * val);
}

int	free_arg(t_arg *arg)
{
	if (arg->fork)
		free(arg->fork);
	pthread_mutex_destroy(&(arg->mutex));
	return (-1);
}

unsigned long	get_usec(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_usec);
}
