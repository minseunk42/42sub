/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:36:43 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/20 12:13:10 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_stdin(void)
{
	int		fd;
	char	buf;

	fd = open("minseseok", O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (fd < 0)
		exit(-1);
	while (read(0, &buf, 1))
		write(fd, &buf, 1);
	close(fd);
}

void	main_loop(char *argv, int *i, int fd)
{
	int		**input_int;
	int		line_len;
	int		line_count;
	char	*cond;

	line_len = ft_line_len(argv, get_first_row(argv));
	line_count = total_line(argv, line_len, get_first_row(argv));
	input_int = (int **)malloc(sizeof(int *) * line_count);
	if (into_map(fd, argv, input_int) == -1)
	{
		(*i)++;
		write(2, "map error\n", 10);
		return ;
	}
	cond = check_cond(argv, line_count, line_count);
	input_int = sol_map(input_int, line_count, line_len);
	print_map(input_int, line_count, line_len, cond);
	(*i)++;
	free(cond);
	free_arr2((void **)input_int, line_count);
	close(fd);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	fd;

	i = 0;
	if (argc == 1)
	{
		ft_stdin();
		argv[0] = "minseseok";
	}
	if (argc != 1)
		i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
			exit(1);
		else
			main_loop(argv[i], &i, fd);
	}
	return (0);
}
