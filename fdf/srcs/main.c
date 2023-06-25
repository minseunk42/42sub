/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 11:38:54 by minseunk          #+#    #+#             */
/*   Updated: 2023/06/25 10:31:16 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	is_fdf_file(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (file[--i] && file[i] != 'f')
		return (-1);
	if (file[--i] && file[i] != 'd')
		return (-1);
	if (file[--i] && file[i] != 'f')
		return (-1);
	if (file[--i] && file[i] != '.')
		return (-1);
	return (0);
}

int	init(t_fdf *fdf, char *file)
{
	if (is_fdf_file(file))
		return (-1);
	if (map_init(fdf, file))
		return (-1);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1000, 1000, "fdf");
	return (0);
}

void	mul(t_fdf *fdf)
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
			fdf->map[i][j][X] = cos(-3.14 / 6) * x + sin(-3.14 / 6) * y + 500;
			fdf->map[i][j][Y] = cos(-3.14 / 6) * y - sin(-3.14 / 6) * x + 300;
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
			fdf->map[i][j][X] = cos(3.14 / 4) * x - sin(3.14 / 4) * z;
			fdf->map[i][j][Z] = sin(3.14 / 4) * x + cos(3.14 / 4) * z;
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
			fdf->map[i][j][Y] = cos(3.14 / 4) * y + sin(3.14 / 4) * z;
			fdf->map[i][j][Z] = cos(3.14 / 4) * z - sin(3.14 / 4) * y;
		}
	}
}

int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac < 2)
		return (EXIT_FAILURE);
	if (init(&fdf, av[1]))
		return (EXIT_FAILURE);
	//mlx_hook(fdf.win_ptr, 17, 0, fc, &fdf);
	mul(&fdf);
	roty(&fdf);
	rotx(&fdf);
	rotz(&fdf);
	draw_map(&fdf);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}
