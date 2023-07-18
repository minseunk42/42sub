/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:41:22 by gylim             #+#    #+#             */
/*   Updated: 2023/07/16 17:29:56 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <termios.h>

# define DEFAULT_PROMPT ("minishell$ ")
# define WHITESPACE ("\b\t\n\v\f\r ")

/* setup */
int	initial_setup(int argc, char *argv[], struct termios *old);

/* utils */
int get_argc(char **argv);
int	ms_check_set(char c, const char *set);


#endif /* MINISHELL_H */