/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 11:38:54 by minseunk          #+#    #+#             */
/*   Updated: 2023/10/11 09:40:18 by minseunk         ###   ########.fr       */
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
		fdf->mulxy = COLPIX / fdf->col / 3;
		fdf->pmx = (COLPIX - (fdf->col * fdf->mulxy)) / 3;
		fdf->pmy = (COLPIX - (fdf->col * fdf->mulxy)) / 3;
	}
	else
	{
		fdf->mulxy = ROWPIX / fdf->row / 3;
		fdf->pmx = (COLPIX - (fdf->col * fdf->mulxy)) / 3;
		fdf->pmy = (COLPIX - (fdf->col * fdf->mulxy)) / 3;
	}
	if (fdf->zmax > fdf->row + fdf->col)
		fdf->mulz = fdf->zmax / 20;
	else
		fdf->mulz = fdf->mulxy / 2;
	if (fdf->mulxy < 2)
		fdf->mulxy = 2;
	if (!fdf->mulz)
		fdf->mulz = 1;
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

int	key_handler(int keycode, void *param)
{
	if (keycode == ESC)
		fin(param);
	if (keycode == 12)
		mul(param);
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
	rota(&fdf);
	bias(&fdf);
	draw_map(&fdf);
	mlx_loop(fdf.mlx_ptr);
	free_map(&fdf);
	return (EXIT_SUCCESS);
}
