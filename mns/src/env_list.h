/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:26:33 by gylim             #+#    #+#             */
/*   Updated: 2023/07/14 18:37:51 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_LIST_H
# define ENV_LIST_H

# ifndef ENV_TYPE
#  define ENV_TYPE
typedef struct s_env_list	t_env_list;
# endif

typedef struct s_env_node
{
	struct s_env_node	*next;
	char				*key;
	char				*value;
}	t_env_node;

typedef struct s_env_list
{
	int					size;
	struct s_env_node	*front;
	struct s_env_node	*rear;
}	t_env_list;

t_env_node	*env_new_node(const char *key, const char *value);
char		*env_split_key(const char *str);
char		*env_split_value(const char *str);
t_env_node	*env_new_node_str(const char *str);
int			env_add_rear_node_to_list(t_env_list *list, t_env_node *node);
t_env_list	*env_new_list(void);
int			env_print_list(const t_env_list *list);
void		env_unset(t_env_list *list, const char *key);
int			env_export(t_env_list *list, char *str);
char		*env_get_value_or_null(t_env_list *list, const char *key);

#endif /* ENV_LIST_H */
