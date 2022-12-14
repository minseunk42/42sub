/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseunk <minseunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:04:06 by minseunk          #+#    #+#             */
/*   Updated: 2022/11/11 19:20:02 by minseunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	return (('0' <= c && c <= '9') || \
			('a' <= c && c <= 'z') || \
			('A' <= c && c <= 'Z'));
}
