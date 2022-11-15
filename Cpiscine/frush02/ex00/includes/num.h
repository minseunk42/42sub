/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dummy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:07:02 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/16 19:24:37 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUM_H
# define NUM_H

typedef struct s_list
{
	struct s_list	*next;
	char			*key;
	char			*value;
}	t_list;

void	print_o(char *num, t_list *dict);
void	print_t(char *num, t_list *dict);
void	print_h(char *num, t_list *dict);

/* dict.c */
t_list	*create_elem(char *key, char *val);
t_list	*sort_insertion_list(t_list *head);
void	add_list(t_list **dict, char *key, char *val);
int		order_tbl(char *s1, char *s2);
void	_memcopy_(char *dest, const char *src, int size);

/* dict2.c */
char	*set_record(t_list **dict, char	*buf, char *over, int flag);
int		set_dict(t_list **dict, char *path);
int		read_num(char *num, t_list *dict, int size);
void	proc_hund(char *num, t_list *dict, int unit, int size);

/* free.c*/
void	rm_all_list(t_list *head);

/*printout.c*/
void	print_unit(int unit, t_list *dict, int flag);
void	print_val(char *ref, t_list *dict);
void	print_o(char *num, t_list *dict);
void	print_t(char *num, t_list *dict);
void	print_h(char *num, t_list *dict);

/* str_func.c*/
int		_strcmp_(char *s1, char *s2);
int		_strlen_(const char *str);
void	_putstr_(char *str);
int		check_num(char *num);

/* str_func2.c*/
int		check_sep(char c, char *charset);
int		get_strscnt(char *str, char *charset);
char	*mkstr(char *str, char *charset);
char	**ft_split(char *str, char *charset);
/* str_func3.c*/
char	*_strstr_(char *str, char *to_find);
char	*_strcat_(char *dest, char *src);
char	*_strdup_(char *src);
char	*_strjoin_(char *str1, char *str2);
/* str_func4.c*/
void	blue_flag_white_flag(char *X, char *Y, int i, int k, int flag);
void	delete_side_space_between_colon(char *X);
char	*del_space(char *s);
#endif
