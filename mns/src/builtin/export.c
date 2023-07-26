/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gylim <gylim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:52:38 by gylim             #+#    #+#             */
/*   Updated: 2023/07/26 15:12:17 by gylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "env_list.h"
#include "libft.h"
#include "minishell.h"

static int	is_valid_id(char *str)
{
	int	i;
	int	is_num_possible;

	is_num_possible = 0;
	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (!(str[i] == '_' || ft_isalnum(str[i])))
			return (0);
		if (!is_num_possible && ft_isdigit(str[i]))
			return (0);
		if (ft_isalpha(str[i]) || str[i] == '_')
			is_num_possible = 1;
		i++;
	}
	if (str[i] == '=' && i == 0)
		return (0);
	if (str[i] != '=')
		return (0);
	return (!ms_check_set(str[i + 1], WHITESPACE));
}

static int	ft_export_arg_error(const char *arg)
{
	ft_printf(2, "minishell: export: '%s': not a valid identifier\n", arg);
	return (EXIT_FAILURE);
}

static int	ft_export_pass(const char *arg)
{
	while (*arg)
	{
		if (*arg == '=')
			return (0);
		arg++;
	}
	return (1);
}

int	ft_export(char **argv)
{
	int				i;
	int				ret;
	int				argc;
	extern t_gdata	g_data;

	ret = 0;
	argc = get_argc(argv);
	if (argc == 1)
		return (ft_env(argv));
	i = 1;
	while (i < argc)
	{
		if (!is_valid_id(argv[i]))
		{
			if (!ft_export_pass(argv[i]))
				ret = ft_export_arg_error(argv[i]);
		}
		else
			env_export(g_data.env_list, argv[i]);
		i++;
	}
	return (ret);
}
