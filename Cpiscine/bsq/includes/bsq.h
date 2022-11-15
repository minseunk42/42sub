/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:36:31 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/20 12:14:58 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <libgen.h>
# include <stdio.h>
# define X 0
# define Y 1
# define MAX 2
# define BOX 2
# define EMPTY 0
# define BLOCK 1

/*	dp1.c	*/
int		get_min(int a, int b, int c);
int		get_max(int **map, int row, int col);
int		*get_maxindex(int **map, int row, int col, int max);
int		pos_check(int i, int j, int *mi);
int		**sol_map(int **map, int row, int col);

/*	dp2.c	*/
void	print_answer(char **table, int row, int col);
char	**mk_answer(int **map, int *pos, int *mi, char *mark);
void	print_map(int **map, int row, int col, char *mark);
void	free_arr2(void **arr, int row);

/*	validate.c */
int		check_in(char *cond, char *buf, int col);
int		check_val(char *buf, char *cond, int col);

/* setmap.c */
int		*int_arr(char *buf, int line_len, char *cond_char);
char	*check_cond(char *argv, int line_count, int line_count2);
int		overlap_n_count(char *argv, int count);
int		first_line_len(char *argv);
int		into_map(int fd, char *argv, int **input_int);

/* setmap2.c */
int		total_line(char *argv, int line, int first_line);
int		get_first_row(char *argv);
int		ft_line_len(char *argv, int first_line);

/* sub.c */
int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		ft_strlen_check_val(char *str);
void	free_2(void *a, void *b);
#endif
