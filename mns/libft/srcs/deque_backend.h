/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_backend.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:56:55 by gylim             #+#    #+#             */
/*   Updated: 2023/06/26 17:28:44 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_BACKEND_H
# define DEQUE_BACKEND_H

# ifndef DEQUE_TYPE
#  define DEQUE_TYPE

typedef int				t_item;
typedef struct s_deque	*t_deque;

# endif

struct	s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	t_item			item;
};

struct	s_deque
{
	struct s_node	*front;
	struct s_node	*rear;
	int				size;
};

struct s_node	*new_node(t_item item);
int				add_node_to_front(t_deque dq, struct s_node *nd);
int				add_node_to_rear(t_deque dq, struct s_node *nd);

#endif
