/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:32:32 by minseunk          #+#    #+#             */
/*   Updated: 2023/04/27 20:56:38 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

int	check_pid(char *str, int *pid)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
	}
	*pid = ft_atoi(str);
	return (0);
}

int	main(int ac, char **av)
{
	int	svpid;

	svpid = 0;
	if (ac != 3 || check_pid(av[1], &svpid))
		return (-1);
	if (av[2][0] == '2')
		kill(svpid, SIGUSR2);
	else
		kill(svpid, SIGUSR1);
	return (0);
}
