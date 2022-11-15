/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:07:12 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/15 20:19:04 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct s_list
{
    struct s_list *next;
    char *key;
    char *val;

}t_list;

t_list  *create_list_with_data(char *key, char *val);
t_list *sort_insertion_list(t_list *dict);
void add_list_with_data(t_list* list, int index, char *key, char *val);
void _memcopy_(char *dest, const char *src, int size);
int	_strcmp_(char *s1, char *s2);
int _strlen_(const char *str);
int order_tbl(char *s1, char *s2);


t_list  *create_list_with_data(char *key, char *val)
{
    t_list *new_list = malloc(sizeof(t_list));
    new_list->next = NULL;
    new_list->key = (char *)malloc(sizeof(char) * (_strlen_(key) + 1));
    _memcopy_(new_list->key, key, _strlen_(key) + 1);
    new_list->val = (char *)malloc(sizeof(char) * (_strlen_(val) + 1));
    _memcopy_(new_list->val, val, _strlen_(val) + 1);
    return new_list;
}

void add_list_with_data(t_list* dict, int index, char *key, char *val)
{
    int i ;

    i = 1;
    t_list *iter;

    iter = dict->next;
    while (i <index && iter)
    {
        i++;
        iter = iter->next;
    }
    t_list *add = create_list_with_data(key, val);
    if (index==0)
    {
        add->next=dict->next;
        dict->next = add;
    }
    else
    {
        add->next=iter->next;
        iter->next = add;
    }
}

t_list *sort_insertion_list(t_list *head)
{
    t_list *new_list;
    t_list *curr;
    t_list *prev;
    t_list *nextN;

    new_list = create_list_with_data("0","0");
    prev = new_list;
    curr = head;
    while (curr)
    {
        nextN = curr->next;
        if (_strcmp_(prev->key, curr->key) >= 0)
            prev = new_list;
        while (prev->next && order_tbl(prev->next->key, curr->key) < 0)
            prev = prev->next;
        curr->next = prev->next;
        prev->next = curr;
        curr = nextN;
    }
    return new_list->next;
}

int order_tbl(char *s1, char *s2)
{
    if (_strlen_(s1) > _strlen_(s2))
        return 1;
    else if (_strlen_(s1) < _strlen_(s2))
        return -1;
    return (_strcmp_(s1, s2));
}

void _memcopy_(char *dest, const char *src, int size)
{
    while (size--)
        *dest++ = *src++;
    dest[size] = '\0';
}

int	_strcmp_(char *s1, char *s2)
{
	while ((*s1 != '\0') && (*s2 != '\0'))
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int _strlen_(const char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int	set_pram(int ac, char **path, char **num, char **av)
{
	if (ac < 2 || ac > 3)
		return (-1);
	if (ac == 2)
	{
		*path = "numbers.dict";
		*num = av[1];
	}
	if (ac == 3)
	{
		*path = av[1];
		*num = av[2];
	}
//	if (check_num(*num))
//		return (-1);
	return (0);
}

void put_str(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	print_unit(int unit, t_list *dict, int flag)
{
	int		i;
	t_list	*temp;
	
	if (!unit || !flag)
		return ;
	temp = dict;
	while (_strcmp_(temp->key, "1000"))
		temp = temp->next;
	i = 0;
	while (++i < unit)
		temp = temp->next;
	put_str(temp->val);
	write(1, " ", 1);
}

void	print_val(char *ref, t_list *dict)
{
	t_list	*temp;

	temp = dict;
	while (temp->next && _strcmp_(temp->key, ref))
		temp = temp->next;
	put_str(temp->val);
	write(1, " ", 1);
}

void	print_h(char *num, t_list *dict, int *flag)
{
	char	ref[2];
	
	*flag = 1;
	ref[0] = num[0];
	ref[1] = 0;
	print_val(ref, dict);
	print_val("100", dict);
}

void	print_t(char *num, t_list *dict, int *flag)
{
	char	ref[3];

	*flag = 1;
	if (num[0] == '1')
	{
		ref[0] = num[0];
		ref[1] = num[1];
		ref[2] = 0;
		print_val(ref, dict);
		return ;
	}
	ref[0] = num[0];
	ref[1] = '0';
	ref[2] = 0;
	print_val(ref, dict);
}

void	print_o(char *num, t_list *dict, int *flag)
{
	char	ref[2];
	
	*flag = 1;
	ref[0] = num[0];
	ref[1] = 0;
	print_val(ref, dict);
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

int	read_num(char *num, t_list *dict, int size)
{
	int		unit;

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
	return (0);
}
/*
int	set_dict(t_list **dict, char *path)
{
	int		fd;
	int		ret;
	char	*buf;

	fd = open(path, O_RDONLY);
	buf = (char *)malloc(4096);
	ret = read(fd, buf, 4096);
	buf[ret] = 0;
	

	
	close(fd);
}
*/

int	main(int ac, char **av)
{
	char	*path;
	char	*num;
	t_list	*dict;
	int		index;

	if (set_pram(ac, &path, &num, av))
	{	
		write(2, "Error\n", 6);
		return (-1);
	}
	/*if (set_dict(&dict, path))
	{
		write(2, "Dict Error\n", 11);
		return (-1);
	}*/
	dict = create_list_with_data("0","zero");
	index = 0;
    add_list_with_data(dict, index, "1", "one");
    index++;
	add_list_with_data(dict, index, "2", "two");
    index++;
	add_list_with_data(dict, index, "3", "three");
    index++;
	add_list_with_data(dict, index, "4", "four");
    index++;
	add_list_with_data(dict, index, "5", "five");
    index++;
	add_list_with_data(dict, index, "6", "six");
    index++;
	add_list_with_data(dict, index, "7", "seven");
    index++;
	add_list_with_data(dict, index, "8", "eight");
    index++;
	add_list_with_data(dict, index, "9", "nine");
    index++;
	add_list_with_data(dict, index, "60", "sixty");
    index++;
	add_list_with_data(dict, index, "70", "seventy");
    index++;
	add_list_with_data(dict, index, "80", "eighty");
    index++;
	add_list_with_data(dict, index, "90", "ninty");
	index++;
	add_list_with_data(dict, index, "100", "hundred");
    index++;
	add_list_with_data(dict, index, "1000", "th");
    index++;
	add_list_with_data(dict, index, "1000000", "mil");
	index++;
	add_list_with_data(dict, index, "1000000000", "bil");
	index++;
	add_list_with_data(dict, index, "1000000000000", "tri");
	index++;
	add_list_with_data(dict, index, "1000000000000000", "qu");
	index++;
	add_list_with_data(dict, index, "10", "ten");
    index++;
	add_list_with_data(dict, index, "11", "eleven");
    index++;
	add_list_with_data(dict, index, "12", "twelve");
    index++;
	add_list_with_data(dict, index, "13", "thirteen");
    index++;
	add_list_with_data(dict, index, "14", "fourteen");
    index++;
	add_list_with_data(dict, index, "15", "fifteen");
    index++;
	add_list_with_data(dict, index, "16", "sixteen");
    index++;
	add_list_with_data(dict, index, "17", "seventeen");
    index++;
	add_list_with_data(dict, index, "18", "eighteen");
    index++;
	add_list_with_data(dict, index, "19", "nineteen");
    index++;
	add_list_with_data(dict, index, "20", "twenty");
    index++;
	add_list_with_data(dict, index, "30", "thoty");
    index++;
	add_list_with_data(dict, index, "40", "fourty");
    index++;
	add_list_with_data(dict, index, "50", "fifty");
	sort_insertion_list(dict);

	if (read_num(num, dict,_strlen_(num)))
	{
		write(2, "Dict Error\n", 11);
		return (-1);
	}
	return (0);	
}
