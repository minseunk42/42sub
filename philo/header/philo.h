/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:57:16 by minseunk          #+#    #+#             */
/*   Updated: 2023/09/18 09:05:34 by minseunk         ###   ########.fr       */
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
	int				mxeat;
	int				*fork;
}	t_arg;

typedef struct s_philo
{
	pthread_t		thread;
	unsigned long	ltteat;
	int				philon;
	t_arg			arg;
}	t_philo;

unsigned long	get_usec(void);
int				ft_atoi(const char *str);
int				free_arg(t_arg *arg);
int				philo(t_arg *arg);

#endif