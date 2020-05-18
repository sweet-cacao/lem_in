/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_print_di.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:21:51 by gstarvin          #+#    #+#             */
/*   Updated: 2019/11/21 12:18:09 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_structlist	format_choose_sign(long long int arg, t_structlist a)
{
	if (arg < 0)
	{
		ft_write_my(0, a.fd, '-');
		a.len_arg++;
	}
	if (arg >= 0 && a.plus == 1)
	{
		ft_write_my(0, a.fd, '+');
		a.len_arg++;
	}
	return (a);
}

int				count_num(long long int arg, t_structlist a)
{
	int len_arg;

	len_arg = count_length(arg);
	if (a.width > a.precision && a.isp == 1 && a.width > len_arg)
		return (a.width);
	else
	{
		if (a.width > len_arg && len_arg > a.precision)
			return (a.width);
		if (a.precision > len_arg)
			len_arg = a.precision;
		if (a.plus == 1 || arg < 0)
			len_arg++;
		if (a.space == 1 && arg >= 0)
			len_arg++;
	}
	return (len_arg);
}

void			format_di_min(long long int arg, t_structlist *a)
{
	(*a).ilenarg = (*a).len_arg;
	(*a) = format_choose_sign(arg, (*a));
	if ((*a).isp == 1)
	{
		if ((*a).precision > (*a).ilenarg)
		{
			while ((*a).ilenarg < (*a).precision)
			{
				ft_write_my(0, (*a).fd, '0');
				(*a).ilenarg++;
				(*a).len_arg++;
			}
		}
	}
	if (arg < 0 && arg != (-9223372036854775807 - 1))
		arg *= -1;
	if (!(arg == 0 && (*a).isp == 1 && (*a).precision == 0 && (*a).width != 0))
		ft_putnbr_long(arg, (*a).fd);
	format_width((*a), (*a).len_arg);
}

int				format_print_di(long long int arg, char *str,
		t_parse p)
{
	t_structlist	a;
	int				i;
	int				num;

	i = p.i;
	a = zero_struct();
	a.fd = p.fd;
	a = fill_struct(a, &i, str);
	a = add_star(p.star, a);
	format_di_extra(str, &a, &i);
	p.i = i;
	if (arg == 0)
	{
		if (a.isp == 1 && a.precision == 0 && a.width == 0)
			return (format_di_for_zero(arg, str, p.i, &a));
		a.hash = 0;
	}
	if (is_dioux(str[i]))
	{
		num = format_di_conditions(arg, &a);
		return (num);
	}
	return (0);
}
