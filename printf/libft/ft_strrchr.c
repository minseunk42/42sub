/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:53:24 by minseunk          #+#    #+#             */
/*   Updated: 2022/11/14 00:51:32 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;

	i = ft_strlen(str) - 1;
	if ((char)c == '\0')
		return ((char *)&str[i + 1]);
	if (!str[0])
		return (0);
	while (str[i] != (char)c && i)
		i--;
	if (str[i] != (char)c)
		return (0);
	return ((char *)&str[i]);
}
