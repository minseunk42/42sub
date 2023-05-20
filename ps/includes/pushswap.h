/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:39:19 by minseunk          #+#    #+#             */
/*   Updated: 2023/05/19 20:06:49 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	unsigned int	order;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tail;
}	t_stack;

int			free_sta(t_stack st_arr[]);
void		push_head(t_stack *st, int num);
void		push_tail(t_stack *st, int num);
int			pop_head(t_stack *st);
int			pop_tail(t_stack *st);
int			ft_printf(char *str, ...);
int			ft_isdigit(char c);
long long	ft_atol(const char *str);
size_t		ft_strlen(const char *str);
int			is_sorted(t_stack st_arr[]);
int 		sa(t_stack st_arr[]);
int 		sb(t_stack st_arr[]);
int 		ss(t_stack st_arr[]);
int 		pa(t_stack st_arr[]);
int 		pb(t_stack st_arr[]);
int 		ra(t_stack st_arr[]);
int 		rb(t_stack st_arr[]);
int 		rr(t_stack st_arr[]);
int 		rra(t_stack st_arr[]);
int 		rrb(t_stack st_arr[]);
int 		rrr(t_stack st_arr[]);

int 		puterr(void);

# define SA 0
# define SB 1
# define INTMAX 2147483647
# define INTMIN -2147483648

#endif