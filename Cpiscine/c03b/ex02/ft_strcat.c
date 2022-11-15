/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 11:39:07 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/05 20:09:59 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;

	i = 0;
	while (dest[i])
		i++;
	while (*src)
		dest[i++] = *src++;
	dest[i] = 0;
	return (dest);
}

#include <stdio.h>
#include <string.h>

int main()
{
	char a1[10] = "abc";
	char a2[10] = "123";
	char b1[10] = "abc";
	char b2[10] = "123";

	printf("%s\n",ft_strcat(a1,a2));
	printf("%s\n",strcat(b1,b2));

}
