/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:05:55 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/18 09:30:11 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "parse.h"

static void	init_checker(t_checker *checker)
{
	if (!checker)
		print_err_exit("Unknown Error\n");
	checker->north = 0;
	checker->south = 0;
	checker->west = 0;
	checker->east = 0;
	checker->floor = 0;
	checker->ceiling = 0;
}

static int	check_checker(t_checker *checker)
{
	if (!checker)
		return (0);
	if (checker->north == 1 && checker->south == 1 && checker->west == 1
		&& checker->east == 1 && checker->ceiling == 1 && checker->floor == 1)
		return (1);
	return (0);
}

static void	get_s_config(t_file_data *data, char *line)
{
	int	idx;
	int	id;

	if (!data || !line)
		print_err_exit("Unknown Error\n");
	id = check_id(line, &idx);
	if (id == 1)
		data->checker->north += 1;
	if (id == 2)
		data->checker->south += 1;
	if (id == 3)
		data->checker->west += 1;
	if (id == 4)
		data->checker->east += 1;
	if (id == 5)
		data->checker->floor += 1;
	if (id == 6)
		data->checker->ceiling += 1;
	if (id >= 1 && id <= 4)
		get_text(data, line, &idx, id);
	if (id == 5 || id == 6)
		get_rgb(data, line, &idx, id);
}

static void	get_config(t_file_data *data)
{
	char		*line;

	if (!data)
		print_err_exit("Unknown Error\n");
	init_checker(data->checker);
	data->floor = (t_rgb *)malloc(sizeof(t_rgb));
	data->ceiling = (t_rgb *)malloc(sizeof(t_rgb));
	if (!data->floor || !data->ceiling)
		print_err_exit("Unknown Error\n");
	line = get_next_line(data->fd);
	while (line)
	{
		get_s_config(data, line);
		if (check_checker(data->checker))
			break ;
		line = get_next_line(data->fd);
	}
	if (!line)
		print_err_exit("Config Error\n");
	if (!(check_checker(data->checker)))
		print_err_exit("Config Error\n");
}

t_file_data	*get_data(const char *path)
{
	t_file_data	*data;
	char	*line;

	data = (t_file_data *)malloc(sizeof(t_file_data));
	if (!data)
		print_err_exit("Parse Error\n");
	data->fd = open(path, O_RDONLY);
	if (data->fd < 0)
		print_err_exit("File Open Error\n");
	data->checker = (t_checker *)malloc(sizeof(t_checker));
	if (!(data->checker))
		print_err_exit("Unknown Error\n");
	get_config(data);
	line = get_next_line(data->fd);
	get_map(data, line);
	close(data->fd);
	return (data);
}
