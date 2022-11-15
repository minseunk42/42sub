/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:42:19 by minseunk          #+#    #+#             */
/*   Updated: 2022/11/11 19:22:02 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	s_size;
	size_t	d_size;
	size_t	i;

	s_size = 0;
	while (src[s_size])
		s_size++;
	d_size = 0;
	while (dest[d_size])
		d_size++;
	if (d_size >= size)
		return (s_size + size);
	i = 0;
	while (src[i] && d_size + i + 1 < size)
	{
		dest[d_size + i] = src[i];
		i++;
	}
	dest[d_size + i] = 0;
	return (s_size + d_size);
}
