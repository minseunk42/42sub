/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:48:45 by minseunk          #+#    #+#             */
/*   Updated: 2022/11/23 17:36:06 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sep(char s, char c)
{
	return (s == c);
}

static size_t	get_strscnt(char *str, char c)
{
	size_t	cnt;

	if (c == 0)
		return (2);
	cnt = 1;
	while (*str)
	{
		if (!check_sep(*str, c))
		{
			cnt++;
			while (*str && !check_sep(*str, c))
				str++;
		}
		while (*str && check_sep(*str, c))
				str++;
	}
	return (cnt);
}

static void	free_all(char **out, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(out[i]);
	free(out[i]);
	free(out);
}

static int	mkstr(char *str, char c, char **out, int idx)
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
		free_all(out, idx);
		return (0);
	}
	str = str - size;
	i = 0;
	while (i < size)
		dest[i++] = *str++;
	dest[i] = 0;
	out[idx] = dest;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	size_t	i;
	size_t	j;

	out = (char **)ft_calloc(get_strscnt((char *)s, c), sizeof(char *));
	if (!out)
		return (0);
	i = 0;
	j = 0;
	while (s[j] && i < get_strscnt((char *)s, c))
	{
		if (s[j] && !check_sep(s[j], c))
		{
			if (!mkstr((char *)&s[j], c, out, i))
				return (0);
			i++;
			while (s[j] && !check_sep(s[j], c))
				j++;
		}
		while (s[j] && check_sep(s[j], c))
				j++;
	}
	if (out)
		out[i] = 0;
	return (out);
}
