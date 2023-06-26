/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:05:51 by minseunk          #+#    #+#             */
/*   Updated: 2023/06/26 18:29:11 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	main(int ac, char **av)
{
	t_stack	st_arr[2];
	char	*cmd;

	if (ac < 2)
		return (-1);
	init_st(st_arr);
	if (proc_av(av, st_arr))
		return (puterr());
	cmd = get_next_line(0);
	while (cmd)
	{
		if (proc_cmd(cmd, st_arr) && free_all(0, st_arr, cmd))
			return (puterr());
		free(cmd);
		cmd = get_next_line(0);
	}
	if (is_sorted(st_arr))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(0, st_arr, cmd);
	return (EXIT_SUCCESS);
}
