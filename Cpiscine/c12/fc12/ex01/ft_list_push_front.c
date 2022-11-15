#include "ft_list.h"
#include <stdlib.h>

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
	
	new_n = ft_create_elem(data)
	*begin_list->next = new_n;
}
