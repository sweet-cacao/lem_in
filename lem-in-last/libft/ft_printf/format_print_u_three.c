/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_print_u_three.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:22:47 by gstarvin          #+#    #+#             */
/*   Updated: 2019/11/21 14:02:02 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_structlist	print_u_hash3(const char *str, int start, t_structlist *a)
{
	if ((*a).hash == 1)
	{
		if (str[start] == 'o')
			(*a).len_arg++;
		if (str[start] == 'x' || str[start] == 'p')
			(*a).len_arg += 2;
		if (str[start] == 'X')
			(*a).len_arg += 2;
	}
	if ((*a).width > (*a).len_arg)
	{
		if ((*a).zero == 0)
			format_width((*a), (*a).len_arg);
		if ((*a).hash == 1)
			write_hash(str, start, (*a).fd);
		if ((*a).zero == 1)
			format_width((*a), (*a).len_arg);
	}
	return (*a);
}

t_structlist	print_u_setlenarg(unsigned long long int arg,
					const char *str, int start, t_structlist *a)
{
	if (str[start] == 'x' || str[start] == 'X' || str[start] == 'p')
		(*a).len_arg = count_hex(arg, str[start]);
	else if (str[start] == 'o')
		(*a).len_arg = count_oct(arg);
	else
		(*a).len_arg = count_length_u(arg);
	(*a).ilenarg = (*a).len_arg;
	return (*a);
}

t_structlist	print_u_no_min(const char *str, int start, t_structlist *a)
{
	if ((*a).isp == 1)
	{
		(*a) = print_u_isp2(str, start, a);
		(*a) = print_u_hash2(str, start, a);
	}
	if ((*a).isp == 0)
	{
		(*a) = print_u_hash3(str, start, a);
		if ((*a).width < (*a).len_arg)
		{
			if ((*a).hash == 1)
			{
				if (str[start] == 'o')
					write_prefix(a, 'o');
				if (str[start] == 'x' || str[start] == 'p')
					write_prefix(a, 'x');
				if (str[start] == 'X')
					write_prefix(a, 'X');
			}
		}
	}
	return (*a);
}

void			set_a(char *str, t_star *star, t_structlist *a, int *i)
{
	(*a) = zero_struct();
	(*a) = fill_struct((*a), i, str);
	(*a) = add_star((*star), (*a));
	(*a).plus = 0;
	(*a).space = 0;
}

void			print_u_check_min(unsigned long long int arg, const char *str,
													int start, t_structlist *a)
{
	if (arg == 0 && (*a).isp == 1 && (*a).precision == 0 && (*a).width != 0)
		(*a).width++;
	if ((*a).min == 1)
	{
		(*a) = print_u_hash1(str, start, a);
		(*a) = print_u_isp1(str, start, a);
		if (!(arg == 0 && (*a).isp == 1 &&
					(*a).precision == 0 && (*a).width != 0))
			ft_printer(arg, str[start], (*a).fd);
		format_width((*a), (*a).len_arg);
	}
	else
	{
		(*a) = print_u_no_min(str, start, a);
		if (!(arg == 0 && (*a).isp == 1 &&
				(*a).precision == 0 && (*a).width != 0))
			ft_printer(arg, str[start], (*a).fd);
	}
}
