/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:37:23 by ubuntu            #+#    #+#             */
/*   Updated: 2023/10/21 00:18:51 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static void	set_dir(t_mlx_data *md)
{
	if (md->data->pos->d == NORTH || md->data->pos->d == SOUTH)
	{
		md->dval[DRY] = 0;
		md->dval[PLX] = 0;
		md->dval[PLY] = -0.7;
		if (md->data->pos->d == NORTH)
			md->dval[DRX] = -1;
		else
			md->dval[DRX] = 1;
	}
	else
	{
		md->dval[DRY] = 0;
		md->dval[PLY] = 0;
		md->dval[PLX] = -0.7;
		if (md->data->pos->d == WEST)
			md->dval[DRY] = -1;
		else
			md->dval[DRY] = 1;
	}
}

static int	set_tex_dir(t_mlx_data *md, int dir, char *path)
{
	md->img_ptr = mlx_new_image(md->mlx_ptr, COLPIX, ROWPIX);
	if (!md->img_ptr)
		return (-1);
	md->img_ptr = mlx_xpm_file_to_image(md->mlx_ptr, \
	path, &md->texture[dir].width, &md->texture[dir].height);
	md->texture[dir].addr = mlx_get_data_addr(md->img_ptr, \
	&md->texture[dir].bits_per_pixel \
	, &md->texture[dir].line_length, &md->texture[dir].endian);
	return (0);
}

static int	set_tex(t_mlx_data *md)
{
	if (set_tex_dir(md, NORTH, md->data->north))
		return (-1);
	if (set_tex_dir(md, SOUTH, md->data->south))
		return (-1);
	if (set_tex_dir(md, EAST, md->data->east))
		return (-1);
	if (set_tex_dir(md, WEST, md->data->west))
		return (-1);
	return (0);
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
