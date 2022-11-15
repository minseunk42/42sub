/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:10:21 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/05 20:27:44 by minseunk         ###   ########.fr       */
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

#include <stdio.h>
#include <string.h>

int main()
{
	char a1[15] = "abcdefghij";
	char a2[15] = "123";
	char b1[15] = "abcdefghij";
	char b2[15] = "123";

	printf("%d\n",ft_strlcat(a1,a2,10));
	printf("%lu\n",strlcat(b1,b2,10));
	printf("%s\n",a1);
	printf("%s\n",b1);

}
