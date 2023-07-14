/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:30:05 by gylim             #+#    #+#             */
/*   Updated: 2023/06/26 17:28:09 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H

# ifndef DEQUE_TYPE
#  define DEQUE_TYPE

typedef int				t_item;
typedef struct s_deque	*t_deque;

# endif

int		dq_add_front(t_deque dq, t_item item);
int		dq_add_rear(t_deque dq, t_item item);
int		dq_delete_front(t_deque dq);
int		dq_delete_rear(t_deque dq);
int		dq_destroy(t_deque dq);
int		dq_empty(t_deque dq);
t_item	dq_front(t_deque dq);
t_deque	dq_new(void);
t_item	dq_rear(t_deque dq);
int		dq_size(t_deque dq);

/* utils */
int		dq_get_three(t_deque dq, int arr[3]);
int		dq_search(t_deque dq, t_item key);

#endif
