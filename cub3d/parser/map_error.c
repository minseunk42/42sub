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

static int	check_surr(t_data *data, int i, int j)
{
	if (i > 0)
	{
		if (data->map[i - 1][j] == ' ')
			return (0);
	}
	if (i < data->map_h - 1)
	{
		if (data->map[i + 1][j] == ' ')
			return (0);
	}
	if (j > 0)
	{
		if (data->map[i][j - 1] == ' ')
			return (0);
	}
	if (j < data->map_w - 1)
	{
		if (data->map[i][j + 1] == ' ')
			return (0);
	}
	return (1);
}

int	check_wall(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0')
			{
				if (i == 0 || i == data->map_h - 1
					|| j == 0 || j == data->map_w - 1)
					return (0);
				if (!(check_surr(data, i, j)))
					return (0);
			}
			j++;
		}
		i++;
	}
	if (!(char_surr(data)))
		return (0);
	return (1);
}
