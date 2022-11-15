/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:41:50 by minseunk          #+#    #+#             */
/*   Updated: 2022/11/14 01:07:12 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*out;

	if (start >= ft_strlen(s) || !ft_strlen(s))
		return (NULL);
	out = (char *)malloc(sizeof(char) * len + 1);
	if (!out)
		return (0);
	i = 0;
	while (i < len && s[i])
	{
		out[i] = s[start + i];
		i++;
	}
	out[i] = 0;
	return (out);
}
