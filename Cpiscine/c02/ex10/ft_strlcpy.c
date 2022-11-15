/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 08:40:29 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/02 13:33:17 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	s_size;
	unsigned int	i;

	s_size = 0;
	while (src[s_size])
		s_size++;
	i = -1;
	while (++i + 1 < size)
		dest[i] = src[i];
	dest[i] = 0;
	return (s_size);
}
