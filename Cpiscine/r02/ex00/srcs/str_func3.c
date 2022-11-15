/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_func3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:49:29 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/16 19:34:53 by kelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/num.h"

char	*_strstr_(char *str, char *to_find)
{
	unsigned int	i;

	if (!(*to_find))
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			i = 0;
			while (str[i] == to_find[i])
			{
				if (!to_find[i + 1])
					return (str);
				i++;
			}
		}
		str++;
	}
	return (0);
}

char	*_strcat_(char *dest, char *src)
{
	unsigned int	i;

	i = 0;
	while (dest[i])
		i++;
	while (*src)
		dest[i++] = *src++;
	dest[i] = 0;
	return (dest);
}

char	*_strdup_(char *src)
{
	int		l;
	char	*out;

	l = 0;
	while (src[l])
		l++;
	out = (char *)malloc(sizeof(char) * l + 1);
	if (!out)
		return (0);
	while (*src)
		*out++ = *src++;
	*out = 0;
	out = out - l;
	return (out);
}

char	*_strjoin_(char *str1, char *str2)
{
	char	*out;
	int		total_l;

	total_l = 0;
	total_l += _strlen_(str1);
	total_l += _strlen_(str2);
	out = (char *)malloc(sizeof(char) * total_l + 1);
	if (!out)
		return (0);
	out[0] = 0;
	out = _strcat_(out, str1);
	out = _strcat_(out, str2);
	return (out);
}
