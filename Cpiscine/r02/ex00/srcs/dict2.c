/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:54:33 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/16 23:27:40 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../includes/num.h"

void	set_record(t_list **dict, char	*buf)
{
	char	**strs;
	int		i[2];
	char	*temp;
	char	*temp2;
	char	**pt2_tmp;

	strs = ft_split(buf, "\n");
	i[0] = -1;
	while (strs[++i[0]])
		strs[i[0]] = del_space(strs[i[0]]);
	i[0] = -1;
	while (strs[++i[0]])
	{
		pt2_tmp = ft_split(strs[i[0]], ":");
		temp = pt2_tmp[0];
		temp2 = _strstr_(strs[i[0]], ":");
		add_list(dict, temp, ++temp2);
		i[1] = 0;
		while (pt2_tmp[i[1]])
			free(pt2_tmp[i[1]++]);
		free(strs[i[0]]);
	}
	free(strs);
}

int	check_dict(char *num, t_list *dict)
{
	t_list	*temp;
	int		maxlen;

	if (!dict)
		return (-1);
	temp = dict;
	while (temp->next)
		temp = temp->next;
	maxlen = _strlen_(temp->key) + 3;
	if (_strlen_(num) >= maxlen)
		return (-1);
	return (0);
}

int	set_dict(t_list **dict, char *path, char *num)
{
	int		fd;
	int		ret;
	char	*buf;

	fd = open(path, O_RDONLY);
	buf = (char *)malloc(4096);
	ret = read(fd, buf, 4096);
	buf[ret] = 0;
	set_record(dict, buf);
	*dict = sort_insertion_list(*dict);
	free(buf);
	if (check_dict(num, *dict))
		return (-1);
	return (0);
}

int	read_num(char *num, t_list *dict, int size)
{
	int		unit;

	if (!(_strcmp_(num, "0")))
	{
		print_val("0", dict);
		write(1, "\n", 1);
		return (0);
	}
	unit = size / 3;
	if (size % 3 != 0)
	{
		proc_hund(num, dict, unit, size % 3);
		num = num + (size % 3);
	}
	unit--;
	while (unit >= 0)
	{
		proc_hund(num, dict, unit, 3);
		unit--;
		num = num + 3;
	}
	write(1, "\n", 1);
	return (0);
}

void	proc_hund(char *num, t_list *dict, int unit, int size)
{
	int	flag;

	flag = 0;
	if (size == 3)
	{
		if (num[0] != '0')
			print_h(num, dict, &flag);
		size--;
		num++;
	}
	if (size == 2)
	{
		if (num[0] != '0')
			print_t(num, dict, &flag);
		if (num[0] == '1')
		{
			print_unit(unit, dict, flag);
			return ;
		}
		size--;
		num++;
	}
	if (size == 1 && num[0] != '0')
		print_o(num, dict, &flag);
	print_unit(unit, dict, flag);
}
