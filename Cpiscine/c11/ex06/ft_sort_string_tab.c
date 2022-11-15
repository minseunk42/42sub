/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 08:56:39 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/12 08:57:45 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

void	swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_string_tab(char **tab)
{
	int		(*ptrcmp)(char *, char *);
	void	(*ptrswap)(char **, char **);
	int		i;
	int		j;

	i = 0;
	ptrcmp = my_strcmp;
	ptrswap = swap;
	while (tab[i])
	{
		j = 1;
		while (tab[j])
		{
			if (ptrcmp(tab[j - 1], tab[j]) > 0)
				ptrswap(&tab[j - 1], &tab[j]);
			j++;
		}
		i++;
	}
}
