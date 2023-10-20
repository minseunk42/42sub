/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:36:34 by ubuntu            #+#    #+#             */
/*   Updated: 2023/10/21 00:21:09 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	my_mlx_pixel_put(t_mlx_data *md, int x, int y, int color)
{
	char	*dst;

	dst = md->addr + (y * md->line_length + x * (md->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_color(t_rgb *rgb)
{
	int	out;

	out = 0;
	out += rgb->red;
	out <<= 8;
	out += rgb->green;
	out <<= 8;
	out += rgb->blue;
	return (out);
}

int	get_color_tex(t_rc_data *rc, t_mlx_data *md, int dir)
{
	int	*temp;

	temp = (int *)&md->texture[dir].addr[rc->texy \
	* md->texture[dir].line_length \
	+ rc->texx * (md->texture[dir].bits_per_pixel / 8)];
	return (*temp);
}

void	init_draw_val(t_rc_data *rc, t_mlx_data *md)
{
	rc->lineheight = (int)(ROWPIX / rc->walldist);
	rc->drawstart = ROWPIX / 2 - (rc->lineheight / 2);
	if (rc->drawstart < 0)
		rc->drawstart = 0;
	rc->drawend = ROWPIX / 2 + (rc->lineheight / 2);
	if (rc->drawend >= ROWPIX)
		rc->drawend = ROWPIX - 1;
	if (rc->dir == NORTH || rc->dir == SOUTH)
		rc->wallx = md->dval[PSY] + rc->walldist * rc->raydiry;
	else
		rc->wallx = md->dval[PSX] + rc->walldist * rc->raydirx;
	rc->wallx -= floor((rc->wallx));
	rc->texx = (int)(rc->wallx * (double)md->texture[rc->dir].width);
	if (rc->dir == SOUTH || rc->dir == EAST)
		rc->texx = md->texture[rc->dir].width - rc->texx - 1;
	rc->tstep = 1.0 * md->texture[rc->dir].height / rc->lineheight;
	rc->texpos = (rc->drawstart - ROWPIX / 2 + rc->lineheight / 2) * rc->tstep;
}

void	set_rc_dir(t_rc_data *rc)
{
	if (rc->side == 1)
	{
		if (rc->raydiry > 0)
			rc->dir = WEST;
		else
			rc->dir = EAST;
	}
	else
	{
		if (rc->raydirx > 0)
			rc->dir = SOUTH;
		else
			rc->dir = NORTH;
	}
}
