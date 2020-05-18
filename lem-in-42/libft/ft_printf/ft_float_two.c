/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:28:02 by gstarvin          #+#    #+#             */
/*   Updated: 2019/11/19 14:28:02 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void					f_is_min(long double arg, t_structlist *a)
{
	(*a).ilenarg = (*a).len_arg;
	(*a) = format_choose_sign_f(arg, (*a));
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
	if (arg < 0)
		arg *= -1;
	if ((*a).isp == 1)
		ft_float(arg, (*a));
	else
	{
		(*a).precision = 6;
		ft_float(arg, (*a));
	}
	format_width((*a), (*a).len_arg);
}

t_structlist			no_min_isp(long double arg, t_structlist *a)
{
	if ((*a).precision > (*a).len_arg)
	{
		(*a).len_arg = (*a).precision;
		if ((*a).plus == 1 || arg < 0)
			(*a).len_arg++;
	}
	if ((*a).zero == 0)
	{
		format_width((*a), (*a).len_arg);
		(*a) = format_choose_sign_f(arg, (*a));
	}
	if ((*a).zero == 1)
	{
		(*a) = format_choose_sign_f(arg, (*a));
		if (arg < 0 || (*a).plus == 1)
			(*a).len_arg--;
		format_width((*a), (*a).len_arg);
	}
	while ((*a).ilenarg < (*a).precision)
	{
		ft_write_my(0, (*a).fd, '0');
		(*a).ilenarg++;
	}
	return (*a);
}

t_structlist			no_min_no_isp(long double arg, t_structlist *a)
{
	if ((*a).zero == 1)
	{
		(*a) = format_choose_sign_f(arg, (*a));
		if (arg < 0 || (*a).plus == 1)
			(*a).len_arg--;
	}
	format_width((*a), (*a).len_arg);
	if ((*a).zero == 0)
		(*a) = format_choose_sign_f(arg, (*a));
	return (*a);
}

void					f_no_min(long double arg, t_structlist *a)
{
	(*a).ilenarg = (*a).len_arg;
	if ((*a).plus == 1 || arg < 0)
		(*a).len_arg++;
	if ((*a).isp == 1)
		(*a) = no_min_isp(arg, a);
	if ((*a).isp == 0)
		(*a) = no_min_no_isp(arg, a);
	if (arg < 0)
		arg *= -1;
	if ((*a).isp == 1)
		ft_float(arg, (*a));
	else
	{
		(*a).precision = 6;
		ft_float(arg, (*a));
	}
}

void					before_min(long double arg, t_structlist *a, int *num)
{
	(*a).len_arg = count_float(arg, (*a));
	(*num) = count_num_f(arg, (*a));
	if (arg == 0 && (*a).isp == 1 && (*a).precision == 0 && (*a).width != 0)
		(*a).width++;
	if ((*a).space == 1 && arg >= 0)
	{
		ft_write_my(0, (*a).fd, ' ');
		(*a).width--;
	}
}
