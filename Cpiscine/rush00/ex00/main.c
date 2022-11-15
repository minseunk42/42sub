/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 11:14:57 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/02 17:50:24 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		rush(int c, int r);
void		error(void);
long long	ft_atoi(char *nptr);

int	main(int ac, char **av)
{
	if (ac != 3 || ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) <= 0)
	{
		error();
		return (0);
	}
	rush(ft_atoi(av[1]), ft_atoi(av[2]));
	return (0);
}

void	error(void)
{
	write(2, "error\n", 6);
}

long long	ft_atoi(char *nptr)
{
	int			i;
	int			n;
	long long	res;

	i = 0;
	n = 0;
	res = 0;
	while (nptr[n])
		n++;
	if (n > 11)
		return (-1);
	while (nptr[i])
	{
		if (!('0' <= nptr[i] && nptr[i] <= '9'))
			return (-2);
		else
		{
			res = 10 * res + nptr[i] - 48;
			if (res > 2147483647)
				return (-3);
			i++;
		}
	}
	return (res);
}
