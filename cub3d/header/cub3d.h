/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:56:14 by minseunk          #+#    #+#             */
/*   Updated: 2023/10/17 11:12:00 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	dval[6];
}	t_mlx_data;

typedef struct s_rc_data
{
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	deltadistx;
	double	deltadisty;
	double	sidedistx;
	double	sidedisty;
	double	walldist;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		side;
}	t_rc_data;

# define COLPIX 1920
# define ROWPIX 1080

# define ST 0
# define ED 1
# define ESC 53
# define EVT_EXIT 17
# define EVT_KEYE 2
# define KA 0
# define KS 1
# define KD 2
# define KW 13
# define PSX 0
# define PSY 1
# define DRX 2
# define DRY 3
# define PLX 4
# define PLY 5
# define SPINSP 0.1

void	movef(void *param);
void	moveb(void *param);
void	movel(void *param);
void	mover(void *param);
void	turnl(void *param);
void	turnr(void *param);
void	raycast(t_mlx_data *mlx_data);
void	my_mlx_pixel_put(t_mlx_data *md, int x, int y, int color);
void	init(t_mlx_data *md);
int		fin(void *param);
int		key_handler(int keycode, void *param);

extern int	worldMap[24][24];

#endif