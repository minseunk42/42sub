/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:36:15 by gylim             #+#    #+#             */
/*   Updated: 2023/07/25 17:43:23 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# ifndef TREE_TYPE
#  define TREE_TYPE

typedef struct s_astree			t_astree;
typedef enum e_tree_type		t_atype;
typedef const struct s_astree	t_ctree;
typedef struct s_cmd			t_cmd;

# endif

typedef enum e_builtin
{
	BUILTIN_CD,
	BUILTIN_ECHO,
	BUILTIN_ENV,
	BUILTIN_EXIT,
	BUILTIN_EXPORT,
	BUILTIN_PWD,
	BUILTIN_UNSET,
	BUILTIN_ERR = -1
}	t_builtin;

int	builtin_check(const char *cmd);
int	builtin_exit_or_return(int exit_status);
int	builtin_run(const t_cmd *cmd);
int	ft_cd(char **argv);
int	ft_echo(char **argv);
int	ft_env(char **argv);
int	ft_exit(char **argv);
int	ft_export(char **argv);
int	ft_pwd(char **argv);
int	ft_unset(char **argv);

#endif /* BUILTIN_H */
