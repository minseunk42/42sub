/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:18:41 by minseunk          #+#    #+#             */
/*   Updated: 2023/09/17 21:57:19 by ubuntu           ###   ########.fr       */
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
	free(arg->fork);
	pthread_mutex_destroy(&(arg->mutex));
	return (-1);
}

int	get_usec(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_usec);
}
