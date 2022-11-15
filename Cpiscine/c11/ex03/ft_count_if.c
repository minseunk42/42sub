/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 08:54:36 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/13 16:01:42 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	while (*tab && i < length)
	{
		if (f(*tab))
			cnt++;
		tab++;
		i++;
	}
	return (cnt);
}
