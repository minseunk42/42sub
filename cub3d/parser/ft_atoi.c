/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:59:36 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/14 20:55:22 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	check_digit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		n;
	int		result;
	char	*s;

	i = 0;
	result = 0;
	s = (char *)str;
	while (check_whitespace(*(s + i)) == 1)
		i++;
	n = 0;
	while (check_digit(*(s + i)) == 1)
	{
		result *= 10;
		result += (*(s + i) - 48);
		i++;
		n++;
	}
	if (n > 3)
		print_err_exit("Rgb Input Error\n");
	if (result > 255)
		print_err_exit("Rgb Input Error\n");
	return (result);
}
