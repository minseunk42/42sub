/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:14:49 by minseunk          #+#    #+#             */
/*   Updated: 2023/10/23 07:59:32 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	movef(void *param)
{
	t_mlx_data	*md;

	md = param;
	mlx_destroy_image(md->mlx_ptr, md->img_ptr);
	if (md->data->map[(int)md->dval[PSY]][(int)(md->dval[PSX] + md->dval[DRX])] \
	!= '1')
		md->dval[PSX] += md->dval[DRX] / 3;
	if (md->data->map[(int)(md->dval[PSY] + md->dval[DRY])][(int)md->dval[PSX]] \
	!= '1')
		md->dval[PSY] += md->dval[DRY] / 3;
	raycast(md);
}

void	moveb(void *param)
{
	t_mlx_data	*md;

	md = param;
	mlx_destroy_image(md->mlx_ptr, md->img_ptr);
	if (md->data->map[(int)md->dval[PSY]][(int)(md->dval[PSX] - md->dval[DRX])] \
	!= '1')
		md->dval[PSX] -= md->dval[DRX] / 3;
	if (md->data->map[(int)(md->dval[PSY] - md->dval[DRY])][(int)md->dval[PSX]] \
	!= '1')
		md->dval[PSY] -= md->dval[DRY] / 3;
	raycast(md);
}

void	movel(void *param)
{
	t_mlx_data	*md;
	double		t_drx;
	double		t_dry;

	md = param;
	mlx_destroy_image(md->mlx_ptr, md->img_ptr);
	t_drx = -(md->dval[DRY] * sin(PI / 2));
	t_dry = md->dval[DRX] * sin(PI / 2);
	if (md->data->map[(int)md->dval[PSY]][(int)(md->dval[PSX] - t_drx)] != '1')
		md->dval[PSX] -= t_drx / 3;
	if (md->data->map[(int)(md->dval[PSY] - t_dry)][(int)md->dval[PSX]] != '1')
		md->dval[PSY] -= t_dry / 3;
	raycast(md);
}

void	mover(void *param)
{
	t_mlx_data	*md;
	double		t_drx;
	double		t_dry;

	md = param;
	mlx_destroy_image(md->mlx_ptr, md->img_ptr);
	t_drx = -(md->dval[DRY] * sin(PI / 2));
	t_dry = md->dval[DRX] * sin(PI / 2);
	if (md->data->map[(int)md->dval[PSY]][(int)(md->dval[PSX] + t_drx)] != '1')
		md->dval[PSX] += t_drx / 3;
	if (md->data->map[(int)(md->dval[PSY] + t_dry)][(int)md->dval[PSX]] != '1')
		md->dval[PSY] += t_dry / 3;
	raycast(md);
}
