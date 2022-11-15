/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 08:55:16 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/13 14:38:23 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	asd;
	int	dsd;

	i = 0;
	asd = 0;
	dsd = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			asd = 1;
		else if (f(tab[i], tab[i + 1]) > 0)
			dsd = 1;
		if (asd && dsd)
			return (0);
		i++;
	}
	return (1);
}
