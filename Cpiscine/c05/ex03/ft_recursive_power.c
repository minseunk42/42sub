/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:16:26 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/04 20:57:51 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rec(int nb, int power, int *o)
{
	if (power > 1)
	{
		*o *= nb;
		rec(nb, power - 1, o);
	}
}

int	ft_recursive_power(int nb, int power)
{
	int	o;

	o = nb;
	if (power == 0)
		return (1);
	if (power < 0 || nb == 0)
		return (0);
	rec(nb, power, &o);
	return (o);
}
