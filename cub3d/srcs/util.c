/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:16:43 by minseunk          #+#    #+#             */
/*   Updated: 2023/10/14 07:16:09 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	key_handler(int keycode, void *param)
{
	if (keycode == ESC)
		fin(param);
	if (keycode == KW)
		movef(param);
	if (keycode == KS)
		moveb(param);
	if (keycode == KA)
		turnl(param);
	if (keycode == KD)
		turnr(param);
	return (0);
}

void	my_mlx_pixel_put(t_mlx_data *md, int x, int y, int color)
{
	char	*dst;

	dst = md->addr + (x * md->line_length + y * (md->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init(t_mlx_data *md)
{
	md->mlx_ptr = mlx_init();
	md->win_ptr = mlx_new_window(md->mlx_ptr, COLPIX, ROWPIX, "md");
	md->img_ptr = mlx_new_image(md->mlx_ptr, COLPIX, ROWPIX);
	md->addr = mlx_get_data_addr(md->img_ptr, &(md->bits_per_pixel) \
	, &md->line_length, &md->endian);
	md->dval[PSX] = 19.5;
	md->dval[PSY] = 15.5;
	md->dval[DRX] = -1;
	md->dval[DRY] = 0;
	md->dval[PLX] = 0;
	md->dval[PLY] = 0.66;
}

int	fin(void *param)
{
	t_mlx_data	*md;

	md = param;
	mlx_destroy_window(md->mlx_ptr, md->win_ptr);
	exit(0);
	return (0);
}
