/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:09:13 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/04 21:01:29 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	o;

	o = nb;
	if (power == 0)
		return (1);
	if (power < 0 || nb == 0)
		return (0);
	while (--power)
		o *= nb;
	return (o);
}
