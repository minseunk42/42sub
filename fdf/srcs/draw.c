/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 03:59:37 by minseunk          #+#    #+#             */
/*   Updated: 2023/10/14 01:36:05 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_nega(t_fdf *fdf, int x[2], int y[2])
{
	int	p;

	p = 0;
	while (x[ST] != x[ED] && y[ST] != y[ED])
	{
		my_mlx_pixel_put(fdf, x[ST], y[ST], WHITE);
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
	while (x[ST] != x[ED] && y[ST] != y[ED])
	{
		my_mlx_pixel_put(fdf, x[ST], y[ST], WHITE);
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

void	draw_otho(t_fdf *fdf, int x[2], int y[2])
{
	if (x[ST] == x[ED])
	{
		while (y[ST] != y[ED])
		{
			my_mlx_pixel_put(fdf, x[ST], y[ST], WHITE);
			if (y[ST] < y[ED])
				y[ST]++;
			else
				y[ST]--;
		}
	}
	else
	{
		while (x[ST] != x[ED])
		{
			my_mlx_pixel_put(fdf, x[ST], y[ST], WHITE);
			x[ST]++;
		}
	}
}

static void	draw_line(t_fdf *fdf, int *dot1, int *dot2)
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
	if (x[ST] == x[ED] || y[ST] == y[ED])
		draw_otho(fdf, x, y);
	else if (y[ED] > y[ST])
		draw_posi(fdf, x, y);
	else
		draw_nega(fdf, x, y);
}

void	draw_map(t_fdf *fdf)
{
	int	i;
	int	j;

	//fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, COLPIX, ROWPIX);
	//fdf->addr = mlx_get_data_addr(fdf->img_ptr, &(fdf->bits_per_pixel) \
	//, &fdf->line_length, &fdf->endian);
	i = -1;
	while (++i < fdf->row - 1)
	{
		j = -1;
		while (++j < fdf->col - 1)
		{
			draw_line(fdf, fdf->map[i][j], fdf->map[i + 1][j]);
			draw_line(fdf, fdf->map[i][j], fdf->map[i][j + 1]);
		}
		draw_line(fdf, fdf->map[i][j], fdf->map[i + 1][j]);
	}
	j = -1;
	while (++j < fdf->col - 1)
		draw_line(fdf, fdf->map[i][j], fdf->map[i][j + 1]);
}
