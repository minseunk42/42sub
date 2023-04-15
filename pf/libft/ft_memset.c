/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:44:29 by minseunk          #+#    #+#             */
/*   Updated: 2022/11/13 17:53:39 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int val, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
		((unsigned char *)ptr)[i++] = val;
	return (ptr);
}
