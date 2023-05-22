/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:50:51 by minseunk          #+#    #+#             */
/*   Updated: 2022/11/17 19:53:25 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned long long	i;

	if (!src && !dest)
		return (0);
	i = -1;
	while ((size_t)(++i) < size)
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	return ((void *)dest);
}
