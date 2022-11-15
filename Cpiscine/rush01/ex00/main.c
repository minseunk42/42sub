/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyep <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 05:48:01 by sanghyep          #+#    #+#             */
/*   Updated: 2022/10/16 17:16:30 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

int		no_dup(int **table, int row, int col, int n);
void	print_answer(int **table, int n);
int		**mk_n_table(int n);
int		check_from_top(int **table, int *view);
int		check_from_bottom(int **table, int *view);
int		check_from_left(int **table, int *view);
int		check_from_right(int **table, int *view);
int		is_board_perfect(int **table, int *view);
int		proc_argv(char *argv);
int		get_n(int cnt, int *n);
void	free_all(int **table, int *view);
int		init(int **table, int *view);
int		*put_argument(int n, char *argv);

int	put(int **table, int row, int col, int *view)
{
	int	building_height;

	if (row == view[0])
	{
		if (is_board_perfect(table, view))
			return (1);
		return (0);
	}
	if (col == view[0])
	{
		if (put(table, row + 1, 0, view))
			return (1);
		return (0);
	}
	building_height = 1;
	while (building_height <= view[0])
	{
		table[row][col] = building_height;
		if (no_dup(table, row, col, view[0]) && put(table, row, col + 1, view))
			return (1);
		table[row][col] = 0;
		building_height++;
	}
	return (0);
}

void	put_zero(int **table, int n)
{
	int	row;
	int	col;

	row = 0;
	while (row < n)
	{
		col = 0;
		while (col < n)
		{
			table[row][col] = 0;
			col++;
		}
		row++;
	}
}

int	main(int argc, char *argv[])
{
	int	**table;
	int	*view;
	int	result;
	int	n;

	if (argc != 2 || !get_n(proc_argv(argv[1]), &n))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	view = put_argument(n, argv[1]);
	table = mk_n_table(n);
	put_zero(table, n);
	result = put(table, 0, 0, view);
	if (result == 1)
	{
		print_answer(table, n);
		system("leaks a.out");
		free_all(table, view);
		return (1);
	}
	else
		write(2, "Error\n", 6);
	free_all(table, view);
	system("leaks a.out");
	return (0);
}
