/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:54:58 by minseunk          #+#    #+#             */
/*   Updated: 2022/10/13 16:05:44 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	swap2(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	void	(*ptrswap)(char **, char **);
	int		i;
	int		j;

	i = 0;
	ptrswap = swap2;
	while (tab[i])
	{
		j = 1;
		while (tab[j])
		{
			if (cmp(tab[j - 1], tab[j]) > 0)
				ptrswap(&tab[j - 1], &tab[j]);
			j++;
		}
		i++;
	}
}
