/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 01:11:10 by minseunk          #+#    #+#             */
/*   Updated: 2023/06/26 13:39:45 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		col;
	int		row;
	int		zmax;
	int		mulxy;
	int		mulz;
	int		(**map)[3];
}	t_fdf;

char		*get_next_line(int fd);
void		free_map(t_fdf *fdf);
int			free_strs(char **strs);
size_t		ft_strlen(const char *str);
int			map_init(t_fdf *fdf, char *file);
char		**ft_split(char const *s, char c);
int			ft_atoi(const char *str);
void		draw_map(t_fdf *fdf);
void		rotx(t_fdf *fdf);
void		roty(t_fdf *fdf);
void		rotz(t_fdf *fdf);
void		weit(t_fdf *fdf);
void		bias(t_fdf *fdf);

# define X 0
# define Y 1
# define Z 2
# define ST 0
# define ED 1
# define PI 3.14
# define COLPIX 1920
# define ROWPIX 1080
# define ESC 53
# define EVT_EXIT 17
# define EVT_KEYE 2
# define WHITE 0xffffff

#endif