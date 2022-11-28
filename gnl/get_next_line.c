/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:35:47 by minseunk          #+#    #+#             */
/*   Updated: 2022/11/28 05:58:33 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_one_line(char *str)
{
	int		size;
	int		i;
	char	*out;

	if (!str)
		return (0);
	size = 0;
	while (str[size] && str[size] != '\n')
		size++;
	out = (char *)malloc(size + 1 + (str[size] == '\n'));
	out[size + (str[size] == '\n')] = 0;
	i = -1;
	while (++i < size + (str[size] == '\n'))
		out[i] = str[i];
	return (out);
}

char	*read_line(int fd, char *ba, char *buf)
{
	int	end;

	end = 1;
	while (1)
	{
		end = read(fd, buf, BUFFER_SIZE);
		if (!end)
			break ;
		if (end == -1)
		{
			free(ba);
			return (0);
		}
		buf[end] = 0;
		if (!ba)
		{
			ba = (char *)malloc(1);
			ba[0] = 0;
		}
		ba = ft_strjoin(ba, buf);
		if (end < BUFFER_SIZE)
			break ;
	}
	return (ba);
}

char	*get_next_line(int fd)
{
	static char	*ba[OPEN_MAX + 3];
	char		*out;
	char		*buf;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	ba[fd] = read_line(fd, ba[fd], buf);
	free(buf);
	if (!ft_strlen(ba[fd]) && ba[fd])
	{
		free(ba[fd]);
		return (0);
	}
	out = get_one_line(ba[fd]);
	ba[fd] = ft_memmove(ba[fd], ba[fd] + (ft_strlen(out)), \
	ft_strlen(ba[fd]) - ft_strlen(out) + 1);
	printf("%s", out);
	return (out);
}

int main()
{
	int		fd;

	fd = open("limits.txt", O_RDONLY);	
	free(get_next_line(fd));
	free(get_next_line(fd));
	free(get_next_line(fd));
//	system("leaks a.out");
	close(fd);
}
