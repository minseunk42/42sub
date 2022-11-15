/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:05:04 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/03 17:27:53 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rec(int nb, int *o)
{
	if (nb > 1)
	{
		*o *= nb;
		nb--;
		rec(nb, o);
	}
}

int	ft_recursive_factorial(int nb)
{
	int	o;

	o = 1;
	if (nb < 0)
		return (0);
	rec(nb, &o);
	return (o);
}
