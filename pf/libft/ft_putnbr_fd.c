/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:15:49 by minseunk          #+#    #+#             */
/*   Updated: 2022/11/19 23:59:32 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	nb;

	if (n < 0)
		write(fd, "-", 1);
	nb = (n * (n > 0)) - ((long long)n * (n < 0));
	if (nb / 10 > 0)
		ft_putnbr_fd(nb / 10, fd);
	nb = '0' + nb % 10;
	write(fd, &nb, 1);
}
