/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 11:38:54 by minseunk          #+#    #+#             */
/*   Updated: 2023/10/14 01:24:23 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	is_fdf_file(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (file[--i] && file[i] != 'f')
		return (-1);
	if (file[--i] && file[i] != 'd')
		return (-1);
	if (file[--i] && file[i] != 'f')
		return (-1);
	if (file[--i] && file[i] != '.')
		return (-1);
	return (0);
}

void	set_data(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, COLPIX, ROWPIX, "fdf");
	fdf->ang[X] = PI / 4;
	fdf->ang[Y] = PI / 4;
	fdf->ang[Z] = -PI / 6;
	if (fdf->col > fdf->row)
	{
		fdf->mulxy = COLPIX / fdf->col;
		fdf->pmx = (COLPIX - (fdf->col * fdf->mulxy)) / 3;
		fdf->pmy = (COLPIX - (fdf->col * fdf->mulxy)) / 3;
	}
	else
	{
		fdf->mulxy = ROWPIX / fdf->row;
		fdf->pmx = (COLPIX - (fdf->col * fdf->mulxy)) / 3;
		fdf->pmy = (COLPIX - (fdf->col * fdf->mulxy)) / 3;
	}
	if (fdf->zmax > fdf->row + fdf->col)
		fdf->mulz = fdf->zmax / 20;
	else
		fdf->mulz = fdf->mulxy / 2;
	if (fdf->mulxy < 2)
		fdf->mulxy = 4;
	if (!fdf->mulz)
		fdf->mulz = 4;
}

int	init(t_fdf *fdf, char *file)
{
	if (is_fdf_file(file))
		return (-1);
	if (map_init(fdf, file))
		return (-1);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, COLPIX, ROWPIX, "fdf");
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, COLPIX, ROWPIX);
	fdf->addr = mlx_get_data_addr(fdf->img_ptr, &(fdf->bits_per_pixel) \
	, &fdf->line_length, &fdf->endian);
	fdf->objx = 200;
	fdf->objy = 200;
	fdf->obja = 0;
	fdf->objdx = cos(fdf->obja) * 5;
	fdf->objdy = sin(fdf->obja) * 5;
	set_data(fdf);
	return (0);
}

int	fin(void *param)
{
	t_fdf	*fdf;

	fdf = param;
	free_map(fdf);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	exit(0);
	return (0);
}

void	draw_obj(t_fdf *fdf)
{
	int x;
	int	xtemp;
	int ytemp;
	int y;
	int r;

	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, COLPIX, ROWPIX);
	fdf->addr = mlx_get_data_addr(fdf->img_ptr, &(fdf->bits_per_pixel) \
	, &fdf->line_length, &fdf->endian);
	r = 10;
	x = fdf->objx - r;
	while (++x < fdf->objx + r)
	{
		y = fdf->objy - r;
		while (++y < fdf->objy + r)
		{
			if ((x - fdf->objx) * (x - fdf->objx) + (y - fdf->objy) * (y - fdf->objy) < r * r)
			{
				if (x < fdf->objx)
				{
					xtemp = cos(fdf->obja) * (x - fdf->objx) - sin(fdf->obja) * (y - fdf->objy) + fdf->objx;
					ytemp = sin(fdf->obja) * (x - fdf->objx) + cos(fdf->obja) * (y - fdf->objy) + fdf->objy;
					my_mlx_pixel_put(fdf, xtemp, ytemp, 0xff00ff);
				}
			}
		}
	}
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
}
/*
static void mul(void *param)
{
	t_fdf	*fdf;
	int	i;
	int	j;
	int	z;
	int x;
	int	y;

	fdf = param;
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	i = -1;
	while (++i < fdf->row)
	{
		j = -1;
		while (++j < fdf->col)
		{
			x = fdf->map[i][j][X];
			z = fdf->map[i][j][Z];
			fdf->map[i][j][X] = cos(fdf->ang[Y] / 12) * x - sin(fdf->ang[Y] / 12) * z;
			fdf->map[i][j][Z] = sin(fdf->ang[Y] / 12) * x + cos(fdf->ang[Y] / 12) * z;
		}
	}
	while (++i < fdf->row)
	{
		j = -1;
		while (++j < fdf->col)
		{
			y = fdf->map[i][j][Y];
			z = fdf->map[i][j][Z];
			fdf->map[i][j][Y] = cos(fdf->ang[X] / 12) * y + sin(fdf->ang[X] / 12) * z;
			fdf->map[i][j][Z] = cos(fdf->ang[X] / 12) * z - sin(fdf->ang[X] / 12) * y;
		}
	}
	draw_map(fdf);
}
*/

void move_up(void *param)
{
	t_fdf	*fdf;

	fdf = param;
	fdf->objx -= fdf->objdx;
	fdf->objy -= fdf->objdy;
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	draw_obj(fdf);
}

void move_down(void *param)
{
	t_fdf	*fdf;

	fdf = param;
	fdf->objx += fdf->objdx;
	fdf->objy += fdf->objdy;
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	draw_obj(fdf);
}

void turn_right(void *param)
{
	t_fdf	*fdf;

	fdf = param;
	fdf->obja -= 0.1;
	if (fdf->obja < 0)
		fdf->obja += 2 * PI;
	fdf->objdx = cos(fdf->obja) * 5;
	fdf->objdy = sin(fdf->obja) * 5;
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	draw_obj(fdf);
}

void turn_left(void *param)
{
	t_fdf	*fdf;

	fdf = param;
	fdf->obja += 0.1;
	if (fdf->obja > 2 * PI)
		fdf->obja -= 2 * PI;
	fdf->objdx = cos(fdf->obja) * 5;
	fdf->objdy = sin(fdf->obja) * 5;
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	draw_obj(fdf);
}

int	key_handler(int keycode, void *param)
{
	if (keycode == ESC)
		fin(param);
	if (keycode == KW)
		move_up(param);
	if (keycode == KS)
		move_down(param);
	if (keycode == KA)
		turn_left(param);
	if (keycode == KD)
		turn_right(param);
	return (0);
}

int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2)
		return (EXIT_FAILURE);
	if (init(&fdf, av[1]))
		return (EXIT_FAILURE);
	mlx_hook(fdf.win_ptr, EVT_KEYE, 0, key_handler, &fdf);
	mlx_hook(fdf.win_ptr, EVT_EXIT, 0, fin, &fdf);
	weit(&fdf);
//	rota(&fdf);
	bias(&fdf);
	draw_obj(&fdf);
	draw_map(&fdf);
	mlx_loop(fdf.mlx_ptr);
	free_map(&fdf);
	return (EXIT_SUCCESS);
}
