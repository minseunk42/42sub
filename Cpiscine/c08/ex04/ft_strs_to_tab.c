/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 08:50:37 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/12 09:44:36 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../ft_stock_str.h"

int	my_strlen(char *str)
{
	int	l;

	l = 0;
	while (*str++)
		l++;
	return (l);
}

char	*my_strdup(char *src)
{
	int		l;
	char	*out;

	l = 0;
	while (src[l])
		l++;
	out = (char *)malloc(sizeof(char) * l + 1);
	if (!out)
		return (0);
	while (*src)
		*out++ = *src++;
	*out = 0;
	out = out - l;
	return (out);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*t_arr;
	int			i;

	i = 0;
	t_arr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	while (ac > 0)
	{
		t_arr[i].size = my_strlen(av[i]);
		t_arr[i].str = av[i];
		t_arr[i].copy = my_strdup(av[i]);
		i++;
		ac--;
	}
	t_arr[i].str = 0;
	return (t_arr);
}
