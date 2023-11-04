/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:33:36 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/26 20:04:49 by changhyl         ###   ########.fr       */
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

void	check_char_side(t_data *data)
{
	if (data->pos->x == 0 || data->pos->y == 0)
		print_err_exit("Play Error\n");
	if (data->pos->x == data->map_w - 1
		|| data->pos->y == data->map_h - 1)
		print_err_exit("Player Error\n");
}
