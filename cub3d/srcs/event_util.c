/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:16:43 by minseunk          #+#    #+#             */
/*   Updated: 2023/10/21 02:07:20 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	key_handler(int keycode, void *param)
{
	if (keycode == ESC)
		fin(param);
	else if (keycode == KW)
		movef(param);
	else if (keycode == KS)
		moveb(param);
	else if (keycode == KA)
		movel(param);
	else if (keycode == KD)
		mover(param);
	else if (keycode == KL)
		turnl(param);
	else if (keycode == KR)
		turnr(param);
	return (0);
}

int	free_mlx(t_mlx_data *md)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (md->texture[i].has_img)
			mlx_destroy_image(md->mlx_ptr, md->texture[i].img_ptr);
	}
	mlx_destroy_window(md->mlx_ptr, md->win_ptr);
	free(md->mlx_ptr);
	free_data(md->data);
	return (-1);
}

int	fin(void *param)
{
	t_mlx_data	*md;

	md = param;
	free_mlx(md);
	exit(0);
	return (0);
}
