/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:46:53 by minseunk          #+#    #+#             */
/*   Updated: 2023/06/25 00:52:34 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*ft_strjoin1(char *s1, char *s2);
char	*ft_strchr1(const char *str, int c);
size_t	ft_strlen1(const char *str);
void	*ft_memmove1(void *dest, void *src, size_t size);
char	*get_next_line(int fd);

# define BUFFER_SIZE 4096

#endif