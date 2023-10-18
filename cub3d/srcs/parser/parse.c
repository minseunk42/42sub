/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhyl <changhyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:23:05 by changhyl          #+#    #+#             */
/*   Updated: 2023/10/14 17:19:02 by changhyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "parse.h"

t_data	*run_parse(int argc, char *argv[])
{
	t_data	*data;

	if (!(check_arg(argc, argv)))
		exit(1);
	data = get_data(argv[1]);
	if (!data)
		print_err_exit("Parse Error\n");
	return (data);
}
