/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 11:38:54 by minseunk          #+#    #+#             */
/*   Updated: 2023/07/02 11:44:47 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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