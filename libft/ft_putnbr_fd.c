/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:15:49 by minseunk          #+#    #+#             */
/*   Updated: 2022/11/16 20:43:58 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		c;
	long long	nb;

	if (n < 0)
		write(fd, "-", 1);
	nb = (n * (n > 0)) - ((long long)n * (n < 0));
	if (nb / 10 > 0)
		ft_putnbr_fd(nb / 10, fd);
	c = '0' + nb % 10;
	write(fd, &c, 1);
}
