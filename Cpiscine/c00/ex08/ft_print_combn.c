/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:23:14 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/01 09:54:22 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_nbr(int nb, int d)
{
	char	na[9];
	int		i;

	i = 0;
	while (i < d)
	{
		na[i++] = '0' + (nb % 10);
		nb = nb / 10;
	}
	while (--i >= 0)
		write(1, &(na[i]), 1);
}

int	is_val(int nb, int d)
{
	while (d-- > 1)
	{
		if (nb % 10 <= (nb / 10) % 10)
			return (0);
		nb = nb / 10;
	}
	return (1);
}

int	get_max(int n)
{
	int	o;

	o = 0;
	while (n-- > 0)
		o = 10 * o + (9 - n);
	return (o);
}

void	ft_print_combn(int n)
{
	int		num;

	if (n < 1 || n > 9)
		return ;
	num = -1;
	while (++num < get_max(n))
	{
		if (is_val(num, n))
		{
			put_nbr(num, n);
			write(1, ", ", 2);
		}
	}
	put_nbr(get_max(n), n);
}
