/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:32:05 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/10 11:19:02 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	long long	l;
	long long	i;
	int			*tab;

	if (min >= max)
		return (0);
	l = (long long)max - (long long)min;
	tab = (int *)malloc(sizeof(int) * l);
	if (!tab)
		return (0);
	i = 0;
	while (i < l)
		tab[i++] = min++;
	return (tab);
}
