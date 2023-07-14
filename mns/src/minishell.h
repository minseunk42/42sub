/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:41:22 by gylim             #+#    #+#             */
/*   Updated: 2023/07/13 19:32:09 by minseunk         ###   ########.fr       */
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
int	ms_check_set(char c, const char *set);


#endif /* MINISHELL_H */
