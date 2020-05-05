/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_print_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:22:31 by gstarvin          #+#    #+#             */
/*   Updated: 2019/11/21 12:18:09 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				count_length_u(unsigned long long int n)
{
	int res;

	res = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		res++;
	}
	return (res);
}

int				print_u_return_zero(const char *str, int start, t_structlist *a)
{
	if ((*a).hash == 1 && str[start] == 'o')
	{
		ft_write_my(0, (*a).fd, '0');
		return (1);
	}
	return (-2);
}

void			print_u_skip_i(const char *str, int *start, int *i)
{
	while (str[(*i)] == 'h' || str[(*i)] == 'l')
		(*i)++;
	(*start) = (*i);
}

void			format_u_init(char *str, t_parse *p, t_structlist *a, int *i)
{
	(*i) = (*p).i;
	set_a(str, &(*p).star, a, i);
	(*a).fd = (*p).fd;
	print_u_skip_i(str, &(*p).i, i);
}

int				format_print_u(unsigned long long int arg, char *str,
		t_parse p)
{
	t_structlist	a;
	int				i;
	int				num;

	format_u_init(str, &p, &a, &i);
	if (arg == 0)
	{
		if (a.isp == 1 && a.precision == 0 && a.width == 0)
			return (print_u_return_zero(str, p.i, &a));
		if ((str[p.i] == 'x' || str[p.i] == 'X' || str[p.i] == 'p')
		|| (str[p.i] == 'o' && a.isp == 0))
			a.hash = 0;
	}
	if (str[p.i] == 'p')
		a.hash = 1;
	if (is_dioux(str[i]) || str[i] == 'p')
	{
		a = print_u_setlenarg(arg, str, p.i, &a);
		num = count_num_u(a, str[p.i]);
		print_u_check_min(arg, str, p.i, &a);
		return (num);
	}
	return (0);
}
