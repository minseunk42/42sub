/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:07:12 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/17 10:13:06 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "num.h"

t_list	*create_elem(char *key, char *val);
t_list	*sort_insertion_list(t_list *dict);
void	add_list(t_list **dict, char *key, char *val);
void	_memcopy_(char *dest, const char *src, int size);
int		_strcmp_(char *s1, char *s2);
int		_strlen_(const char *str);
int		order_tbl(char *s1, char *s2);

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
	if (set_dict(&dict, path, num))
	{
		write(2, "Dict Error\n", 11);
		return (-1);
	}
	if (read_num(num, dict, _strlen_(num)))
	{
		write(2, "Dict Error\n", 11);
		return (-1);
	}
	return (0);
}
