/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:33:36 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/17 22:39:49 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	check_f_roop(t_data *data, int *wall_f, int i)
{
	if (*wall_f > 0)
	{
		if (data->map[i][*wall_f - 1] == '1')
		{
			*wall_f -= 1;
			return (1);
		}
	}
	if (data->map[i][*wall_f] == '1')
		return (1);
	if (*wall_f < data->map_w - 1)
	{
		if (data->map[i][*wall_f + 1] == '1')
		{
			*wall_f += 1;
			return (1);
		}	
	}
	return (0);
}

static int	check_r_roop(t_data *data, int *wall_r, int i)
{
	if (*wall_r < data->map_w - 1)
	{
		if (data->map[i][*wall_r + 1] == '1')
		{
			*wall_r += 1;
			return (1);
		}
	}
	if (data->map[i][*wall_r] == '1')
		return (1);
	if (*wall_r > 0)
	{
		if (data->map[i][*wall_r - 1] == '1')
		{
			*wall_r -= 1;
			return (1);
		}
	}
	return (0);
}

int	check_wall_fw(t_data *data, int *wall_f, int *wall_r)
{
	int	i;

	i = 1;
	while (data->map[i])
	{
		if (!(check_f_roop(data, wall_f, i)))
			return (0);
		if ((data->pos->y == i) && (data->pos->x <= *wall_f))
			return (0);
		i++;
	}
	i = 1;
	while (data->map[i])
	{
		if (!(check_r_roop(data, wall_r, i)))
			return (0);
		if ((data->pos->y == i) && (data->pos->x >= *wall_r))
			return (0);
		i++;
	}
	return (1);
}
