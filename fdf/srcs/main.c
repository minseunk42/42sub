/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 11:38:54 by minseunk          #+#    #+#             */
/*   Updated: 2023/06/25 18:53:49 by minseunk         ###   ########.fr       */
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

int	init(t_fdf *fdf, char *file)
{
	if (is_fdf_file(file))
		return (-1);
	if (map_init(fdf, file))
		return (-1);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, COLPIX, ROWPIX, "fdf");
	return (0);
}

void	fin(void *param)
{
	t_fdf *fdf;

	fdf = param;
	free_map(fdf);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	exit(0);
}

void	key_handler(int keycode, void *param)
{
	if (keycode == ESC)
		fin(param);
}

int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac < 2)
		return (EXIT_FAILURE);
	if (init(&fdf, av[1]))
		return (EXIT_FAILURE);
	mlx_hook(fdf.win_ptr, EVT_KEYE, 0, key_handler, &fdf);
	mlx_hook(fdf.win_ptr, EVT_EXIT, 0, fin, &fdf);
	weit(&fdf);
	roty(&fdf);
	rotx(&fdf);
	rotz(&fdf);
	bias(&fdf);
	draw_map(&fdf);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}
