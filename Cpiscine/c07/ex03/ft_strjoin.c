/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:55:37 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/08 13:32:22 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*my_strcat(char *dest, char *src)
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

int	my_strlen(char *str)
{
	int	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*out;
	int		total_l;
	int		i;

	total_l = 0;
	i = -1;
	while (++i < size - 1)
	{
		total_l += my_strlen(strs[i]);
		total_l += my_strlen(sep);
	}
	total_l += my_strlen(strs[i]);
	out = (char *)malloc(sizeof(char) * total_l + 1);
	if (!out)
		return (0);
	i = -1;
	out[0] = 0;
	while (++i < size - 1)
	{
		out = my_strcat(out, strs[i]);
		out = my_strcat(out, sep);
	}
	if (size != 0)
		out = my_strcat(out, strs[i]);
	return (out);
}
