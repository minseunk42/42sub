/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:37:23 by ubuntu            #+#    #+#             */
/*   Updated: 2023/10/18 18:58:34 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void static set_dir(t_mlx_data *md, t_data *data)
{
	if (data->pos->d == NORTH || data->pos->d == SOUTH)
	{
		md->dval[DRY] = 0;
		md->dval[PLX] = 0;
		md->dval[PLY] = 0.7;
		if (data->pos->d == NORTH)
			md->dval[DRX] = -1;
		else
			md->dval[DRX] = 1;
	}
	else
	{
		md->dval[DRY] = 0;
		md->dval[PLY] = 0;
		md->dval[PLX] = 0.7;
		if (data->pos->d == WEST)
			md->dval[DRY] = -1;
		else
			md->dval[DRY] = 1;
	}
}

void static set_tex(t_mlx_data *md, t_data *data)
{
	
}

int	init(t_mlx_data *md, t_data *data)
{
	md->mlx_ptr = mlx_init();
	if (!md->mlx_ptr)
		return (free_data(data));
	md->win_ptr = mlx_new_window(md->mlx_ptr, COLPIX, ROWPIX, "md");
	if (!md->win_ptr)
		return (free_mlx(md), free_data(data));
	md->img_ptr = mlx_new_image(md->mlx_ptr, COLPIX, ROWPIX);
	if (!md->img_ptr)
		return (free_mlx(md), free_data(data));
	md->addr = mlx_get_data_addr(md->img_ptr, &(md->bits_per_pixel) \
	, &md->line_length, &md->endian);
	if (!md->addr)
		return (free_mlx(md), free_data(data));
	set_tex(md, data);
	md->dval[PSX] = data->pos->x;
	md->dval[PSY] = data->pos->y;
	set_dir(md, data);
	return (0);
}