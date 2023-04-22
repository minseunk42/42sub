/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:20:08 by ubuntu            #+#    #+#             */
/*   Updated: 2023/04/23 01:51:17 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*utoa(unsigned int nb)
{
	int				size;
	char			*out;
	unsigned int	n;

	n = nb;
	size = (nb == 0);
	while (n && ++size)
		n /= 10;
	out = (char *)malloc(size + 1);
	if (!out)
		return (0);
	out[size] = 0;
	while (size-- > 0)
	{
		out[size] = '0' + nb % 10;
		nb /= 10;
	}
	return (out);
}

char	*utoh(unsigned int nb)
{
	int				size;
	char			*out;
	char			*hex;
	unsigned int	n;

	hex = "0123456789abcdef";
	n = nb;
	size = (nb == 0);
	while (n && ++size)
		n /= 16;
	out = (char *)malloc(size + 1);
	if (!out)
		return (0);
	out[size] = 0;
	while (size-- > 0)
	{
		out[size] = hex[(int)(nb % 16)];
		nb /= 16;
	}
	return (out);
}

char	*ulltoh(unsigned long long nb)
{
	int					size;
	char				*out;
	char				*hex;
	unsigned long long	n;

	hex = "0123456789abcdef";
	n = nb;
	size = (nb == 0);
	while (n && ++size)
		n /= 16;
	out = (char *)malloc(size + 1);
	if (!out)
		return (0);
	out[size] = 0;
	while (size-- > 0)
	{
		out[size] = hex[(int)(nb % 16)];
		nb /= 16;
	}
	return (out);
}
