/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:21:52 by minseunk          #+#    #+#             */
/*   Updated: 2022/09/28 17:22:03 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int		num1;
	int		num2;
	char	c;

	num1 = -1;
	while (num1++ < 97)
	{
		num2 = num1;
		while (num2++ < 99)
		{
			c = '0' + num1 / 10;
			write(1, &c, 1);
			c = '0' + num1 % 10;
			write(1, &c, 1);
			write(1, " ", 1);
			c = '0' + num2 / 10;
			write(1, &c, 1);
			c = '0' + num2 % 10;
			write(1, &c, 1);
			write(1, ", ", 2);
		}
	}
	write(1, "98 99", 5);
}
