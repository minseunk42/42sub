/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 01:11:10 by minseunk          #+#    #+#             */
/*   Updated: 2023/06/25 09:50:55 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdio.h>
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
	int		(**map)[3];
}	t_fdf;

char		*get_next_line(int fd);
size_t		ft_strlen(const char *str);
int			map_init(t_fdf *fdf, char *file);
char		**ft_split(char const *s, char c);
int			ft_atoi(const char *str);
int			draw_map(t_fdf *fdf);

# define X 0
# define Y 1
# define Z 2
# define ST 0
# define ED 1

#endif