/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:21:35 by gstarvin          #+#    #+#             */
/*   Updated: 2019/11/23 18:27:06 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	min_case(t_structlist a)
{
	if (a.min == 1)
	{
		ft_write_my(0, a.fd, '%');
		while (a.width > 1)
		{
			if (a.zero == 1)
				ft_write_my(0, a.fd, '0');
			else
				ft_write_my(0, a.fd, ' ');
			a.width--;
		}
	}
	else
	{
		while (a.width > 1)
		{
			if (a.zero == 1)
				ft_write_my(0, a.fd, '0');
			else
				ft_write_my(0, a.fd, ' ');
			a.width--;
		}
		ft_write_my(0, a.fd, '%');
	}
}

int		format_percent(char b, char *str, int start, t_parse p)
{
	t_structlist	a;
	int				i;
	int				num;

	i = start;
	a = zero_struct();
	a.fd = p.fd;
	a = fill_struct(a, &i, str);
	if (a.width > 1)
		num = a.width;
	else
		num = 1;
	if (str[i] == b)
	{
		min_case(a);
		return (num);
	}
	return (0);
}
