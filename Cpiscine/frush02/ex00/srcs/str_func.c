/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:28:25 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/16 19:30:57 by kelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	_strcmp_(char *s1, char *s2)
{
	while ((*s1 != '\0') && (*s2 != '\0'))
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	_strlen_(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	_putstr_(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	check_num(char *num)
{
	while (*num)
	{
		if (!('0' <= *num && *num <= '9'))
			return (-1);
	}
	return (0);
}
