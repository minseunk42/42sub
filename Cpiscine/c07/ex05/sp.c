/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:56:42 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/06 20:49:59 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	check_in(char c, char *charset)
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

	cnt = 0;
	while (*str)
	{
		if (!check_in(*str, charset))
		{
			cnt++;
			while (!check_in(*str, charset) && *(str + 1))
				str++;
		}
		else
		{
			while (check_in(*str, charset) && *(str + 1))
				str++;
		}
		if (!*str)
			break ;
		str++;
	}
	return (cnt);
}

int get_size(char *str, char *charset)
{
	int		size;

	size = 0;
	while (check_in(*str, charset) && *str)
		str++;
	while (!check_in(*str, charset) && *str)
	{
		size++;
		str++;
	}
	return (size);
}

char	*mkstr(char *str, char *charset)
{
	int		size;
	char	*dest;
	int		i;

	size = 0;
	while (check_in(*str, charset) && *str)
		str++;
	while (!check_in(*str, charset) && *str)
	{
		size++;
		str++;
	}
	dest = (char *)malloc(sizeof(char) * size + 1);
	if (!dest)
		return (0);
	str = str - size;
	dest[size] = 0;
	i = 0;
	while (i < size)
		dest[i++] = *str++;
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		i;
	
	strs = (char **)malloc(sizeof(char *) + get_strscnt(str, charset) + 1);
	if (!strs)
		return (0);
	i = 0;
	while (*str)
	{
		if (check_in(*str, charset))
		{
			while (check_in(*str, charset) && *(str + 1))
				str++;
		}
		strs[i] = (char *)malloc(sizeof(char) * get_size(str, charset) + 1);
		strs[i++] = mkstr(str, charset);
		while (!check_in(*str, charset) && *(str + 1))
			str++;
		if (!*str)
			break ;
		str++;
		printf("i = %d, strs[0] = %s\n",i,strs[0]);
	}
	printf("outstrs[i] = %s",strs[0]);
	return (strs);
}

int main()
{
	char a[100] = ",,,abc,123,abc,123,,,,,abc,123,l21331";
	int i = -1;
	char **strs = ft_split(a, ",");

	while (++i < 0)
		printf("%s\n",strs[i]);
	return (1);
}
