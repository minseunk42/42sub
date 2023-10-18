/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:14:49 by minseunk          #+#    #+#             */
/*   Updated: 2023/10/18 20:14:05 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	movef(void *param)
{
	t_mlx_data	*md;

	md = param;
	mlx_destroy_image(md->mlx_ptr, md->img_ptr);
	if (!md->data->map[(int)(md->dval[PSX] + md->dval[DRX])][(int)md->dval[PSY]])
		md->dval[PSX] += md->dval[DRX] / 3;
	if (!md->data->map[(int)md->dval[PSX]][(int)(md->dval[PSY] + md->dval[DRY])])
		md->dval[PSY] += md->dval[DRY] / 3;
	raycast(md);
}

void	moveb(void *param)
{
	t_mlx_data	*md;

	md = param;
	mlx_destroy_image(md->mlx_ptr, md->img_ptr);
	if (!md->data->map[(int)(md->dval[PSX] - md->dval[DRX])][(int)md->dval[PSY]])
		md->dval[PSX] -= md->dval[DRX] / 3;
	if (!md->data->map[(int)md->dval[PSX]][(int)(md->dval[PSY] - md->dval[DRY])])
		md->dval[PSY] -= md->dval[DRY] / 3;
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
	if (!md->data->map[(int)(md->dval[PSX] - t_drx)][(int)md->dval[PSY]])
		md->dval[PSX] -= t_drx / 3;
	if (!md->data->map[(int)md->dval[PSX]][(int)(md->dval[PSY] - t_dry)])
		md->dval[PSY] -= t_dry / 3;
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
	if (!md->data->map[(int)(md->dval[PSX] + t_drx)][(int)md->dval[PSY]])
		md->dval[PSX] += t_drx / 3;
	if (!md->data->map[(int)md->dval[PSX]][(int)(md->dval[PSY] + t_dry)])
		md->dval[PSY] += t_dry / 3;
	raycast(md);
}
