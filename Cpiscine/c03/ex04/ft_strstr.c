/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:00:22 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/05 21:26:06 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;

	if (!(*to_find))
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			i = 0;
			while (str[i] == to_find[i])
			{
				if (!to_find[i + 1])
					return (str);
				i++;
			}
		}
		str++;
	}
	return (0);
}
