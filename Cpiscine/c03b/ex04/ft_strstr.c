/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:00:22 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/10 08:27:46 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_strcmp(char *str, char *to_find)
{
	unsigned int	i;

	i = 0;
	while (to_find[i])
	{
		if (str[i] != to_find[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	l;

	l = 0;
	while (str[l])
		l++;
	i = 0;
	while (str[i])
	{
		if (!(*to_find))
			break ;
		if (str[i] == *to_find && my_strcmp(&str[i], to_find))
			break ;
		i++;
	}
	if (l == i)
		return (0);
	str = str + i;
	return (str);
}

#include <stdio.h>
#include <string.h>

int main()
{
	char a1[50] ="abq afsdjuilliask ";
	char b1[50] ="abq adfjslkasf";
	char a2[3] = {'a','b','q'};
	char b2[3] = {'a','b','q'};

	printf("%s\n",ft_strstr(a1,a2));
	printf("%s\n",strstr(b1,b2));

}
