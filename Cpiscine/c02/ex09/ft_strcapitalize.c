/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 09:36:08 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/02 09:57:20 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	is_1st(char *str)
{
	if (str[0] >= 'A' && str[0] <= 'Z')
		return (0);
	if (str[0] >= 'a' && str[0] <= 'z')
		return (0);
	if (str[0] >= '0' && str[0] <= '9')
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'a' - 'A';
	}
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 'a' - 'A';
	i = -1;
	while (str[++i])
	{
		if (is_1st(&str[i - 1]))
		{	
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 'a' - 'A';
		}
	}
	return (str);
}
