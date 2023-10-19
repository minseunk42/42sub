/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:36:34 by ubuntu            #+#    #+#             */
/*   Updated: 2023/10/19 14:08:01 by ubuntu           ###   ########.fr       */
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

static void	set_txy(t_rc_data *rc, t_mlx_data *md, int *pos, int dir)
{
	double	wallx;
	double	texpos;

	if (rc->side == 0)
		wallx = md->dval[PSY] + rc->walldist * rc->raydiry;
	else
		wallx = md->dval[PSX] + rc->walldist * rc->raydirx;
	wallx -= floor((wallx));
	pos[PSX] = (int)(wallx * (double)md->texture[dir].bits_per_pixel);
    if (rc->side == 0 && rc->raydirx > 0)
		pos[PSX] = md->texture[dir].bits_per_pixel - pos[PSX] - 1;
    if (rc->side == 1 && rc->raydiry < 0)
		pos[PSX] = md->texture[dir].bits_per_pixel - pos[PSX] - 1;
	rc->tstep = 1.0 * md->texture[dir].line_length / rc->lineheight;
	rc->tstep *= rc->wally;
    texpos = (rc->drawstart - ROWPIX / 2 + rc->lineheight / 2) * rc->tstep;
	pos[PSY] = (int)texpos & (md->texture[dir].line_length - 1);
}

static int get_color_tex(t_rc_data *rc, t_mlx_data *md, int dir)
{
	int *temp;
	int	pos[2];

	set_txy(rc, md, pos, dir);
	temp = (int *)&md->texture[dir].addr[pos[PSY] * md->texture[dir].line_length + \
	pos[PSX] * (md->texture[dir].bits_per_pixel / 8)];
	return (*temp);
}

int	tex_color(t_rc_data *rc, t_mlx_data *md)
{
	int	color;

	(void)md;
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
	return (color);
}