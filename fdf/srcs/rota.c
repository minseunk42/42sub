/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:33:11 by minseunk          #+#    #+#             */
/*   Updated: 2023/06/25 12:39:19 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotz(t_fdf *fdf)
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
			fdf->map[i][j][X] = cos(-PI / 6) * x + sin(-PI / 6) * y;
			fdf->map[i][j][Y] = cos(-PI / 6) * y - sin(-PI / 6) * x;
		}
	}
}

void	roty(t_fdf *fdf)
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
			fdf->map[i][j][X] = cos(PI / 4) * x - sin(PI / 4) * z;
			fdf->map[i][j][Z] = sin(PI / 4) * x + cos(PI / 4) * z;
		}
	}
}

void	rotx(t_fdf *fdf)
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
			fdf->map[i][j][Y] = cos(PI / 4) * y + sin(PI / 4) * z;
			fdf->map[i][j][Z] = cos(PI / 4) * z - sin(PI / 4) * y;
		}
	}
}
