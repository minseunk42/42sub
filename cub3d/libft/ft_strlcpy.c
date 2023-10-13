/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:42:00 by minseunk          #+#    #+#             */
/*   Updated: 2022/11/13 21:35:34 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	s_size;
	size_t	i;

	s_size = 0;
	while (src[s_size])
		s_size++;
	if (!size)
		return (s_size);
	i = -1;
	while (++i + 1 < size && src[i])
		dest[i] = src[i];
	dest[i] = 0;
	return (s_size);
}
