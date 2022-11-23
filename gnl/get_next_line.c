/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:35:47 by minseunk          #+#    #+#             */
/*   Updated: 2022/11/22 18:53:44 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *str)
{
	int		i;
	char	*out;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	out = (char *)malloc(i + 1);
	while (i >= 0)
	{
		out[i] = str[i];
		i--;
	}
	return (out);
}

char	*get_next_line(int fd)
{
	static char	**ba;
	char		*buf;
	char		*out;

	ba = (char **)malloc(sizeof(char *) * (OPEN_MAX + 3));
	while (!ft_strchr(ba[fd], '\n'))
	{
		buf = (char *)malloc(BUFFER_SIZE);
		ft_bzero(buf, BUFFER_SIZE);
		if (!buf)
			return (0);
		read(fd, buf, BUFFER_SIZE);
		ba[fd] = ft_strjoin((const char *)ba[fd], (const char *)buf);	
		if (!ba[fd])
			break ;
	}
	free(buf);
	out = get_line(ba[fd]);
	ba[fd] = ft_memmove(ba[fd], ba[fd] + (ft_strlen(out)), ft_strlen(ba[fd]));
	printf("%s",out);
	return (out);
}

int main()
{
	int		fd;

	fd = open("numbers.dict", O_RDONLY);	
	free(get_next_line(fd));
	free(get_next_line(fd));
	free(get_next_line(fd));
	free(get_next_line(fd));
	free(get_next_line(fd));
	free(get_next_line(fd));
	free(get_next_line(fd));
	free(get_next_line(fd));
	free(get_next_line(fd));
	free(get_next_line(fd));
	free(get_next_line(fd));
	free(get_next_line(fd));
	free(get_next_line(fd));
	free(get_next_line(fd));
	free(get_next_line(fd));
	free(get_next_line(fd));
	free(get_next_line(fd));
	free(get_next_line(fd));
	system("leaks a.out");
	close(fd);
}
