/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:21:26 by gstarvin          #+#    #+#             */
/*   Updated: 2019/11/21 12:18:09 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		count_length(long long int n)
{
	int res;

	res = 0;
	if (n == 0)
		return (1);
	if (n == (-9223372036854775807 - 1))
		return (19);
	if (n < 0)
		n *= (-1);
	while (n > 0)
	{
		n = n / 10;
		res++;
	}
	return (res);
}

void	set_func(char chr, t_structlist a)
{
	if (chr == '-')
		a.min = 1;
	if (chr == '#')
		a.hash = 1;
	if (chr == '+')
		a.plus = 1;
	if (chr == '0')
		a.zero = 1;
	if (chr == ' ')
		a.space = 1;
}
