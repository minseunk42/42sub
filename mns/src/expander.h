/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:33:03 by gylim             #+#    #+#             */
/*   Updated: 2023/07/14 16:46:59 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# ifndef TOKEN_TYPE
#  define TOKEN_TYPE

typedef struct s_token	t_token;

# endif

int expander(t_env_list *list, t_token *tok);

#endif /* EXPANDER_H */