/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:13:27 by minseunk          #+#    #+#             */
/*   Updated: 2023/10/21 00:11:01 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static void	init_rc(t_rc_data *rc, t_mlx_data *md, int linei)
{
	rc->camerax = (linei * 2 / (double)COLPIX) - 1;
	rc->raydirx = md->dval[DRX] + md->dval[PLX] * rc->camerax;
	rc->raydiry = md->dval[DRY] + md->dval[PLY] * rc->camerax;
	if (rc->raydirx == 0)
		rc->deltadistx = 1e30;
	else
		rc->deltadistx = fabs(1 / rc->raydirx);
	if (rc->raydiry == 0)
		rc->deltadisty = 1e30;
	else
		rc->deltadisty = fabs(1 / rc->raydiry);
	rc->mapx = (int)md->dval[PSX];
	rc->mapy = (int)md->dval[PSY];
	rc->texpos = 0;
	rc->tstep = 0;
}

static void	init_ray(t_rc_data *rc, t_mlx_data *md)
{
	if (rc->raydirx < 0)
	{	
		rc->stepx = -1;
		rc->sidedistx = (md->dval[PSX] - rc->mapx) * rc->deltadistx;
	}
	else
	{
		rc->stepx = 1;
		rc->sidedistx = (rc->mapx + 1.0 - md->dval[PSX]) * rc->deltadistx;
	}
	if (rc->raydiry < 0)
	{
		rc->stepy = -1;
		rc->sidedisty = (md->dval[PSY] - rc->mapy) * rc->deltadisty;
	}
	else
	{
		rc->stepy = 1;
		rc->sidedisty = (rc->mapy + 1.0 - md->dval[PSY]) * rc->deltadisty;
	}
}

static void	singleray(t_rc_data *rc, t_mlx_data *md)
{
	int	is_wall;

	is_wall = 0;
	init_ray(rc, md);
	while (!is_wall)
	{
		if (rc->sidedistx < rc->sidedisty)
		{
			rc->sidedistx += rc->deltadistx;
			rc->mapx += rc->stepx;
			rc->side = 0;
		}
		else
		{
			rc->sidedisty += rc->deltadisty;
			rc->mapy += rc->stepy;
			rc->side = 1;
		}
		if (md->data->map[rc->mapy][rc->mapx] == '1')
			is_wall = 1;
	}
	if (rc->side == 0)
		rc->walldist = (rc->sidedistx - rc->deltadistx);
	else
		rc->walldist = (rc->sidedisty - rc->deltadisty);
}

static void	draw_vline(t_rc_data *rc, t_mlx_data *md, int linex)
{
	int	liney;

	init_draw_val(rc, md);
	liney = -1;
	while (++liney < ROWPIX)
	{
		if (liney < rc->drawstart)
			my_mlx_pixel_put(md, linex, liney, get_color(md->data->ceiling));
		else if (liney < rc->drawend)
		{
			rc->texy = (int)rc->texpos ;
			my_mlx_pixel_put(md, linex, liney, get_color_tex(rc, md, rc->dir));
			rc->texpos += rc->tstep;
		}
		else
			my_mlx_pixel_put(md, linex, liney, get_color(md->data->floor));
	}
}

int	raycast(t_mlx_data *md)
{
	t_rc_data	rc;
	int			linei;

	md->img_ptr = mlx_new_image(md->mlx_ptr, COLPIX, ROWPIX);
	if (!md->img_ptr)
		return (free_mlx(md));
	md->addr = mlx_get_data_addr(md->img_ptr, &(md->bits_per_pixel) \
	, &md->line_length, &md->endian);
	if (!md->addr)
		return (free_mlx(md));
	linei = -1;
	while (++linei < COLPIX)
	{
		init_rc(&rc, md, linei);
		singleray(&rc, md);
		set_rc_dir(&rc);
		draw_vline(&rc, md, linei);
	}
	mlx_put_image_to_window(md->mlx_ptr, md->win_ptr, md->img_ptr, 0, 0);
	return (0);
}
