/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:05:51 by minseunk          #+#    #+#             */
/*   Updated: 2023/05/27 21:27:21 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	main(int ac, char **av)
{
	t_stack	st_arr[2];
	char	*answer;

	if (ac < 2)
		return (-1);
	init(st_arr);
	if (proc_av(av, st_arr) && puterr())
		return (-1);
	if (is_sorted(st_arr))
		return (0);
	answer = 0;
	if (st_arr[STA].size < 6)
		answer = hard(answer, st_arr);
	else
		answer = algo(answer, st_arr);
	ft_printf(answer);
	free(answer);
	return (0);
}
