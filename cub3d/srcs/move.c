/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:14:49 by minseunk          #+#    #+#             */
/*   Updated: 2023/10/17 11:11:50 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	movef(void *param)
{
	t_mlx_data	*md;

	md = param;
	mlx_destroy_image(md->mlx_ptr, md->img_ptr);
	md->img_ptr = mlx_new_image(md->mlx_ptr, COLPIX, ROWPIX);
	md->addr = mlx_get_data_addr(md->img_ptr, &(md->bits_per_pixel) \
	, &md->line_length, &md->endian);
	if (!worldMap[(int)(md->dval[PSX] + md->dval[DRX])][(int)md->dval[PSY]])
		md->dval[PSX] += md->dval[DRX] / 5;
	if (!worldMap[(int)md->dval[PSX]][(int)(md->dval[PSY] + md->dval[DRY])])
		md->dval[PSY] += md->dval[DRY] / 5;
	raycast(md);
}

void	moveb(void *param)
{
	t_mlx_data	*md;

	md = param;
	mlx_destroy_image(md->mlx_ptr, md->img_ptr);
	md->img_ptr = mlx_new_image(md->mlx_ptr, COLPIX, ROWPIX);
	md->addr = mlx_get_data_addr(md->img_ptr, &(md->bits_per_pixel) \
	, &md->line_length, &md->endian);
	if (!worldMap[(int)(md->dval[PSX] - md->dval[DRX])][(int)md->dval[PSY]])
		md->dval[PSX] -= md->dval[DRX] / 5;
	if (!worldMap[(int)md->dval[PSX]][(int)(md->dval[PSY] - md->dval[DRY])])
		md->dval[PSY] -= md->dval[DRY] / 5;
	raycast(md);
}

void	movel(void *param)
{
	t_mlx_data	*md;

	md = param;
	mlx_destroy_image(md->mlx_ptr, md->img_ptr);
	md->img_ptr = mlx_new_image(md->mlx_ptr, COLPIX, ROWPIX);
	md->addr = mlx_get_data_addr(md->img_ptr, &(md->bits_per_pixel) \
	, &md->line_length, &md->endian);
	if (!worldMap[(int)md->dval[PSX]][(int)(md->dval[PSY] - md->dval[DRY])])
		md->dval[PSY] -= (md->dval[DRY] + 1) / 5;
	raycast(md);
}

void	mover(void *param)
{
	t_mlx_data	*md;

	md = param;
	mlx_destroy_image(md->mlx_ptr, md->img_ptr);
	md->img_ptr = mlx_new_image(md->mlx_ptr, COLPIX, ROWPIX);
	md->addr = mlx_get_data_addr(md->img_ptr, &(md->bits_per_pixel) \
	, &md->line_length, &md->endian);
	if (!worldMap[(int)md->dval[PSX]][(int)(md->dval[PSY] - md->dval[DRY])])
		md->dval[PSY] += (md->dval[DRY] + 1) / 5;
	raycast(md);
}

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
	md->dval[DRX] = md->dval[DRX] * cos(SPINSP) - md->dval[DRY] * sin(SPINSP);
	md->dval[DRY] = dx_temp * sin(SPINSP) + md->dval[DRY] * cos(SPINSP);
	md->dval[PLX] = md->dval[PLX] * cos(SPINSP) - md->dval[PLY] * sin(SPINSP);
	md->dval[PLY] = plx_temp * sin(SPINSP) + md->dval[PLY] * cos(SPINSP);
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
	md->dval[DRX] = md->dval[DRX] * cos(-SPINSP) - md->dval[DRY] * sin(-SPINSP);
	md->dval[DRY] = dx_temp * sin(-SPINSP) + md->dval[DRY] * cos(-SPINSP);
	md->dval[PLX] = md->dval[PLX] * cos(-SPINSP) - md->dval[PLY] * sin(-SPINSP);
	md->dval[PLY] = plx_temp * sin(-SPINSP) + md->dval[PLY] * cos(-SPINSP);
	raycast(md);
}
