/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:43:53 by minseunk          #+#    #+#             */
/*   Updated: 2022/11/12 19:45:59 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*out;

	size = ft_strlen(s1) + ft_strlen(s2);
	out = (char *)malloc(sizeof(char) * size + sizeof(char));
	if (!out)
		return (0);
	ft_memmove((void *)out, (void *)s1, ft_strlen(s1));
	ft_memmove((void *)&out[ft_strlen(s1)], (void *)s2, ft_strlen(s2) + 1);
	return (out);
}
