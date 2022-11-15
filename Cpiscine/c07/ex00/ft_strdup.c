/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:18:57 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/06 17:54:38 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
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
