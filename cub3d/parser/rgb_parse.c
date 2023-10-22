/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:19:54 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/21 17:26:30 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "parse.h"

void	get_f_rgb(t_data *data, char *line, int *idx)
{
	if (!data || !line)
		return ;
	line = cub_substr(line, *idx, ch_strlen(line) - *idx);
	data->floor->red = ft_atoi(line);
	*idx = 0;
	while (*(line + *idx) != ',')
		*idx += 1;
	*idx += 1;
	line = cub_substr(line, *idx, ch_strlen(line) - *idx);
	data->floor->green = ft_atoi(line);
	*idx = 0;
	while (*(line + *idx) != ',')
		*idx += 1;
	*idx += 1;
	line = cub_substr(line, *idx, ch_strlen(line) - *idx);
	data->floor->blue = ft_atoi(line);
	free(line);
}

void	get_c_rgb(t_data *data, char *line, int *idx)
{
	if (!data || !line)
		return ;
	line = cub_substr(line, *idx, ch_strlen(line) - *idx);
	data->ceiling->red = ft_atoi(line);
	*idx = 0;
	while (*(line + *idx) != ',')
		*idx += 1;
	*idx += 1;
	line = cub_substr(line, *idx, ch_strlen(line) - *idx);
	data->ceiling->green = ft_atoi(line);
	*idx = 0;
	while (*(line + *idx) != ',')
		*idx += 1;
	*idx += 1;
	line = cub_substr(line, *idx, ch_strlen(line) - *idx);
	data->ceiling->blue = ft_atoi(line);
	free(line);
}
