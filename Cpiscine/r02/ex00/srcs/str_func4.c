/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   str_func4.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: minseunk <minseunk@student.42seoul.>	   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/10/16 18:52:13 by minseunk		  #+#	#+#			 */
/*   Updated: 2022/10/16 23:11:04 by minseunk         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/num.h"

void	blue_flag_white_flag(char *X, char *Y, int flag)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (X[i] != '\0')
	{
		if ((X[i] >= 33 && X[i] <= 126))
			flag = 1;
		if (flag == 1 && (X[i] != ' '))
			Y[k++] = X[i];
		if (flag == 1 && X[i] == ' ')
		{
			Y[k++] = X[i];
			flag = 2;
		}
		i++;
		if (flag == 2)
			continue ;
	}
	Y[k] = '\0';
}

void	delete_side_space_between_colon(char *X)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (X[i])
	{
		j = 0;
		if (X[i] == ' ')
		{
			if (count == 2)
				break ;
			count++;
			j = i;
			while (X[j])
			{
				X[j] = X[j + 1];
				j++;
			}
		}
		i++;
	}
}

char	*del_space(char *s)
{
	char	*str;
	int		i;
	int		k;
	int		flag;

	i = 0;
	k = 0;
	flag = 0;
	str = (char *)malloc(_strlen_(s));
	blue_flag_white_flag(s, str, 0);
	delete_side_space_between_colon(str);
	return (str);
}
