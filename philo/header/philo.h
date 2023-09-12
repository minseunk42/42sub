/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:57:16 by minseunk          #+#    #+#             */
/*   Updated: 2023/09/12 20:49:57 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

typedef struct s_arg
{
	struct timeval	it;
	int				nplo;
	int				teat;
	int				tdie;
	int				tslp;
	int				meat;
}	t_arg;

int	get_time(t_arg arg);
int	atoi(const char *str);

#endif