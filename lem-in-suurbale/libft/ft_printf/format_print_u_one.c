/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_print_u_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:22:41 by gstarvin          #+#    #+#             */
/*   Updated: 2019/11/21 14:02:02 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_structlist	count_num_u2(t_structlist *a, char b)
{
	if ((*a).precision > (*a).len_arg)
	{
		if ((b == 'x' || b == 'X' || b == 'p') && (*a).hash == 1)
			(*a).len_arg = (*a).precision + 2;
		else
			(*a).len_arg = (*a).precision;
	}
	else
	{
		if ((b == 'x' || b == 'X' || b == 'p') && (*a).hash == 1)
			(*a).len_arg += 2;
		if ((b == 'o') && (*a).hash == 1)
			(*a).len_arg++;
	}
	return (*a);
}

t_structlist	count_num_u1(t_structlist *a, char b)
{
	if ((*a).precision > (*a).len_arg)
	{
		if ((b == 'x' || b == 'X' || b == 'p') && (*a).hash == 1)
			(*a).len_arg = (*a).precision + 2;
		else
			(*a).len_arg = (*a).precision;
	}
	else
	{
		if ((b == 'x' || b == 'X' || b == 'p') && (*a).hash == 1)
			(*a).len_arg += 2;
		if ((b == 'o') && (*a).hash == 1)
			(*a).len_arg++;
	}
	return (*a);
}

int				count_num_u(t_structlist a, char b)
{
	if (a.width > a.precision)
	{
		if (a.width > a.len_arg)
		{
			if (a.hash == 1 && (b == 'x' || b == 'X' || b == 'p')
				&& (a.width - a.len_arg == 1))
				return (a.width + 1);
			return (a.width);
		}
		else
			a = count_num_u1(&a, b);
	}
	else
		a = count_num_u2(&a, b);
	return (a.len_arg);
}

void			ft_printer(unsigned long long int arg, char a, int fd)
{
	if (a == 'x' || a == 'X' || a == 'p')
		ft_printhex2(arg, a, fd);
	else if (a == 'o')
		ft_printoct(arg, fd);
	else
		ft_putnbr_long_u(arg, fd);
}

t_structlist	print_u_hash1(const char *str, int start, t_structlist *a)
{
	if ((*a).hash == 1)
	{
		if (str[start] == 'o')
		{
			write_prefix(a, 'o');
			(*a).len_arg++;
		}
		if (str[start] == 'x' || str[start] == 'p')
		{
			write_prefix(a, 'x');
			(*a).len_arg += 2;
		}
		if (str[start] == 'X')
		{
			write_prefix(a, 'X');
			(*a).len_arg += 2;
		}
	}
	return (*a);
}
