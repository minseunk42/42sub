/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:16:43 by minseunk          #+#    #+#             */
/*   Updated: 2023/10/18 17:41:22 by ubuntu           ###   ########.fr       */
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

int	fin(void *param)
{
	t_mlx_data	*md;

	md = param;
	mlx_destroy_image(md->mlx_ptr, md->img_ptr);
	mlx_destroy_window(md->mlx_ptr, md->win_ptr);
	exit(0);
	return (0);
}
