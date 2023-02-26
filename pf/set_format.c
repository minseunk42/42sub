/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:23:10 by minseunk          #+#    #+#             */
/*   Updated: 2023/02/26 22:42:56 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_type(char c)
{
	char	*str;

	str = "cspdiuxX%";
	while (*str)
	{
		if (c == *(str++))
			return (1);
	}
	return (0);
}

int	set_type(char c)
{
	if (c == 'c')
		return (CHR);
	if (c == 's')
		return (STR);
	if (c == 'p')
		return (PTR);
	if (c == 'd' || c == 'i')
		return (INT);
	if (c == 'u')
		return (USI);
	if (c == 'x' || c == 'X')
		return (HEX);
	if (c == '%')
		return (PCT);
}

void	set_format(char **str, t_format *form)
{
	while (is_type(*(*++str)))
	{
		if (form->flag && **str >= '1' && **str <= '9')
		{
			form->widt = ft_atoi(*str);
			while (**str >= '0' && **str <= '9')
				*str++;
		}
		else if (**str == '.')
		{
			form->prec = ft_atoi(*str++);
			while (**str >= '0' && **str <= '9')
				*str++;
		}
		else
			form->flag += set_flag(**str);
	}
	form->type = set_type(**str);
}
