/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:20:08 by ubuntu            #+#    #+#             */
/*   Updated: 2023/04/21 20:40:38 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putchar_proc_error(char c, int *cnt)
{
	int	flag;

	flag = write(1, &c, 1);
	if (flag == -1)
		return (-1);
	*cnt += 1;
	return (0);
}

int	print_space(int widt, int *cnt)
{
	int	i;

	i = -1;
	while (++i < widt)
	{
		if (putchar_proc_error(' ', cnt) == -1)
			return (-1);
	}
	return (0);
}

int free_str(char *str)
{
	free(str);
	return (1);
}