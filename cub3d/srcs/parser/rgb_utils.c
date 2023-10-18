/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:36:03 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/14 18:39:57 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	is_rgb_input(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c == ',')
		return (1);
	if (check_whitespace(c))
		return (1);
	else
		return (0);
}

void	add_rgb_err(char *line, int *idx)
{	
	int	i;
	int	count;

	if (!line)
		print_err_exit("No Line Found\n");
	i = *idx;
	count = 0;
	while (*(line + i))
	{
		if (ft_isdigit(*(line + i)))
		{
			count++;
			while (*(line + i) && ft_isdigit(*(line + i)))
				i++;
			while (*(line + i) && check_whitespace(*(line + i)))
				i++;
			if (*(line + i) != ',')
				break ;
		}
		i++;
	}
	if (count != 3)
		print_err_exit("Rgb Input Error\n");
}
