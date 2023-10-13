/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:46:17 by minseunk          #+#    #+#             */
/*   Updated: 2023/05/27 23:40:07 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	size_t	i;

	i = -1;
	while (set[++i])
	{
		if (set[i] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	sti;
	size_t	edi;
	char	*out;

	sti = 0;
	while (is_set(s1[sti], set))
		sti++;
	edi = ft_strlen(s1) - 1;
	while (is_set(s1[edi], set))
		edi--;
	out = ft_substr(s1, sti, edi - sti + 1);
	return (out);
}
