/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:20:27 by minseunk          #+#    #+#             */
/*   Updated: 2023/10/18 08:28:47 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	turnl(void *param)
{
	double		dx_temp;
	double		plx_temp;
	t_mlx_data	*md;

	md = param;
	mlx_destroy_image(md->mlx_ptr, md->img_ptr);
	md->img_ptr = mlx_new_image(md->mlx_ptr, COLPIX, ROWPIX);
	md->addr = mlx_get_data_addr(md->img_ptr, &(md->bits_per_pixel) \
	, &md->line_length, &md->endian);
	plx_temp = md->dval[PLX];
	dx_temp = md->dval[DRX];
	md->dval[DRX] = md->dval[DRX] * cos(SPINA) - md->dval[DRY] * sin(SPINA);
	md->dval[DRY] = dx_temp * sin(SPINA) + md->dval[DRY] * cos(SPINA);
	md->dval[PLX] = md->dval[PLX] * cos(SPINA) - md->dval[PLY] * sin(SPINA);
	md->dval[PLY] = plx_temp * sin(SPINA) + md->dval[PLY] * cos(SPINA);
	raycast(md);
}

void	turnr(void *param)
{
	double		dx_temp;
	double		plx_temp;
	t_mlx_data	*md;

	md = param;
	mlx_destroy_image(md->mlx_ptr, md->img_ptr);
	md->img_ptr = mlx_new_image(md->mlx_ptr, COLPIX, ROWPIX);
	md->addr = mlx_get_data_addr(md->img_ptr, &(md->bits_per_pixel) \
	, &md->line_length, &md->endian);
	plx_temp = md->dval[PLX];
	dx_temp = md->dval[DRX];
	md->dval[DRX] = md->dval[DRX] * cos(-SPINA) - md->dval[DRY] * sin(-SPINA);
	md->dval[DRY] = dx_temp * sin(-SPINA) + md->dval[DRY] * cos(-SPINA);
	md->dval[PLX] = md->dval[PLX] * cos(-SPINA) - md->dval[PLY] * sin(-SPINA);
	md->dval[PLY] = plx_temp * sin(-SPINA) + md->dval[PLY] * cos(-SPINA);
	raycast(md);
}