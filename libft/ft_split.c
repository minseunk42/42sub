/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:48:45 by minseunk          #+#    #+#             */
/*   Updated: 2022/11/17 20:56:54 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_sep(char s, char c)
{
	return (s == c);
}

size_t	get_strscnt(char *str, char c)
{
	size_t	cnt;

	cnt = 1;
	while (*str)
	{
		if (!check_sep(*str, c))
		{
			cnt++;
			while (!check_sep(*str, c) && *str)
				str++;
		}
		while (check_sep(*str, c))
				str++;
	}
	return (cnt);
}

void	free_all(char **out)
{
	size_t	i;

	i = -1;
	while (!(out[++i]))
		free(out[i]);
}

char	*mkstr(char *str, char c, char **out)
{
	int		size;
	char	*dest;
	int		i;

	size = 0;
	while (!check_sep(*str, c) && *str)
	{
		size++;
		str++;
	}
	dest = (char *)malloc(sizeof(char) * size + 1);
	if (!dest)
	{
		free_all(out);
		return (0);
	}
	str = str - size;
	i = 0;
	while (i < size)
		dest[i++] = *str++;
	dest[i] = 0;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	size_t	i;
	size_t	j;

	out = (char **)malloc(sizeof(char *) * get_strscnt((char *)s, c));
	if (!out)
		return (0);
	i = 0;
	j = 0;
	while (s[j] && i < get_strscnt((char *)s, c))
	{
		if (!check_sep(s[j], c))
		{
			out[i++] = mkstr((char *)&s[j], c, out);
			if (!out[i])
				return (0);
			while (s[j] && !check_sep(s[j], c))
				j++;
		}
		while (check_sep(s[j], c))
				j++;
	}
	out[i] = 0;
	return (out);
}
