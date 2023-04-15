/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:47:49 by minseunk          #+#    #+#             */
/*   Updated: 2022/11/19 23:15:53 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	*out;

	i = 0;
	while (str[i] != (char)c)
	{
		if (str[i] == 0)
			return (NULL);
		i++;
	}
	out = (char *)&str[i];
	return (out);
}
