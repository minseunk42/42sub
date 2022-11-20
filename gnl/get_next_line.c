/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:35:47 by minseunk          #+#    #+#             */
/*   Updated: 2022/11/18 07:47:17 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *str)
{
	int		i;
	char	*out;
	
	i = 0;
	while (str[i] != '\n')
		i++;
	out = (char *)malloc(i + 1);
	i = -1;
	while (str[++i] != '\n')
		out[i] = str[i];
	out[i] = '\n';
	return (out);
}

char	*get_next_line(int fd)
{
	static char	*stt_str;
	char		*buf;
	char		*out;

	buf = (char *)malloc(BUFFER_SIZE);
	if (!buf)
		return (0);
	while (!ft_strchr(stt_str, '\n'))
	{
		read(fd, buf, BUFFER_SIZE);
		stt_str = ft_strjoin((const char *)stt_str, (const char *)buf);
		if (!stt_str)
			break ;
	}
	out = get_line(stt_str);
	stt_str = ft_strchr(stt_str, '\n') + 1;
	return (out);
}

int main()
{
	int	fd;
	
	fd = open("numbers.dict", O_RDONLY);
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	close(fd);
}