/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:37:23 by ubuntu            #+#    #+#             */
/*   Updated: 2023/10/25 10:35:27 by minseunk         ###   ########.fr       */
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
		md->dval[DRX] = 1;
		if (md->data->pos->d == SOUTH)
		{
			md->dval[PLY] *= -1;
			md->dval[DRX] *= -1;
		}
	}
	else
	{
		md->dval[DRY] = 0;
		md->dval[PLY] = 0;
		md->dval[PLX] = 0.7;
		md->dval[DRY] = -1;
		if (md->data->pos->d == EAST)
		{
			md->dval[PLX] = -0.7;
			md->dval[DRY] = 1;
		}
	}		
}

int	check_path(t_mlx_data *md)
{
	int	fd;

	fd = 0;
	fd = open(md->data->north, O_RDONLY);
	if (fd == -1)
		return (-1);
	fd = open(md->data->south, O_RDONLY);
	if (fd == -1)
		return (-1);
	fd = open(md->data->east, O_RDONLY);
	if (fd == -1)
		return (-1);
	fd = open(md->data->west, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	return (0);
}

static int	set_tex_dir(t_mlx_data *md, int dir, char *path)
{
	md->texture[dir].has_img = 0;
	md->texture[dir].img_ptr = mlx_xpm_file_to_image(md->mlx_ptr, \
	path, &md->texture[dir].width, &md->texture[dir].height);
	if (!md->texture[dir].img_ptr)
		return (-1);
	md->texture[dir].addr = mlx_get_data_addr(md->texture[dir].img_ptr, \
	&md->texture[dir].bits_per_pixel \
	, &md->texture[dir].line_length, &md->texture[dir].endian);
	md->texture[dir].has_img = 1;
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
	md->win_ptr = mlx_new_window(md->mlx_ptr, COLPIX, ROWPIX, "cub3D");
	if (set_tex(md))
		return (-1);
	md->dval[PSX] = md->data->pos->x + 0.4;
	md->dval[PSY] = md->data->pos->y + 0.4;
	set_dir(md);
	return (0);
}
