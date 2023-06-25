/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:39:01 by minseunk          #+#    #+#             */
/*   Updated: 2023/06/25 17:59:55 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_mul(t_fdf *fdf)
{
	if (fdf->col > fdf->row)
	{
		fdf->mulxy = COLPIX / 2 / fdf->col;
		fdf->mulz = fdf->mulxy * fdf->zmax / fdf->col;
	}
	else
	{
		fdf->mulxy = ROWPIX / 2 / fdf->row;
		fdf->mulz = fdf->mulxy * fdf->zmax / fdf->row;
	}
	if (!fdf->mulxy)
		fdf->mulxy = 1;
	if (!fdf->mulz)
		fdf->mulz = 1;
}

void	weit(t_fdf *fdf)
{
	int	i;
	int	j;

	set_mul(fdf);
	i = -1;
	while (++i < fdf->row)
	{
		j = -1;
		while (++j < fdf->col)
		{
			fdf->map[i][j][X] *= fdf->mulxy;
			fdf->map[i][j][Y] *= fdf->mulxy;
			fdf->map[i][j][Z] *= fdf->mulz;
		}
	}
}

void	bias(t_fdf *fdf)
{
	int	i;
	int	j;

	i = -1;
	while (++i < fdf->row)
	{
		j = -1;
		while (++j < fdf->col)
		{
			fdf->map[i][j][X] += (COLPIX - (fdf->col * fdf->mulxy)) / 2;
			fdf->map[i][j][Y] += (ROWPIX - (fdf->row * fdf->mulxy)) / 2;
		}
	}
}