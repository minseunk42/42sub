/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:44:02 by minseunk          #+#    #+#             */
/*   Updated: 2023/05/25 17:06:16 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define FT_BOOLEAN_H

# include <unistd.h>

typedef int	t_bool;

# define EVEN(nbr) ((nbr) % (2)) == (0)
# define TRUE 1
# define FALSE 0
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"
# define SUCCESS 0
#endif
