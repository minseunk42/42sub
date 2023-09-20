/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:57:16 by minseunk          #+#    #+#             */
/*   Updated: 2023/09/19 20:18:59 by ubuntu           ###   ########.fr       */
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
	int				isfin;
	int				*fork;
}	t_arg;

typedef struct s_philo
{
	pthread_t		thread;
	unsigned long	ltteat;
	int				philon;
	t_arg			*arg;
}	t_philo;

unsigned long	get_usec(void);
int				ft_atoi(const char *str);
int				free_arg(t_arg *arg);
int				philo(t_arg *arg);
int				take_lfork(t_philo *philo);
int				take_rfork(t_philo *philo);
void			backfork(t_philo *philo);

#endif