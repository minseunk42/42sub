/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 11:29:17 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/05 20:05:07 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

#include <stdio.h>
#include <string.h>

int main()
{
	char a1[10] = "abc";
	char a2[10] = "a";
	char b1[10] = "abc";
	char b2[10] = "a";

	printf("%d\n",ft_strcmp(a1,a2));
	printf("%d\n",strcmp(a1,a2));

}
