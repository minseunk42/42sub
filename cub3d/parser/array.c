/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:48:05 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/17 22:11:10 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "parse.h"

static void	check_map_err(t_data *data)
{
	data->pos = (t_pos *)malloc(sizeof(t_pos));
	if (!(check_pos(data)))
		map_err_exit(2);
	if (!(check_wall(data)))
		map_err_exit(2);
}

void	fill_arr(char *s1, char *s2, int width)
{
	int	i;

	i = 0;
	while (i < map_strlen(s1))
	{
		if (*(s1 + i) == ' ')
			*(s2 + i) = '0';
		else
			*(s2 + i) = *(s1 + i);
		i++;
	}
	while (i < width)
	{
		*(s2 + i) = '0';
		i++;
	}
}

void	make_arr(t_data *data, t_mapline *mapline)
{
	int			i;
	t_mapline	*p;

	p = mapline;
	i = 0;
	while (i < data->map_h)
	{
		if (!p)
			print_err_exit("Map Error\n");
		data->map[i] = (char *)malloc(sizeof(char) * (data->map_w + 1));
		if (!(data->map[i]))
			print_err_exit("Unknown Error\n");
		data->map[i][data->map_w] = '\0';
		fill_arr(p->line, data->map[i], data->map_w);
		p = p->next;
		i++;
	}
	free_mapline(mapline);
	check_map_err(data);
}
