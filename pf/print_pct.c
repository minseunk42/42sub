/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:20:11 by minseunk          #+#    #+#             */
/*   Updated: 2023/04/03 16:36:35 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pct(t_format form, va_list *ap, int *cnt)
{
	int		i;

	(void)ap;
	if (form.widt > 1)
		*cnt += form.widt;
	else
		*cnt += 1;
	if (form.flag & MNS)
	{
		if (putchar_proc_error('%') == -1)
			return (-1);
	}
	i = 0;
	while (++i < form.widt)
	{
		if (putchar_proc_error(' ') == -1)
			return (-1);
	}
	if (!(form.flag & MNS))
	{
		if (putchar_proc_error('%') == -1)
			return (-1);
	}
	return (0);
}
