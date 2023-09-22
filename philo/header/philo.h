/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:57:16 by minseunk          #+#    #+#             */
/*   Updated: 2023/09/22 09:35:59 by minseunk         ###   ########.fr       */
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
	pthread_mutex_t	*fmtx;
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
	int				eatcnt;
	t_arg			*arg;
}	t_philo;

unsigned long	get_usec(void);
int				ft_atoi(const char *str);
int				free_arg(t_arg *arg);
int				philo(t_arg *arg);
int				take_lfork(t_philo *philo);
int				take_rfork(t_philo *philo);
int				is_fin(t_philo *philo);
int				backfork(t_philo *philo);
int				spend_time(t_philo *philo, int val);
void			print_action(char *str, t_philo *philo);

# define EAT "%lu %d is eating\n"
# define SLP "%lu %d is sleeping\n"
# define THK "%lu %d is thinking\n"
# define TKF "%lu %d has taken a fork\n"
# define DED "%lu %d died\n"
#endif