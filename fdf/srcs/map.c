/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 11:38:48 by minseunk          #+#    #+#             */
/*   Updated: 2023/06/25 03:44:03 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	get_col(char *file)
{
	int		fd;
	char	*temp;
	char	**temp2;
	int		out;

	fd = open(file, O_RDONLY);
	temp = get_next_line(fd);
	if (temp)
		temp2 = ft_split(temp, ' ');
	else
		return (0);
	out = -1;
	while (temp2[++out])
		free(temp2[out]);
	free(temp2);
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
	return (out);
}

static int	get_row(char *file)
{
	int		fd;
	char	*temp;
	int		out;

	fd = open(file, O_RDONLY);
	temp = get_next_line(fd);
	out = 0;
	while (temp && ++out)
	{
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
	return (out);
}

static int	set_val(t_fdf *fdf, char *str, int row)
{
	char	**temp;
	int		col;

	temp = ft_split(str, ' ');
	col = 0;
	while (temp[col])
		col++;
	if (col != fdf->col)
		return (-1);
	col = -1;
	while (++col < fdf->col)
	{
		fdf->map[row][col][X] = row;
		fdf->map[row][col][Y] = col;
		fdf->map[row][col][Z] = ft_atoi(temp[col]);
	}
	col = -1;
	while (temp[++col])
		free(temp[col]);
	free(temp);
	return (0);
}

int	map_init(t_fdf *fdf, char *file)
{
	int		i;
	int		fd;
	char	*temp;

	fdf->row = get_row(file);
	fdf->col = get_col(file);
	if (!fdf->row || !fdf->col)
		return (-1);
	fdf->map = (int (**)[3])malloc(sizeof(int (*)[3]) * fdf->row);
	i = -1;
	while (++i < fdf->row)
		fdf->map[i] = (int (*)[3])malloc(sizeof(int [3]) * fdf->col);
	i = -1;
	fd = open(file, O_RDONLY);
	while (++i < fdf->row)
	{
		temp = get_next_line(fd);
		if (set_val(fdf, temp, i))
			return (-1);
	}
	close(fd);
	return (0);
}
