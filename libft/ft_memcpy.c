/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:50:51 by minseunk          #+#    #+#             */
/*   Updated: 2022/11/11 19:47:08 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void *src, size_t size)
{
	size_t	i;

	if (!src && !dest)
		return (0);
	i = -1;
	while (++i < size)
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	return (dest);
}
