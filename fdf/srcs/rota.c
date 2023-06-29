/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rota.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:33:11 by minseunk          #+#    #+#             */
/*   Updated: 2023/06/29 18:21:55 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	rotz(t_fdf *fdf)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	while (++i < fdf->row)
	{
		j = -1;
		while (++j < fdf->col)
		{
			x = fdf->map[i][j][X];
			y = fdf->map[i][j][Y];
			fdf->map[i][j][X] = cos(fdf->ang[Z]) * x + sin(fdf->ang[Z]) * y;
			fdf->map[i][j][Y] = cos(fdf->ang[Z]) * y - sin(fdf->ang[Z]) * x;
		}
	}
}

static void	roty(t_fdf *fdf)
{
	int	i;
	int	j;
	int	x;
	int	z;

	i = -1;
	while (++i < fdf->row)
	{
		j = -1;
		while (++j < fdf->col)
		{
			x = fdf->map[i][j][X];
			z = fdf->map[i][j][Z];
			fdf->map[i][j][X] = cos(fdf->ang[Y]) * x - sin(fdf->ang[Y]) * z;
			fdf->map[i][j][Z] = sin(fdf->ang[Y]) * x + cos(fdf->ang[Y]) * z;
		}
	}
}

static void	rotx(t_fdf *fdf)
{
	int	i;
	int	j;
	int	y;
	int	z;

	i = -1;
	while (++i < fdf->row)
	{
		j = -1;
		while (++j < fdf->col)
		{
			y = fdf->map[i][j][Y];
			z = fdf->map[i][j][Z];
			fdf->map[i][j][Y] = cos(fdf->ang[X]) * y + sin(fdf->ang[X]) * z;
			fdf->map[i][j][Z] = cos(fdf->ang[X]) * z - sin(fdf->ang[X]) * y;
		}
	}
}

void	rota(t_fdf *fdf)
{
	fdf->ang[X] = PI / 4;
	fdf->ang[Y] = PI / 4;
	fdf->ang[Z] = -PI / 6;
	roty(fdf);
	rotx(fdf);
	rotz(fdf);
}
