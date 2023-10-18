/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:19:54 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/18 09:30:11 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "parse.h"

void	get_f_rgb(t_file_data *data, char *line, int *idx)
{
	if (!data || !line)
		return ;
	line = cub_substr(line, *idx, ch_strlen(line) - *idx - 1);
	data->floor->red = ft_atoi(line);
	*idx = 0;
	while (*(line + *idx) != ',')
		*idx += 1;
	*idx += 1;
	line = cub_substr(line, *idx, ch_strlen(line) - *idx - 1);
	data->floor->green = ft_atoi(line);
	*idx = 0;
	while (*(line + *idx) != ',')
		*idx += 1;
	*idx += 1;
	line = cub_substr(line, *idx, ch_strlen(line) - *idx - 1);
	data->floor->blue = ft_atoi(line);
	free(line);
}

void	get_c_rgb(t_file_data *data, char *line, int *idx)
{
	if (!data || !line)
		return ;
	line = cub_substr(line, *idx, ch_strlen(line) - *idx - 1);
	data->ceiling->red = ft_atoi(line);
	*idx = 0;
	while (*(line + *idx) != ',')
		*idx += 1;
	*idx += 1;
	line = cub_substr(line, *idx, ch_strlen(line) - *idx - 1);
	data->ceiling->green = ft_atoi(line);
	*idx = 0;
	while (*(line + *idx) != ',')
		*idx += 1;
	*idx += 1;
	line = cub_substr(line, *idx, ch_strlen(line) - *idx - 1);
	data->ceiling->blue = ft_atoi(line);
	free(line);
}
