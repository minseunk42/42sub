/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:10:21 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/04 19:19:27 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	s_size;
	unsigned int	d_size;
	unsigned int	i;

	s_size = 0;
	while (src[s_size])
		s_size++;
	d_size = 0;
	while (dest[d_size])
		d_size++;
	if (d_size >= size)
		return (s_size + size);
	i = 0;
	while (src[i] && d_size + i + 1 < size)
	{
		dest[d_size + i] = src[i];
		i++;
	}
	dest[d_size + i] = 0;
	return (s_size + d_size);
}
