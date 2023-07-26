/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:33:03 by gylim             #+#    #+#             */
/*   Updated: 2023/07/15 18:56:11 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# ifndef TOKEN_TYPE
#  define TOKEN_TYPE

typedef struct s_token		t_token;

# endif

# ifndef ENV_TYPE
#  define ENV_TYPE

typedef struct s_env_list	t_env_list;

# endif

# define EXPANDER_CHAR_SET ("$\b\t\n\v\f\r ")

char	*concat_words(char **words);
void	destroy_words(char **words);
char	*expand(t_env_list *list, t_token *tok);
int		expand_exit_status(char **words, int idx, int exit_status);
int		expander(t_env_list *list, t_token *tok);
char	*get_word(char **str);
int		get_word_cnt(const char *str);

#endif /* EXPANDER_H */