/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:46:32 by minseunk          #+#    #+#             */
/*   Updated: 2022/11/21 01:41:55 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*out;

	size = ft_strlen(s1) + ft_strlen(s2);
	if (!size)
		return (0);
	out = (char *)malloc(sizeof(char) * size + sizeof(char));
	if (!out)
		return (0);
	ft_memmove((void *)out, (void *)s1, ft_strlen(s1));
	ft_memmove((void *)&out[ft_strlen(s1)], (void *)s2, ft_strlen(s2));
	out[size] = 0;
	return (out);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != (char)c)
	{
		if (str[i] == 0)
			return (NULL);
		i++;
	}
	return ((char *)&str[i]);
}

void	*ft_memmove(void *dest, void *src, size_t size)
{
	size_t	i;

	if (!src && !dest)
		return (0);
	if (!size)
		return (dest);
	if (dest > src)
	{
		i = size;
		while (i > 0)
		{
			((unsigned char *)dest)[i - 1] = ((unsigned char *)src)[i - 1];
			i--;
		}
	}
	else
	{
		i = -1;
		while (++i < size)
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	}
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	l;

	if (!str)
		return (0);
	l = 0;
	while (str[l])
		l++;
	return (l);
}
