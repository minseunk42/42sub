/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:11:42 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/12 09:44:50 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "../ft_stock_str.h"

void	my_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

void	my_putnbr(int nb)
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
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str)
	{
		my_putstr(par->str);
		my_putnbr(par->size);
		my_putstr(par->copy);
		par++;
	}
}
