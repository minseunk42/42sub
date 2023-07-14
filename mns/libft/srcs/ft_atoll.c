/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:14:26 by gylim             #+#    #+#             */
/*   Updated: 2023/06/29 19:23:59 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_ll	_get_num(int sign, const char *str)
{
	t_ll	prev;
	t_ll	res;

	res = 0;
	while (*str == '0')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		prev = res;
		res = res * 10 + (*str - '0');
		if (prev != res / 10)
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		str++;
	}
	return ((sign * res));
}

t_ll	ft_atoll(const char *str)
{
	int	sign;

	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	return (_get_num(sign, str));
}
