/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:37:55 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/19 09:32:11 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	get_dir(char c)
{
	if (c == 'N')
		return (NORTH);
	if (c == 'S')
		return (SOUTH);
	if (c == 'W')
		return (WEST);
	if (c == 'E')
		return (EAST);
	return (0);
}

int	check_pos(t_data *data)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
			|| data->map[i][j] == 'W' || data->map[i][j] == 'E')
			{
				count++;
				data->pos->x = j;
				data->pos->y = i;
				data->pos->d = get_dir(data->map[i][j]);
			}
		}
	}
	if (count == 1)
		return (1);
	return (0);
}

static int	get_wall_fw(t_data *data, int *wall_f, int *wall_r)
{
	int	i;

	i = 0;
	while (i < data->map_w)
	{
		if (data->map[0][i] == '1')
			break ;
		i++;
	}
	if (i == data->map_w)
		return (0);
	*wall_f = i;
	while (i < data->map_w)
	{
		if (data->map[0][i] == '0')
			break ;
		i++;
	}
	*wall_r = i - 1;
	return (1);
}

int	check_wall(t_data *data)
{
	int	wall_f;
	int	wall_r;

	if (!(get_wall_fw(data, &wall_f, &wall_r)))
		return (0);
	if (data->pos->y == 0)
	{
		if (wall_f >= data->pos->x || wall_r <= data->pos->x)
			return (0);
	}
	if (!(check_wall_fw(data, &wall_f, &wall_r)))
		return (0);
	while (wall_f <= wall_r)
	{
		if (data->map[data->map_h - 1][wall_f] != '1')
			return (0);
		wall_f++;
	}
	return (1);
}
