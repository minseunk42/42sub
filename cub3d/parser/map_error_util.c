/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:33:36 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/19 14:40:09 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	check_char_i(t_data *data)
{
	int	i;
	int	j;

	i = data->pos->y;
	j = data->pos->x;
	while (i >= 0 && data->map[i][j] != '1')
	{
		if (data->map[i][j] == ' ')
			return (0);
		i--;
	}
	i = data->pos->y;
	while (i < data->map_h && data->map[i][j] != '1')
	{
		if (data->map[i][j] == ' ')
			return (0);
		i++;
	}
	return (1);
}

static int	check_char_j(t_data *data)
{
	int	i;
	int	j;

	i = data->pos->y;
	j = data->pos->x;
	while (j >= 0 && data->map[i][j] != '1')
	{
		if (data->map[i][j] == ' ')
			return (0);
		j--;
	}
	j = data->pos->x;
	while (j < data->map_w && data->map[i][j] != '1')
	{
		if (data->map[i][j] == ' ')
			return (0);
		j++;
	}
	return (1);
}

int	char_surr(t_data *data)
{
	if (!(check_char_i(data)))
		return (0);
	if (!(check_char_j(data)))
		return (0);
	return (1);
}
