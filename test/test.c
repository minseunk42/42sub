#include "../fdf/includes/fdf.h"

void at()
{
	system("leaks fdf");
}

int	fc(void *param)
{
	t_fdf	*fdf;

	fdf = param;
	free(fdf->mlx_ptr);
	exit(0);
	return (0);
}

void	draw_coord(t_fdf fdf)
{
	int	x;
	int	y;
	char a[10];

	x = 0;
	while (++x < 1000)
	{
		y = 0;
		while (++y < 1000)
		{
			if (x % 100 == 0 && y % 5 == 0)
				mlx_pixel_put(fdf.mlx_ptr, fdf.win_ptr, x, y, 0xffffff);
			if (y % 100 == 0 && x % 5 == 0)
				mlx_pixel_put(fdf.mlx_ptr, fdf.win_ptr, x, y, 0xffffff);
			sprintf(a,"%d",x);
			if (x % 100 == 0 && y == 5)
				mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, x, y, 0xffffff, a);
			sprintf(a,"%d",y);
			if (y % 100 == 0 && x == 5)
				mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, x, y, 0xffffff, a);
		}
	}
}

void	draw_line(void *mlx_ptr, void *win_ptr, int xf, int yf, int xt, int yt)
{
	int p;
	int g;

	g = (yt - yf) / (xt - xf);
	p = 0;
	while (xf != xt && yf != yt)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, xf, yf, 0xffffff);
		if (g)
		{
			if (p > 0)
			{
				xf += 1;
				yf += 1;
				p = p + (2 * (xt - xf)) - (2 * (yt - yf));
			}
			else
			{
				yf += 1;
				p = p + (2 * (xt - xf));
			}
		}
		else
		{
			if (p > 0)
			{
				xf += 1;
				yf += 1;
				p = p + 2 * (yf - yt) - 2 * (xt - xf);
			}
			else
			{
				xf += 1;
				p = p + 2 * (yt - yf);
			}
		}
	}
}
/*
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
*/
int	map_init(t_fdf *fdf, char *file)
{
	int		fd;
	int		row;
	int		col;
	char	*temp;

	fd = open(file, O_RDONLY);
	return (0);
}

int	init(t_fdf *fdf, char *file)
{
	//if (is_fdf_file(file))
	//	return (-1);
	if (map_init(fdf, file))
		return (-1);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1000, 1000, "fdf");
	return (0);
}

int	main(int ac, char **av)
{
	t_fdf	fdf;

	atexit(at);
	if (ac < 2)
		return (EXIT_FAILURE);
	if (init(&fdf, av[1]))
		return (EXIT_FAILURE);
//	draw_coord(fdf);
	draw_line(fdf.mlx_ptr, fdf.win_ptr, atoi(av[1]),atoi(av[2]), atoi(av[3]), atoi(av[4]));
	mlx_hook(fdf.win_ptr, 17, 0, fc, &fdf);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}
