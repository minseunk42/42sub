/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 08:40:51 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/07 10:58:55 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	unsigned int	i;

	if (ac < 1)
		return (0);
	while (ac-- > 1)
	{
		i = 0;
		while (av[ac][i])
			write(1, &av[ac][i++], 1);
		write(1, "\n", 1);
	}
	return (1);
}
