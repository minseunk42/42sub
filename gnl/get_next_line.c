/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:35:47 by minseunk          #+#    #+#             */
/*   Updated: 2022/11/21 01:43:36 by minseunk         ###   ########.fr       */
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
	static char	*stt_str;
	char		*buf;
	char		*out;

	while (!ft_strchr(stt_str, '\n') && !ft_strchr(stt_str, 0))
	{
		buf = (char *)malloc(BUFFER_SIZE);
		if (!buf)
			return (0);
		read(fd, buf, BUFFER_SIZE);
		stt_str = ft_strjoin((const char *)stt_str, (const char *)buf);
		free(buf);
		if (!stt_str)
			break ;
	}
	out = get_line(stt_str);
	stt_str = ft_memmove(stt_str, stt_str + (ft_strlen(out)), ft_strlen(stt_str));
	printf("!!!!!!!!%s",out);
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
