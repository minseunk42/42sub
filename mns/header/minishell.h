/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:41:22 by gylim             #+#    #+#             */
/*   Updated: 2023/07/26 18:57:59 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <termios.h>
# include <sys/wait.h>

# define DEFAULT_PROMPT ("minishell$ ")
# define WHITESPACE ("\b\t\n\v\f\r ")

typedef struct s_global_data
{
	struct s_env_list	*env_list;
	struct s_token		*curtoken;
	long long			last_exit_status;
	int					heredoc_idx;
	int					heredoc_cnt;
	char				**internal_envp;
}	t_gdata;

extern t_gdata	g_data;

/* setup */
void	shell_setup(struct termios *old);

/* utils */
void	destroy_arr(char **arr);
int		get_argc(char **argv);
int		ms_check_set(char c, const char *set);
int		is_same_string(const char *s1, const char *s2);

#endif /* MINISHELL_H */
