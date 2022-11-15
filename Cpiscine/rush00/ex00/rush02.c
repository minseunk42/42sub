/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:42:47 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/01 19:18:50 by seojyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	print_row(int ri, int col, int row, char *marks);

void	rush(int col, int row)
{
	char	*marks;
	int		ri;

	marks = " AACCBB";
	ri = 0;
	while (++ri <= row)
		print_row(ri, col, row, marks);
}

void	print_row(int ri, int col, int row, char *marks)
{
	int	ci;

	ci = 0;
	while (++ci <= col)
	{	
		if (ci * ri == 1)
			ft_putchar(marks[1]);
		else if (ri == 1 && ci == col)
			ft_putchar(marks[2]);
		else if (ci == 1 && ri == row)
			ft_putchar(marks[3]);
		else if (ci * ri == col * row)
			ft_putchar(marks[4]);
		else if (ri == 1 || ri == row)
			ft_putchar(marks[5]);
		else if (ci == 1 || ci == col)
			ft_putchar(marks[6]);
		else
			ft_putchar(marks[0]);
	}
	ft_putchar('\n');
}
