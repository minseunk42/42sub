/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:54:33 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/16 19:08:57 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*set_record(t_list **dict, char	*buf, char *over, int flag)
{
	char	**strs;
	int		i;
	char	*temp;
	char	*temp2;

	strs = ft_split(buf, "\n");
	i = -1;
	while (strs[++i])
		strs[i] = del_space(strs[i]);
	if (flag)
	{
		strs[0] = _strjoin_(over, strs[0]);
		over = strs[--i];
	}
	i = -1;
	while (strs[(++i + flag)])
	{
		temp = ft_split(strs[i], ":")[0];
		temp2 = _strstr_(strs[i], ":");
		add_list(dict, temp, ++temp2);
	}
	return (over);
}

int	set_dict(t_list **dict, char *path)
{
	int		fd;
	int		ret;
	char	*buf;
	int		flag;
	char	*over;

	flag = 1;
	fd = open(path, O_RDONLY);
	buf = (char *)malloc(1024);
	over = (char *)malloc(1024);
	over[0] = 0;
	while (flag)
	{
		ret = read(fd, buf, 1024);
		buf[ret] = 0;
		over = set_record(dict, buf, over, flag);
		if (ret < 1024)
			flag = 0;
	}
	free(over);
	free(buf);
	return (0);
}

int	read_num(char *num, t_list *dict, int size)
{
	char	**nums;
	char	*nb;
	int		size;
	int		i;

	size = _strlen_(num);
	if (size % 3 == 0)
		nums = (char **)malloc(sizeof(char *) * (size + 1));
	else
		nums = (char **)malloc(sizeof(char *) * (size + 2));
	i = 0;
	while (size > 0)
	{
		nb[0] = num[size];
	}
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
