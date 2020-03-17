/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:23:14 by gstarvin          #+#    #+#             */
/*   Updated: 2019/11/19 21:28:58 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void					rounding_plus_one(long double *fr)
{
	int				i;
	int				count;

	i = 4;
	count = 0;
	while (i > 0)
	{
		*fr *= 10;
		if ((unsigned long long int)(*fr) % 10 == 9)
			count++;
		i--;
	}
	if (count == 3)
		*fr += 0.1;
	while (i < 4)
	{
		*fr /= 10;
		i++;
	}
}

int						format_print_f(long double arg, char *str,
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
	while (str[i] == 'L' || str[i] == 'l')
		i++;
	if (is_f(str[i]))
	{
		before_min(arg, &a, &num);
		if (a.min == 1)
			f_is_min(arg, &a);
		else
			f_no_min(arg, &a);
		return (num);
	}
	return (0);
}

unsigned long long int	count_ft_float(long double fract, int count_pres,
		unsigned long long int fract2, t_structlist a)
{
	int count;

	count = 0;
	while (count_pres)
	{
		fract = fract * 10;
		fract2 = fract;
		if (fract2 == 0)
			count++;
		count_pres--;
	}
	while (count > 0)
	{
		ft_write_my(0, a.fd, '0');
		count--;
	}
	return (fract2);
}

void					ft_float_print(unsigned long long int fract2,
		int last_dig, int fd)
{
	if (count_length(fract2) > 1)
	{
		ft_putnbr_unsigned_long(fract2 / 10, fd);
		ft_putnbr_long((long long int)last_dig, fd);
	}
	else
		ft_putnbr_unsigned_long(fract2, fd);
}

void					ft_float(long double num, t_structlist a)
{
	unsigned long long	whole;
	long double			fract;
	int					count_pres;
	unsigned long long	fract2;
	int					last_dig;

	count_pres = a.precision;
	fract2 = 0;
	rounding(&a, count_pres, &num, &last_dig);
	count_pres = a.precision;
	whole = (unsigned long long)num;
	fract = num - whole;
	ft_putnbr_unsigned_long(whole, a.fd);
	if (a.hash == 1 || a.precision != 0)
		ft_write_my(0, a.fd, '.');
	if (a.precision != 0)
	{
		fract2 = count_ft_float(fract, count_pres, fract2, a);
		if (fract2 != 0)
			ft_float_print(fract2, last_dig, a.fd);
	}
}
