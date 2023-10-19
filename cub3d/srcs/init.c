/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:37:23 by ubuntu            #+#    #+#             */
/*   Updated: 2023/10/19 14:05:25 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static void	set_dir(t_mlx_data *md)
{
	if (md->data->pos->d == NORTH || md->data->pos->d == SOUTH)
	{
		md->dval[DRY] = 0;
		md->dval[PLX] = 0;
		md->dval[PLY] = 0.7;
		if (md->data->pos->d == NORTH)
			md->dval[DRX] = 1;
		else
			md->dval[DRX] = -1;
	}
	else
	{
		md->dval[DRY] = 0;
		md->dval[PLY] = 0;
		md->dval[PLX] = 0.7;
		if (md->data->pos->d == WEST)
			md->dval[DRY] = 1;
		else
			md->dval[DRY] = -1;
	}
}

static int	set_tex_dir(t_mlx_data *md, int dir)
{
	md->img_ptr = mlx_new_image(md->mlx_ptr, COLPIX, ROWPIX);
	if (!md->img_ptr)
		return (-1);
	md->texture[dir].addr = mlx_get_data_addr(md->img_ptr, \
	&md->texture[dir].bits_per_pixel \
	, &md->texture[dir].line_length, &md->texture[dir].endian);
	if (!md->texture[dir].addr)
	{
		mlx_destroy_image(md->mlx_ptr, md->img_ptr);
		return (-1);
	}
	mlx_destroy_image(md->mlx_ptr, md->img_ptr);
	return (0);
}

static int	set_tex(t_mlx_data *md)
{
	if (set_tex_dir(md, NORTH))
		return (-1);
	if (set_tex_dir(md, SOUTH))
		return (-1);
	if (set_tex_dir(md, EAST))
		return (-1);
	if (set_tex_dir(md, WEST))
		return (-1);
}

int	init(t_mlx_data *md)
{
	md->mlx_ptr = mlx_init();
	if (!md->mlx_ptr)
		return (free_mlx(md));
	md->win_ptr = mlx_new_window(md->mlx_ptr, COLPIX, ROWPIX, "cub3D");
	if (!md->win_ptr)
		return (free_mlx(md));
	if (set_tex(md))
		return (free_mlx(md));
	md->dval[PSX] = md->data->pos->x + 0.5;
	md->dval[PSY] = md->data->pos->y + 0.5;
	set_dir(md);
	return (0);
}
