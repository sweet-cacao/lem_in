/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:25:51 by gstarvin          #+#    #+#             */
/*   Updated: 2019/11/21 18:06:00 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void					rounding(t_structlist *a, int count_pres,
								long double *num, int *last_dig)
{
	unsigned long long		whole;
	long double				fr;

	whole = (unsigned long long)(*num);
	fr = (*num) - whole;
	if ((*num) < 0)
	{
		ft_write_my(0, (*a).fd, '-');
		(*num) = -(*num);
	}
	(*num) = (*num) - fr;
	while (count_pres > 0)
	{
		fr *= 10;
		count_pres--;
	}
	rounding_plus_one(&fr);
	count_pres = (*a).precision;
	(*last_dig) = (unsigned long long int)(fr += 0.5) % 10;
	while (count_pres > 0)
	{
		fr /= 10;
		count_pres--;
	}
	(*num) = (*num) + fr;
}

unsigned long long int	rounding_for_count_f(long double num, int count_pres)
{
	unsigned long long int	whole;
	int						i;

	i = count_pres;
	if (num < 0)
		num = -num;
	while (count_pres > 0)
	{
		num *= 10;
		count_pres--;
	}
	count_pres = i;
	num += 0.5;
	while (count_pres > 0)
	{
		num /= 10;
		count_pres--;
	}
	whole = (unsigned long long)num;
	return (whole);
}

int						count_float(long double num, t_structlist a)
{
	unsigned long long	whole;
	int					count_pres;

	count_pres = a.precision;
	if (a.isp == 0 && a.precision == 0)
		whole = rounding_for_count_f(num, 6);
	else
		whole = rounding_for_count_f(num, count_pres);
	if (a.isp == 1 && a.precision == 0)
	{
		if (a.hash == 1)
			return (count_length(whole) + 1);
		return (count_length(whole));
	}
	if (a.isp == 0)
		return (count_length(whole) + 1 + 6);
	return (count_length(whole) + 1 + a.precision);
}

int						count_num_f(long double arg, t_structlist a)
{
	a.len_arg = count_float(arg, a);
	if (a.width > a.precision)
	{
		if (a.width > a.len_arg)
			return (a.width);
	}
	else
	{
		if (a.precision > a.len_arg)
			a.len_arg = a.precision;
		if (a.plus == 1 || arg < 0)
			a.len_arg++;
		if (a.space == 1 && arg >= 0)
			a.len_arg++;
	}
	return (a.len_arg);
}

t_structlist			format_choose_sign_f(long double arg, t_structlist a)
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
