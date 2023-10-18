/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:10:56 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/18 09:30:11 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "parse.h"

int	check_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

void	print_err_exit(const char *s)
{
	perror(s);
	printf("Error\n");
	exit(1);
}

void	free_data(t_file_data *data)
{
	int	i;

	free(data->checker);
	free(data->south);
	free(data->north);
	free(data->west);
	free(data->east);
	free(data->floor);
	free(data->ceiling);
	i = 0;
	while (i < data->map_h)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	free(data->pos);
	free(data);
}
