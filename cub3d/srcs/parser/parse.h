/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:23:25 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/17 22:12:11 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdlib.h>

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct s_checker
{
	int	north;
	int	south;
	int	west;
	int	east;
	int	ceiling;
	int	floor;
}	t_checker;

typedef struct s_data
{
	int			fd;
	char		**map;
	t_checker	*checker;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	t_rgb		*floor;
	t_rgb		*ceiling;
	int			map_w;
	int			map_h;
	t_pos		*pos;
}	t_data;

typedef struct s_mapline
{
	char				*line;
	struct s_mapline	*next;
}	t_mapline;

size_t	ch_strlen(const	char *s);
char	*cub_substr(char *s, unsigned int start, size_t len);
int		check_whitespace(char c);
void	print_err_exit(const char *s);
int		check_arg(int argc, char *argv[]);
int		ft_atoi(const char *str);
int		check_id(const char *s, int *idx);
int		is_rgb_input(int c);
void	get_c_rgb(t_data *data, char *line, int *idx);
void	get_f_rgb(t_data *data, char *line, int *idx);
void	add_rgb_err(char *line, int *idx);
void	get_text(t_data *data, char *line, int *idx, int id);
void	get_rgb(t_data *data, char *line, int *idx, int id);
int		check_if_map(const char *s);
int		map_strlen(const char *s);
void	make_arr(t_data *data, t_mapline *mapline);
void	free_mapline(t_mapline *mapline);
void	get_map(t_data *data, char *line);
void	map_err_exit(int errnum);
int		check_pos(t_data *data);
int		check_wall_fw(t_data *data, int *wall_f, int *wall_r);
int		check_wall(t_data *data);
t_data	*get_data(const char *path);
t_data	*run_parse(int argc, char *argv[]);
void	free_data(t_data *data);

#endif
