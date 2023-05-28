#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

void at()
{
	system("leaks a.out");
}

int	fc(void *param)
{
	printf("%phi",param);
	exit(0);
	return (0);
}

void	draw_coord(void	*mlx_ptr, void	*win_ptr)
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
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xffffff);
			if (y % 100 == 0 && x % 5 == 0)
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xffffff);
			sprintf(a,"%d",x);
			if (x % 100 == 0 && y == 5)
				mlx_string_put(mlx_ptr, win_ptr, x, y, 0xffffff, a);
			sprintf(a,"%d",y);
			if (y % 100 == 0 && x == 5)
				mlx_string_put(mlx_ptr, win_ptr, x, y, 0xffffff, a);
		}
	}
}

void	draw_line(void	*mlx_ptr, void	*win_ptr, int xf, int yf, int xt, int yt)
{
	int p;
	int g = (yt - yf) / (xt - xf);

	if (g)
		p = (2 * (xt - xf)) - (yt - yf);
	else
		p = (2 * (yt - yf)) - (xt - xf);
	while (xf != xt && yf != yt)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, xf, yf, 0xffff);
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
				p = p + 2 * (yt - yf) - 2 * (xt - xf);
			}
			else
			{
				xf += 1;
				p = p + 2 * (yt - yf);
			}
		}
	}
}

int main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*win_ptr;

	atexit(at);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "ofwafe");
	draw_coord(mlx_ptr, win_ptr);
	draw_line(mlx_ptr, win_ptr, atoi(av[1]),atoi(av[2]), atoi(av[3]), atoi(av[4]));
	mlx_hook(win_ptr, 17, 0, fc, win_ptr);
	mlx_loop(mlx_ptr);
	return (0);
}
