/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:39:01 by minseunk          #+#    #+#             */
/*   Updated: 2023/06/25 12:39:13 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	weit(t_fdf *fdf)
{
	int	i;
	int	j;

	i = -1;
	while (++i < fdf->row)
	{
		j = -1;
		while (++j < fdf->col)
		{
			fdf->map[i][j][X] *= 20;
			fdf->map[i][j][Y] *= 20;
			fdf->map[i][j][Z] *= 20;
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
			fdf->map[i][j][X] += 500;
			fdf->map[i][j][Y] += 500;
		}
	}
}