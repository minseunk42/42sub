/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:37:31 by minseunk          #+#    #+#             */
/*   Updated: 2022/11/13 22:07:28 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*out;

	out = (char *)malloc(ft_strlen(str) + 1);
	if (!out)
		return (0);
	out = (char *)ft_memmove(out, (void *)str, ft_strlen(str) + 1);
	return (out);
}
