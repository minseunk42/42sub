/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 03:59:37 by minseunk          #+#    #+#             */
/*   Updated: 2023/06/25 06:55:06 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_nega(t_fdf *fdf, int x[2], int y[2])
{
	int	p;

	p = 0;
	if (x[ST] == x[ED] || x[ST] == x[ED] + 1)
		x[ED] += 2;
	if (y[ST] == y[ED] || y[ST] == y[ED] + 1)
		y[ED] += 2;
	while (x[ST] != x[ED] && y[ST] != y[ED])
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, y[ST], x[ST], 0xffffff);
		if ((y[ED] - y[ST]) / (x[ED] - x[ST]))
		{
			if (p > 0 && ++x[ST] && --y[ST])
				p = p + (2 * (x[ED] - x[ST])) - (2 * (y[ST] - y[ED]));
			else if (--y[ST])
				p = p + (2 * (x[ED] - x[ST]));
		}
		else
		{
			if (p > 0 && ++x[ST] && --y[ST])
				p = p + 2 * (y[ED] - y[ST]) - 2 * (x[ED] - x[ST]);
			else if (++x[ST])
				p = p + 2 * (y[ST] - y[ED]);
		}
	}
}

void	draw_posi(t_fdf *fdf, int x[2], int y[2])
{
	int	p;

	p = 0;
	if (x[ST] == x[ED] || x[ST] == x[ED] + 1)
		x[ED] += 2;
	if (y[ST] == y[ED] || y[ST] == y[ED] + 1)
		y[ED] += 2;
	while (x[ST] != x[ED] && y[ST] != y[ED])
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, y[ST], x[ST], 0xffffff);
		if ((y[ED] - y[ST]) / (x[ED] - x[ST]))
		{
			if (p > 0 && ++x[ST] && ++y[ST])
				p = p + (2 * (x[ED] - x[ST])) - (2 * (y[ED] - y[ST]));
			else if (++y[ST])
				p = p + (2 * (x[ED] - x[ST]));
		}
		else
		{
			if (p > 0 && ++x[ST] && ++y[ST])
				p = p + 2 * (y[ST] - y[ED]) - 2 * (x[ED] - x[ST]);
			else if (++x[ST])
				p = p + 2 * (y[ED] - y[ST]);
		}
	}
}

static int	draw_line(t_fdf *fdf, int *dot1, int *dot2)
{
	int	x[2];
	int	y[2];

	if (dot1[X] < dot2[X])
	{
		x[ST] = dot1[X];
		y[ST] = dot1[Y];
		x[ED] = dot2[X];
		y[ED] = dot2[Y];
	}
	else
	{
		x[ST] = dot2[X];
		y[ST] = dot2[Y];
		x[ED] = dot1[X];
		y[ED] = dot1[Y];
	}
	if (y[ED] > y[ST])
		draw_posi(fdf, x, y);
	else
		draw_nega(fdf, x, y);
	return (0);
}

int	draw_map(t_fdf *fdf)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	while (++i < fdf->row - 1)
	{
		j = -1;
		while (++j < fdf->col - 1)
		{
			flag = draw_line(fdf, fdf->map[i][j], fdf->map[i + 1][j]);
			flag = draw_line(fdf, fdf->map[i][j], fdf->map[i][j + 1]);
		}
		flag = draw_line(fdf, fdf->map[i][j], fdf->map[i + 1][j]);
		if (flag)
			return (-1);
	}
	j = -1;
	i--;
	while (++j < fdf->col - 1)
		flag = draw_line(fdf, fdf->map[i][j], fdf->map[i + 1][j]);
	if (flag)
		return (-1);
	return (0);
}
