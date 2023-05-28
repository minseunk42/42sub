/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:39:19 by minseunk          #+#    #+#             */
/*   Updated: 2023/05/29 01:28:42 by minseunk         ###   ########.fr       */
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
	int				size;
}	t_stack;

void		init_st(t_stack st_arr[]);
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
int			sa(t_stack st_arr[]);
int			sb(t_stack st_arr[]);
int			ss(t_stack st_arr[]);
int			pa(t_stack st_arr[]);
int			pb(t_stack st_arr[]);
int			ra(t_stack st_arr[]);
int			rb(t_stack st_arr[]);
int			rr(t_stack st_arr[]);
int			rra(t_stack st_arr[]);
int			rrb(t_stack st_arr[]);
int			rrr(t_stack st_arr[]);
char		*get_next_line(int fd);
int			puterr(void);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			get_stsize(t_stack st);
char		*hard(char *answer, t_stack st_arr[]);
char		*ft_strjoin(char const *s1, char const *s2);
int			proc_cmd(char *cmd, t_stack st_arr[]);
int			proc_cmds(char *cmds, t_stack st_arr[]);
void		*ft_memcpy(void *dest, const void *src, size_t size);
void		*ft_calloc(size_t num, size_t size);
char		*opti(char *answer, t_stack st_arr[]);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ratorra(int i, int j, char *answer, int rracnt);
char		*opti_ra(char *answer, t_stack st_arr[]);
char		*opti(char *answer, t_stack st_arr[]);
char		*algo(char *answer, t_stack st_arr[]);
char		*atob(char *answer, t_stack st_arr[]);
char		*btoa(char *answer, t_stack st_arr[]);
int			get_maxidx(t_stack st_arr[]);
void		copy_st(t_stack from[], t_stack to[]);

# define STA 0
# define STB 1
# define NUM 0
# define ORDER 1
# define INTMAX 2147483647
# define INTMIN -2147483648
# define CPA "pa\n"
# define CPB "pb\n"
# define CSA "sa\n"
# define CSB "sb\n"
# define CSS "ss\n"
# define CRA "ra\n"
# define CRB "rb\n"
# define CRR "rr\n"
# define CRRA "rra\n"
# define CRRB "rrb\n"
# define CRRR "srrr\n"

#endif