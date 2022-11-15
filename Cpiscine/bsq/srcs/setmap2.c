/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setmap2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:21:37 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/20 12:03:14 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	total_line(char *argv, int line, int first_line)
{
	char	*buf;
	int		i;
	int		fd;

	i = 0;
	fd = open(argv, O_RDONLY);
	while (i++ <= first_line)
		read(fd, &buf, 1);
	buf = (char *)malloc(sizeof(char) * (line + 1));
	i = 0;
	while (read(fd, buf, line + 1))
		i++;
	close(fd);
	free(buf);
	return (i);
}

int	get_first_row(char *argv)
{
	int		first_line;
	int		fd;
	char	buf;

	first_line = 0;
	fd = open(argv, O_RDONLY);
	while (read(fd, &buf, 1) && buf != '\n')
			first_line++;
	close(fd);
	return (first_line);
}

int	ft_line_len(char *argv, int first_line)
{
	int		line;
	int		fd;
	char	buf;
	int		i;

	line = 0;
	i = 0;
	fd = open(argv, O_RDONLY);
	while (i++ <= first_line)
		read(fd, &buf, 1);
	while (read(fd, &buf, 1) && buf != '\n')
			line++;
	close(fd);
	return (line);
}
