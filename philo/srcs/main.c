/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:36:33 by minseunk          #+#    #+#             */
/*   Updated: 2023/09/12 20:37:27 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	init(t_arg *arg, int ac, char **av)
{
	if (atoi(av[1]) < 0 || atoi(av[2]) < 0 || \
		atoi(av[3]) < 0 || atoi(av[4]) < 0)
		return (-1);
	if (ac == 6 && atoi(av[5] < 0))
		return (-1);
	gettimeofday(&(arg->it), NULL);
	arg->nplo = atoi(av[1]);
	arg->teat = atoi(av[2]);
	arg->tdie = atoi(av[3]);
	arg->tslp = atoi(av[4]);
	if (ac == 6)
		(*arg)->meat = atoi(av[5]);
}


int	main(int ac, char **av)
{
	t_arg	arg;

	if (ac < 5 || ac > 6)
		return (-1);
	if (init(&arg, av))
		return (-1);
}
