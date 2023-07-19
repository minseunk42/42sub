/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:44:56 by gylim             #+#    #+#             */
/*   Updated: 2023/07/17 19:40:00 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "builtin.h"

int builtin_exit_or_return(int exit_status)
{
	if (isatty(STDIN_FILENO) == 0)
		exit(exit_status);
	return (exit_status);
}
