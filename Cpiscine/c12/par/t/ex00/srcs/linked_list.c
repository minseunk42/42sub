
#include <stdlib.h>


typedef struct s_list
{
    struct s_list *next;
    char *key;
    char *value;
}t_list;

t_list  *create_list_with_data(char *key, char *value);
t_list *sort_insertion_list(t_list *head);
void add_list_with_data(t_list* list, int index, char *key, char *value);
void _memcopy_(char *dest, const char *src, int size);
int	_strcmp_(char *s1, char *s2);
int _strlen_(const char *str);
int order_tbl(const char *s1, const char *s2);


t_list  *create_list_with_data(char *key, char *value)
{
    t_list *new_list = malloc(sizeof(t_list));
    new_list->next = NULL;
    new_list->key = (char *)malloc(sizeof(char) * (_strlen_(key) + 1));
    _memcopy_(new_list->key, key, _strlen_(key) + 1);
    new_list->value = (char *)malloc(sizeof(char) * (_strlen_(value) + 1));
    _memcopy_(new_list->value, value, _strlen_(value) + 1);
    return new_list;
}

void add_list_with_data(t_list* head, int index, char *key, char *value)
{
    int i ;
    
    i = 1;
    t_list *iter;
    
    iter = head->next;
    while (i <index && iter) 
    {
        i++;
        iter = iter->next;
    }
    t_list *add = create_list_with_data(key, value);
    if (index==0) 
    {
        add->next=head->next;
        head->next = add;
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

int order_tbl(const char *s1, const char *s2)
{
    if _strlen_(s1) > _strlen_(s2)
        return 1;
    else if _strlen_(s1) < _strlen_(s2)
        return -1;
    return (_strcmp_(prev->next->key, curr->key));
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

/**
 * struct t_list *new_list= create_list();
 */

#include <stdio.h>
int main()
{
    int index;

    
    t_list *head= create_list_with_data("key", "value");
    index = 0;
    add_list_with_data(head, index, "key2", "value2");
    index++;
    add_list_with_data(head, index, "key1", "value1");
    head = sort_insertion_list(head);
    
}