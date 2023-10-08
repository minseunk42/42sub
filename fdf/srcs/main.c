/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 11:38:54 by minseunk          #+#    #+#             */
/*   Updated: 2023/10/08 19:44:28 by minseunk         ###   ########.fr       */
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

int	fin(void *param)
{
	t_fdf	*fdf;

	fdf = param;
	free_map(fdf);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	exit(0);
	return (0);
}

int	key_handler(int keycode, void *param)
{
	if (keycode == ESC)
		fin(param);
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
