/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:24:40 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/03 15:24:43 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	long	nbl;
	char	na[10];
	int		i;

	nbl = nb;
	if (nbl < 0)
	{
		write(1, "-", 1);
		nbl = -nbl;
	}
	i = 0;
	while (nbl / 10 > 0)
	{
		na[i++] = '0' + (nbl % 10);
		nbl = nbl / 10;
	}
	na[i++] = '0' + (nbl % 10);
	while (i-- > 0)
		write(1, &(na[i]), 1);
}
