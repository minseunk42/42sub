/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:18:22 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/20 12:31:47 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	check_in(char *cond, char *buf, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (buf[i] != cond[0] && buf[i] != cond[1])
			return (-1);
		i++;
	}
	return (0);
}

int	check_val(char *buf, char *cond, int col)
{
	if (ft_strlen_check_val(buf) < col)
		return (-1);
	if (check_in(cond, buf, col))
		return (-1);
	return (0);
}
