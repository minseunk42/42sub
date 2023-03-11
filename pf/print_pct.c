/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:20:11 by minseunk          #+#    #+#             */
/*   Updated: 2023/03/07 22:55:54 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putchar_proc_error(char c)
{
	int	flag;

	flag = write(1, c, 1);
	if (flag == -1)
		return (-1);
	return (0);
}

int	print_pct(t_format form, va_list *ap, int *cnt)
{
	int		i;

	(void)ap;
	if (form.widt > 1)
		*cnt += form.widt;
	else
		*cnt++;
	if ((form.flag |= MNS) == form.flag)
	{
		if (putchar_proc_error('%') == -1)
			return (-1);
	}
	i = 1;
	while (++i < form.widt)
	{
		if (putchar_proc_error(' ') == -1)
			return (-1);
	}
	if ((form.flag |= MNS) != form.flag)
	{
		if (putchar_proc_error('%') == -1)
			return (-1);
	}
	return (0);
}