/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:36:15 by gylim             #+#    #+#             */
/*   Updated: 2023/07/17 19:49:32 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

#define FT_S_ISDIR(m)      (((m) & S_IFMT) == S_IFDIR)     /* directory */

int builtin_exit_or_return(int exit_status);

#endif /* BUILTIN_H */