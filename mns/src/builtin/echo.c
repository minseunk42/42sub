/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:48:43 by gylim             #+#    #+#             */
/*   Updated: 2023/07/28 20:37:42 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"

static int	echo_write(char *str)
{
	if (write(STDOUT_FILENO, str, ft_strlen(str)) < 0)
	{
		perror("minishell: echo");
		return (1);
	}
	return (0);
}

static int	echo_print_arguments(char **argv, int idx)
{	
	if (echo_write(argv[idx]) != 0)
		return (1);
	if (argv[idx + 1] != NULL)
	{
		if (echo_write(" ") != 0)
			return (1);
	}
	return (0);
}

static int	echo_print(char **argv, int i)
{
	if (echo_print_arguments(argv, i) != 0)
		return (1);
	return (0);
}

/*
 * return value: 0 on success, >0 if an error occurs.
 */
int	ft_echo(char **argv)
{
	int	i;
	int	new_line_flag;

	i = 1;
	new_line_flag = 1;
	if (argv[1] == NULL)
	{
		if (echo_write("\n") != 0)
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	if (ft_strncmp(argv[1], "-n", 2) == 0 && ft_strlen(argv[1]) == 2)
	{
		i++;
		new_line_flag = 0;
	}
	while (argv[i] != NULL)
	{	
		if (echo_print(argv, i) != 0)
			return (1);
		i++;
	}
	if (new_line_flag == 1 && echo_write("\n") != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
