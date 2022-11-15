/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dummy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:07:02 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/15 15:25:22 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list
{
    struct s_list *next;
    char *key;
    char *value;
}t_list;

int	set_dict(char ***dict, char *num, char *path);
int	set_pram(int ac, char **av, char **path, char **num);
int check_num(char *num); // 입력받은 숫자 유효성 검사해서 정수형 아닐시 1리턴 맞으면 0리턴
int	read_num(char *num, char **dict);
void	print_o(char *num, t_list *dict);
void	print_t(char *num, t_list *dict);
void	print_h(char *num, t_list *dict);
void	print_val(char *ref, t_list *dict);
