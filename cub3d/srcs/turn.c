/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:20:27 by minseunk          #+#    #+#             */
/*   Updated: 2023/10/21 00:41:43 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	turnr(void *param)
{
	double		dx_temp;
	double		plx_temp;
	t_mlx_data	*md;

	md = param;
	mlx_destroy_image(md->mlx_ptr, md->img_ptr);
	plx_temp = md->dval[PLX];
	dx_temp = md->dval[DRX];
	md->dval[DRX] = md->dval[DRX] * cos(SPINA) - md->dval[DRY] * sin(SPINA);
	md->dval[DRY] = dx_temp * sin(SPINA) + md->dval[DRY] * cos(SPINA);
	md->dval[PLX] = md->dval[PLX] * cos(SPINA) - md->dval[PLY] * sin(SPINA);
	md->dval[PLY] = plx_temp * sin(SPINA) + md->dval[PLY] * cos(SPINA);
	raycast(md);
}

void	turnl(void *param)
{
	double		dx_temp;
	double		plx_temp;
	t_mlx_data	*md;

	md = param;
	mlx_destroy_image(md->mlx_ptr, md->img_ptr);
	plx_temp = md->dval[PLX];
	dx_temp = md->dval[DRX];
	md->dval[DRX] = md->dval[DRX] * cos(-SPINA) - md->dval[DRY] * sin(-SPINA);
	md->dval[DRY] = dx_temp * sin(-SPINA) + md->dval[DRY] * cos(-SPINA);
	md->dval[PLX] = md->dval[PLX] * cos(-SPINA) - md->dval[PLY] * sin(-SPINA);
	md->dval[PLY] = plx_temp * sin(-SPINA) + md->dval[PLY] * cos(-SPINA);
	raycast(md);
}
