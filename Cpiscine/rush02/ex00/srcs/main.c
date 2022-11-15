/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:07:12 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/16 19:12:29 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "num.h"

int	set_pram(int ac, char **path, char **num, char **av)
{
	if (ac < 2 || ac > 3)
		return (-1);
	if (ac == 2)
	{
		*path = "numbers.dict";
		*num = av[1];
	}
	if (ac == 3)
	{
		*path = av[1];
		*num = av[2];
	}
	if (check_num(*num))
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	char	*path;
	char	*num;
	t_list	*dict;

	if (set_pram(ac, &path, &num, av))
	{	
		write(2, "Error\n", 6);
		return (-1);
	}
	if (set_dict(&dict, path))
	{
		write(2, "Dict Error\n", 11);
		return (-1);
	}
	dict = sort_insertion_list(dict);
	if (read_num(num, dict, _strlen_(num)))
	{
		write(2, "Dict Error\n", 11);
		return (-1);
	}
	write(1, "\n", 1);
	rm_all_list(dict);
	return (0);
}
