/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:23:28 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/20 12:08:56 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	into_map(int fd, char *argv, int **input_int)
{
	char		*buf;
	int			line_count;
	char		*cond_char;
	int			line_len;
	int			idx;

	line_len = ft_line_len(argv, get_first_row(argv));
	line_count = total_line(argv, line_len, get_first_row(argv));
	cond_char = check_cond(argv, line_count, line_count);
	if (cond_char == 0)
		return (-1);
	idx = 0;
	buf = (char *)malloc(sizeof(char) * line_len);
	while (idx < line_count)
	{
		if (idx == 0)
			read(fd, buf, get_first_row(argv) + 1);
		read(fd, buf, line_len);
		if (check_val(buf, cond_char, line_len) == -1)
			return (-1);
		input_int[idx++] = int_arr(buf, line_len, cond_char);
		read(fd, buf, 1);
	}
	free_2((void *)cond_char, (void *)buf);
	return (0);
}

int	first_line_len(char *argv)
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

int	overlap_n_count(char *argv, int count)
{
	int		j;
	char	buf[10];
	int		flag;
	int		fd;

	flag = 1;
	fd = open(argv, O_RDONLY);
	read(fd, buf, 10);
	if (ft_strlen(buf) != (count + 3))
		flag = 0;
	while (buf[count] != '\n')
	{
		j = count + 1;
		while (buf[j] != '\n')
		{
			if (buf[count] == buf[j++])
				flag = 0;
		}
		count++;
	}
	close(fd);
	return (flag);
}

char	*check_cond(char *argv, int line_count, int line_count2)
{
	char	*buf;
	char	*cond_char;
	int		fd;
	int		count;

	fd = open(argv, O_RDONLY);
	count = 0;
	while (line_count > 0)
	{
		count++;
		line_count /= 10;
	}
	buf = (char *)malloc(sizeof(char) * count);
	read(fd, buf, count);
	if (!overlap_n_count(argv, count))
		return (0);
	if (ft_atoi(buf) != line_count2)
		return (0);
	count = 0;
	cond_char = (char *)malloc(sizeof(char) * 3);
	while (read(fd, &buf[0], 1) && buf[0] != '\n')
		cond_char[count++] = buf[0];
	close(fd);
	free(buf);
	return (cond_char);
}

int	*int_arr(char *buf, int line_len, char *cond_char)
{
	int	i;
	int	*input_int;

	i = 0;
	input_int = (int *)malloc(sizeof(int) * line_len);
	while (i < line_len)
	{
		if (cond_char[0] == buf[i])
			input_int[i] = 1;
		else if (cond_char[1] == buf[i])
			input_int[i] = 0;
		i++;
	}
	return (input_int);
}
