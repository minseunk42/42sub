/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:43:53 by minseunk          #+#    #+#             */
/*   Updated: 2023/05/24 14:09:18 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*out;

	if (!ft_strlen(s2))
		return ((char *)s1);
	size = ft_strlen(s1) + ft_strlen(s2);
	out = (char *)malloc(sizeof(char) * size + sizeof(char));
	if (!out)
		return (0);
	ft_memmove((void *)out, (void *)s1, ft_strlen(s1));
	ft_memmove((void *)&out[ft_strlen(s1)], (void *)s2, ft_strlen(s2) + 1);
	if (s1)
		free((char *)s1);
	return (out);
}
