/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:10:33 by gylim             #+#    #+#             */
/*   Updated: 2023/06/29 19:16:42 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
	This function treats partial writing as an error.
*/
int	ft_write(int fd, const void *buf, size_t count)
{
	ssize_t	res;

	res = write(fd, buf, count);
	if (res == ERROR || (size_t)res < count)
		return (ERROR);
	return (res);
}
