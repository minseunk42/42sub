/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:34:47 by gylim             #+#    #+#             */
/*   Updated: 2023/07/26 15:48:41 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "executor.h"
#include "libft.h"
#include "minishell.h"

static void	heredoc_fill_dir(char *filename)
{
	filename[0] = '.';
	filename[1] = '/';
	filename[2] = 't';
	filename[3] = 'e';
	filename[4] = 'm';
	filename[5] = 'p';
	filename[6] = '/';
}

static int	heredoc_temp_file_name(char *filename, int idx)
{
	int		i;
	int		j;
	char	*num;

	ft_memset(filename, 0, sizeof(char) * 256);
	heredoc_fill_dir(filename);
	i = 7;
	num = ft_itoa(idx);
	if (num == NULL)
	{
		perror("minishell: heredoc");
		return (-1);
	}
	j = 0;
	while (num[j] != '\0')
	{
		filename[i] = num[j];
		i++;
		j++;
	}
	filename[i] = '\0';
	free(num);
	return (0);
}

int	heredoc_open_file(int idx)
{
	int		fd;
	char	filename[256];

	if (heredoc_temp_file_name(filename, idx) == -1)
		exit(EXIT_FAILURE);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("minishell: heredoc");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int	heredoc_open_file2(int idx)
{
	int		fd;
	char	filename[256];

	if (heredoc_temp_file_name(filename, idx) == -1)
		exit(EXIT_FAILURE);
	fd = open(filename, O_RDONLY, 0644);
	if (fd < 0)
	{
		perror("minishell: heredoc");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
