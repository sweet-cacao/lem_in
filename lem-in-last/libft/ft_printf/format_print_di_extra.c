/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_print_di_extra.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:22:00 by gstarvin          #+#    #+#             */
/*   Updated: 2019/11/19 14:36:53 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_structlist	format_di_with_perecision(long long int arg, t_structlist *a)
{
	(*a).ilenarg = (*a).len_arg;
	if (((*a).plus == 1 || arg < 0) && (*a).isp == 0)
		(*a).len_arg++;
	if ((*a).isp == 1)
	{
		if (((*a).plus == 1 || arg < 0) && (*a).precision <= (*a).len_arg)
			(*a).len_arg++;
		if ((*a).precision > (*a).len_arg)
		{
			(*a).len_arg = (*a).precision;
			if ((*a).plus == 1 || arg < 0)
				(*a).len_arg++;
		}
		format_width((*a), (*a).len_arg);
		(*a) = format_choose_sign(arg, (*a));
		while ((*a).ilenarg < (*a).precision)
		{
			ft_write_my(0, (*a).fd, '0');
			(*a).ilenarg++;
		}
	}
	return (*a);
}

void			format_di_without_precision(long long int arg, t_structlist *a)
{
	if ((*a).isp == 0)
	{
		if ((*a).zero == 1)
		{
			(*a) = format_choose_sign(arg, (*a));
			if (arg < 0 || (*a).plus == 1)
				(*a).len_arg--;
		}
		format_width((*a), (*a).len_arg);
		if ((*a).zero == 0)
			(*a) = format_choose_sign(arg, (*a));
	}
	if (arg < 0 && arg != (-9223372036854775807 - 1))
		arg *= -1;
	if (!(arg == 0 && (*a).isp == 1 && (*a).precision == 0 && (*a).width != 0))
		ft_putnbr_long(arg, (*a).fd);
}

int				format_di_conditions(long long int arg, t_structlist *a)
{
	int num;

	(*a).len_arg = count_length(arg);
	num = count_num(arg, (*a));
	if (arg == 0 && (*a).isp == 1 && (*a).precision == 0 && (*a).width != 0)
		(*a).width++;
	if ((*a).space == 1 && arg >= 0)
	{
		ft_write_my(0, (*a).fd, ' ');
		(*a).width--;
	}
	if ((*a).min == 1)
		format_di_min(arg, a);
	else
	{
		(*a) = format_di_with_perecision(arg, a);
		format_di_without_precision(arg, a);
	}
	return (num);
}

int				format_di_for_zero(long long int arg, const char *str,
								int start, t_structlist *a)
{
	if (str[start] == 'd' || str[start] == 'i')
	{
		(*a) = format_choose_sign(arg, (*a));
		if ((*a).plus == 1)
			return (1);
	}
	if ((*a).hash == 1 && str[start] == 'o')
	{
		ft_write_my(0, (*a).fd, '0');
		return (1);
	}
	return (-2);
}

void			format_di_extra(const char *str, t_structlist *a, int *i)
{
	if ((*a).isp == 1)
		(*a).zero = 0;
	while (str[(*i)] == 'h' || str[(*i)] == 'l')
		(*i)++;
}
