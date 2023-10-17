/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:13:27 by minseunk          #+#    #+#             */
/*   Updated: 2023/10/17 10:33:38 by minseunk         ###   ########.fr       */
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
}

static void	set_raydir(t_rc_data *rc, t_mlx_data *md)
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
	set_raydir(rc, md);
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
		if (worldMap[rc->mapx][rc->mapy] > 0)
			is_wall = 1;
	}
	if (rc->side == 0)
		rc->walldist = (rc->sidedistx - rc->deltadistx);
	else
		rc->walldist = (rc->sidedisty - rc->deltadisty);
}

static void	draw_vline(t_rc_data *rc, t_mlx_data *md, int linei)
{
	int	lineheight;
	int	drawstart;
	int	drawend;
	int	color;
	int	temp;

	lineheight = (int)(ROWPIX / rc->walldist);
	drawstart = -lineheight / 2 + ROWPIX / 2;
	if (drawstart < 0)
		drawstart = 0;
	drawend = lineheight / 2 + ROWPIX / 2;
	if (drawend >= ROWPIX)
		drawend = ROWPIX - 1;
	//여기부터 텍스쳐 매핑하면
	if (rc->side == 1)
	{
		if (rc->raydiry > 0)
			color = 0xff0000;
		else
			color = 0x00ff00;
	}
	else
	{
		if (rc->raydirx > 0)
			color = 0x0000ff;
		else
			color = 0xffffff;
	}
	//끝!
	temp = -1;
	while (++temp < ROWPIX)
	{
		if (temp < drawstart)
			my_mlx_pixel_put(md, linei, temp, 0xffff);
		else if (temp < drawend)
			my_mlx_pixel_put(md, linei, temp, color);
		else
			my_mlx_pixel_put(md, linei, temp, 0xd3d3d3);
	}
}

void	raycast(t_mlx_data *md)
{
	t_rc_data	rc;
	int			linei;

	linei = -1;
	while (++linei < COLPIX)
	{
		init_rc(&rc, md, linei);
		singleray(&rc, md);
		draw_vline(&rc, md, linei);
	}
	mlx_put_image_to_window(md->mlx_ptr, md->win_ptr, md->img_ptr, 0, 0);
}
