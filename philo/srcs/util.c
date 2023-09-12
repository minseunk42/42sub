/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:18:41 by minseunk          #+#    #+#             */
/*   Updated: 2023/09/12 20:53:30 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	atoi(const char *str)
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
	while (ft_isdigit(str[i]))
		val = 10 * val + (str[i++] - '0');
	return (sign * val);
}

int	get_time(t_arg arg)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_usec - arg.it.tv_usec) / 1000);
}
