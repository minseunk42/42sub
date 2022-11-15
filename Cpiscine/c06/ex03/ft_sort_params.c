/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 08:41:34 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/06 17:49:52 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	my_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

void	my_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	main(int ac, char **av)
{
	char	*temp;
	int		i;

	if (ac < 1)
		return (0);
	while (ac-- > 1)
	{
		i = 1;
		while (i < ac)
		{
			if (my_strcmp(av[i], av[i + 1]) < 0)
			{
				temp = av[i];
				av[i] = av[i + 1];
				av[i + 1] = temp;
			}
			i++;
		}
		my_putstr(av[ac]);
		write(1, "\n", 1);
	}
	return (1);
}
