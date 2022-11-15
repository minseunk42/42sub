/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:48:45 by minseunk          #+#    #+#             */
/*   Updated: 2022/11/12 20:42:04 by minseunk         ###   ########.fr       */
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

char	*mkstr(char *str, char c)
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
		return (0);
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

	out = (char **)malloc(sizeof(char *) * (get_strscnt((char *)s, c) + 1));
	if (!out)
		return (0);
	i = 0;
	j = 0;
	while (i < get_strscnt((char *)s, c))
	{
		if (!check_sep(s[j], c))
		{
			out[i++] = mkstr((char *)&s[j], c);
			while (!check_sep(s[j], c) && s[j])
				j++;
		}
		while (check_sep(s[j], c))
				j++;
	}
	out[i] = 0;
	return (out);
}
