/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 11:35:07 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/05 20:06:45 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i + 1 < n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

#include <stdio.h>
#include <string.h>

int main()
{
	char a1[10] = "abc";
	char a2[10] = "ab";
	char b1[10] = "abc";
	char b2[10] = "ab";

	printf("%d\n",ft_strncmp(a1,a2,3));
	printf("%d\n",strncmp(a1,a2,3));

}
