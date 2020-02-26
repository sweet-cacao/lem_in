/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:21:16 by gstarvin          #+#    #+#             */
/*   Updated: 2019/11/19 20:03:18 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			format_width(t_structlist a, int len_arg)
{
	int i;

	i = 0;
	if (a.width > len_arg)
	{
		while (i < (a.width - len_arg))
		{
			if (a.zero == 1)
				ft_write_my(0, a.fd, '0');
			else
				ft_write_my(0, a.fd, ' ');
			i++;
		}
	}
}

t_structlist	flag_ignore(t_structlist a)
{
	if (a.min == 1)
		a.zero = 0;
	if (a.plus == 1)
		a.space = 0;
	return (a);
}

t_structlist	fill_flags(t_structlist *a, int *i, char *str)
{
	while (first_flag(str[*i]))
	{
		set_func(str[*i], (*a));
		(*i)++;
	}
	(*a) = flag_ignore((*a));
	if (str[*i] == '*')
		(*i)++;
	return (*a);
}

t_structlist	fill_struct(t_structlist a, int *i, char *str)
{
	a = fill_flags(&a, i, str);
	if (is_number(str[*i]))
	{
		a.width = ft_atoi(&str[*i]);
		a.isw = 1;
		while (is_number(str[*i]) || str[*i] == '0')
			(*i)++;
	}
	if (str[*i] == '*')
		(*i)++;
	if (str[*i] == '.')
	{
		(*i)++;
		if (str[(*i)] != '*')
			a.precision = ft_atoi(&str[*i]);
		a.isp = 1;
		while (is_number(str[*i]) || str[*i] == '0')
			(*i)++;
	}
	if (str[*i] == '*')
		(*i)++;
	if (a.isp == 1 && str[*i] != 'f' && str[*i] != 'd' && str[*i] != 'i')
		a.zero = 0;
	return (a);
}

t_structlist	zero_struct(void)
{
	t_structlist a;

	a.hash = 0;
	a.min = 0;
	a.plus = 0;
	a.precision = 0;
	a.space = 0;
	a.width = 0;
	a.isp = 0;
	a.zero = 0;
	a.isw = 0;
	a.len_arg = 0;
	a.ilenarg = 0;
	a.fd = 1;
	return (a);
}
