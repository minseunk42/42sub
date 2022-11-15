/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:56:42 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/12 18:46:50 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_sep(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	get_strscnt(char *str, char *charset)
{
	int	cnt;

	cnt = 1;
	while (*str)
	{
		if (!check_sep(*str, charset))
		{
			cnt++;
			while (!check_sep(*str, charset) && *str)
				str++;
		}
		while (check_sep(*str, charset))
				str++;
	}
	return (cnt);
}

char	*mkstr(char *str, char *charset)
{
	int		size;
	char	*dest;
	int		i;

	size = 0;
	while (!check_sep(*str, charset) && *str)
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

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		i;

	strs = (char **)malloc(sizeof(char *) * get_strscnt(str, charset));
	if (!strs)
		return (0);
	i = 0;
	while (*str)
	{
		if (!check_sep(*str, charset) && *str)
		{
			strs[i++] = mkstr(str, charset);
			while (!check_sep(*str, charset) && *str)
				str++;
		}
		while (check_sep(*str, charset))
			str++;
	}
	strs[i] = 0;
	return (strs);
}
