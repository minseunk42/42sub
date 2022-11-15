/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:05:03 by minseunk          #+#    #+#             */
/*   Updated: 2022/11/14 01:10:34 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	size;
	char	*out;

	size = ft_strlen(s);
	out = (char *)malloc(sizeof(char) * size + 1);
	if (!out)
		return (0);
	i = -1;
	while (s[++i])
		out[i] = f(i, s[i]);
	out[i] = 0;
	return (out);
}
