/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:56:20 by minseunk          #+#    #+#             */
/*   Updated: 2022/11/16 20:29:48 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long long	nb;
	int			size;
	char		*out;

	nb = (n * (n > 0)) - ((long long)n * (n < 0));
	size = (n <= 0);
	while (nb)
	{
		size++;
		nb /= 10;
	}
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
