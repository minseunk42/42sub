/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:55:08 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/10 11:18:40 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long long	l;
	long long	i;

	if (min >= max)
		return (0);
	l = (long long)max - (long long)min;
	*range = (int *)malloc(sizeof(int) * l);
	if (!range)
		return (0);
	i = 0;
	while (i < l)
		range[0][i++] = min++;
	return (l);
}
