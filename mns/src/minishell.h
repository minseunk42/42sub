/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:41:22 by gylim             #+#    #+#             */
/*   Updated: 2023/07/19 18:37:35 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <termios.h>

# define DEFAULT_PROMPT ("minishell$ ")
# define WHITESPACE ("\b\t\n\v\f\r ")

typedef struct s_global_data
{
	struct s_env_list	*env_list;
	long long			last_exit_status;
}	t_gdata;

/* setup */
int	initial_setup(int argc, char *argv[], struct termios *old);

/* utils */
int get_argc(char **argv);
int	ms_check_set(char c, const char *set);


#endif /* MINISHELL_H */
