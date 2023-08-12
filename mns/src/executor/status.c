/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:39:07 by gylim             #+#    #+#             */
/*   Updated: 2023/07/28 18:54:03 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	ft_wifexited(int stat)
{
	return ((stat & 0177) == 0);
}

int	ft_wexitstatus(int stat)
{
	return ((stat >> 8) & 0x000000ff);
}

int	ft_wtermsig(int stat)
{
	return (stat & 0177);
}
