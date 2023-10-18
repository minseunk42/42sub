/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:36:34 by ubuntu            #+#    #+#             */
/*   Updated: 2023/10/18 19:25:01 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	my_mlx_pixel_put(t_mlx_data *md, int x, int y, int color)
{
	char	*dst;

	dst = md->addr + (y * md->line_length + x * (md->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_color(t_rgb)
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

void draw(t_mlx_data *md)
{
  int *temp;

	md->img_ptr = mlx_xpm_file_to_image(md->mlx_ptr, "./test", &w, &h);
  md->addr = mlx_get_data_addr(md->img_ptr, &(md->bits_per_pixel) \
	, &md->line_length, &md->endian);
  temp = (int *)&md->addr[(md->bits_per_pixel / 8) * 4];
}

int	tex_color(t_rc_data *rc, t_mlx_data *md)
{
	int	color;
	int	x;
	int	y;

	x = 
	if (rc->side == 1)
	{
		if (rc->raydiry > 0)
			color = get_color_tex(md->texture[WEST]);
		else
			color = get_color_tex(md->texture[EAST]);

	}
	else
	{
		if (rc->raydirx > 0)
			color = get_color_tex(md->texture[SOUTH]);
		else
			color = get_color_tex(md->texture[NORTH]);
	}
	return (color);	
}