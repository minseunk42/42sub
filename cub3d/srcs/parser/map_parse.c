/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:21:28 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/16 22:39:14 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"
#include "parse.h"

static t_mapline	*new_mapline(char *line)
{
	t_mapline	*p;

	p = (t_mapline *)malloc(sizeof(t_mapline));
	if (!p)
		return (NULL);
	p->next = NULL;
	p->line = line;
	return (p);
}

static t_mapline	*link_map(t_data *data, char *line)
{
	t_mapline	*p;
	t_mapline	*q;
	t_mapline	*r;

	p = new_mapline(line);
	if (!p)
		return (NULL);
	r = p;
	line = get_next_line(data->fd);
	while (line && check_if_map(line))
	{
		q = new_mapline(line);
		if (!q)
			break ;
		r->next = q;
		r = r->next;
		line = get_next_line(data->fd);
	}
	free(line);
	return (p);
}

void	mov_to_arr(t_data *data, t_mapline *mapline)
{
	t_mapline	*p;

	p = mapline;
	data->map_w = 0;
	data->map_h = 0;
	while (p)
	{
		if (!(p->line) || !(*(p->line)))
			print_err_exit("Unknown Error\n");
		if (map_strlen(p->line) > data->map_w)
			data->map_w = map_strlen(p->line);
		data->map_h += 1;
		p = p->next;
	}
	if (!(data->map_w) || !(data->map_h))
		map_err_exit(2);
	data->map = (char **)malloc(sizeof(char *) * (data->map_h + 1));
	if (!(data->map))
		return ;
	*(data->map + data->map_h) = 0;
	make_arr(data, mapline);
}

void	get_map(t_data *data, char *line)
{
	t_mapline	*mapline;

	if (!data || !line)
		print_err_exit("Unknown Error\n");
	while (!(check_if_map(line)) && line)
	{
		free(line);
		line = get_next_line(data->fd);
	}
	if (!line)
		map_err_exit(1);
	mapline = link_map(data, line);
	if (!mapline)
		map_err_exit(1);
	mov_to_arr(data, mapline);
}
