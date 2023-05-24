/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:39:19 by minseunk          #+#    #+#             */
/*   Updated: 2023/05/23 21:26:07 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				val[2];
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tail;
}	t_stack;

void		init(t_stack st_arr[]);
int			set_sa(t_stack st_arr[], int num);
int			set_str(char *str, t_stack st_arr[]);
int			proc_av(char **av, t_stack st_arr[]);
int			free_sta(t_stack st_arr[]);
int			free_all(char **strs, t_stack st_arr[], char *cmd);
void		push_head(t_stack *st, int val[]);
void		push_tail(t_stack *st, int val[]);
int			*pop_head(t_stack *st);
int			*pop_tail(t_stack *st);
int			ft_printf(char *str, ...);
int			ft_isdigit(char c);
long long	ft_atol(const char *str);
size_t		ft_strlen(const char *str);
int			is_sorted(t_stack st_arr[]);
char		**ft_split(char const *s, char c);
int			free_strs(char **strs);
int			has_spa(char *str);
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
char		*get_next_line(int fd);
int 		puterr(void);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int 		get_stsize(t_stack st);
char		*hard_code(char *answer, t_stack st_arr[]);
char		*ft_strjoin(char const *s1, char const *s2);
int			proc_cmd(char *cmd, t_stack st_arr[]);

# define SA 0
# define SB 1
# define NUM 0
# define ORDER 1
# define INTMAX 2147483647
# define INTMIN -2147483648

#endif