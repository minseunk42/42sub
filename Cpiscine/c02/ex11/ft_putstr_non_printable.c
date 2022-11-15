/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 21:01:32 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/08 17:22:01 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char			*hex;
	unsigned char	*strc;

	hex = "0123456789abcdef";
	strc = (unsigned char *)str;
	while (*strc)
	{
		if (*strc < ' ' || *strc > '~')
		{
			write(1, "\\", 1);
			write(1, &hex[*strc / 16], 1);
			write(1, &hex[*strc % 16], 1);
		}
		else
			write (1, strc, 1);
		strc++;
	}
}
