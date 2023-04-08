/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_libft.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:44:26 by ubuntu            #+#    #+#             */
/*   Updated: 2023/04/04 20:21:38 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

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

char *ft_itoa(int n)
{
	long long	nb;
	int			size;
	char		*out;

	nb = (n * (n > 0)) - ((long long)n * (n < 0));
	size = (n <= 0);
	while (nb && ++size)
		nb /= 10;
	out = ft_calloc(size + 1, sizeof(char));
	if (!out)
		return (0);
	out[0] = '-';
	nb = (n * (n > 0)) - ((long long)n * (n < 0));
	while ((size-- - (n < 0)) > 0)
	{
		out[size] = '0' + nb % 10;
		nb /= 10;
	}
	return (out);
}
