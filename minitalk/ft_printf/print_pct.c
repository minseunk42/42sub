/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:20:11 by minseunk          #+#    #+#             */
/*   Updated: 2023/04/21 20:41:29 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pct(t_format form, va_list *ap, int *cnt)
{
	(void)ap;
	if (form.flag & MNS)
	{
		if (putchar_proc_error('%', cnt) == -1)
			return (-1);
	}
	if (print_space((form.widt - 1), cnt) == -1)
		return (-1);
	if (!(form.flag & MNS))
	{
		if (putchar_proc_error('%', cnt) == -1)
			return (-1);
	}
	return (0);
}
