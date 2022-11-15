/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 11:58:44 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/05 20:13:06 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (j < nb)
		dest[i++] = src[j++];
	dest[i] = 0;
	return (dest);
}

#include <stdio.h>
#include <string.h>

int main()
{
	char a1[10] = "abcde";
	char a2[2] = "1";
	char b1[10] = "abcde";
	char b2[2] = "1";

	printf("%s\n",ft_strncat(a1,a2,15));
	printf("%s\n",strncat(b1,b2,15));

}
