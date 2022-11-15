/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:51:15 by seok              #+#    #+#             */
/*   Updated: 2022/10/20 11:59:42 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	get_min(int a, int b, int c)
{
	if (a > b)
		return (b * (b <= c) + c * (c < b));
	else
		return (a * (a <= c) + c * (c < a));
}

int	**sol_map(int	**map, int row, int col)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	while (++i < row)
	{
		j = 0;
		while (++j < col)
		{
			t = get_min(map[i - 1][j - 1], map[i][j - 1], map[i - 1][j]);
			if (map[i][j] != 0)
				map[i][j] = t + 1;
		}
	}
	return (map);
}

int	get_max(int **map, int row, int col)
{
	int	i;
	int	j;
	int	max;

	max = 1;
	i = 0;
	while (++i < row)
	{
		j = 0;
		while (++j < col)
		{
			if (map[i][j] > max)
				max = map[i][j];
		}
	}
	return (max);
}

int	*get_maxindex(int **map, int row, int col, int max)
{
	int	i;
	int	j;
	int	*mi;
	int	flag;

	i = -1;
	flag = 0;
	mi = (int *)malloc(sizeof(int) * 3);
	while (++i < row)
	{
		j = -1;
		while (++j < col)
		{
			if (map[i][j] == max)
			{
				mi[Y] = i - max + 1;
				mi[X] = j - max + 1;
				flag = 1;
			}
			if (flag)
				break ;
		}
	}
	mi[MAX] = max;
	return (mi);
}

int	pos_check(int i, int j, int *mi)
{
	if (i < mi[Y])
		return (0);
	if (j < mi[X])
		return (0);
	if (i >= mi[Y] + mi[MAX])
		return (0);
	if (j >= mi[X] + mi[MAX])
		return (0);
	return (1);
}
