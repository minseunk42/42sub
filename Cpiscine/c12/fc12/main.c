#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

t_list	*ft_create_elem(void *data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	node->data = data;
	node->next = 0;
	return (node);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_n;
	t_list	*head;

	head = *begin_list;
	new_n = ft_create_elem(data);
	new_n->next = head;
	*begin_list = new_n;
}

int	ft_list_size(t_list *begin_list)
{
	int		cnt;
	t_list	*temp;

	cnt = 0;
	temp = begin_list;
	while (temp)
	{
		cnt++;
		temp = temp->next;
	}
	return (cnt);
}

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*temp;

	temp = begin_list;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*temp;
	t_list	*new_n;
	
	temp = *begin_list;
	while (temp->next)
		temp = temp->next;
	new_n = ft_create_elem(data);
	temp->next = new_n;
}

int main()
{
	t_list	*m_list;
	
	m_list = ft_create_elem("1");
	ft_list_push_front(&m_list, "2");
	ft_list_push_front(&m_list, "3");
	ft_list_push_front(&m_list, "4");
	ft_list_push_front(&m_list, "3");
	ft_list_push_front(&m_list, "q");
	ft_list_push_back(&m_list, "a");
	ft_list_push_back(&m_list, "b");
	printf("%s",ft_list_last(m_list)->data);

}
