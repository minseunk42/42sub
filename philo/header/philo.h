/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:57:16 by minseunk          #+#    #+#             */
/*   Updated: 2023/09/17 21:55:49 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

typedef struct s_arg
{
	pthread_mutex_t	mutex;
	unsigned long	itime;
	int				nofpl;
	int				tteat;
	int				ttdie;
	int				ttslp;
	int				edeat;
	int				*fork;
	int				*phid;
}	t_arg;

int	get_usec(void);
int	ft_atoi(const char *str);
int	free_arg(t_arg *arg);
int	philo(t_arg *arg);

#endif