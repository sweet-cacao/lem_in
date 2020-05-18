/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_print_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:22:07 by gstarvin          #+#    #+#             */
/*   Updated: 2019/11/19 21:14:29 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				count_num_p(t_structlist a, void *arg)
{
	if (arg == 0 && a.isp && a.precision == 0)
		return (2);
	if (arg == 0 && a.isp == 0)
		a.precision = 1;
	if (a.width > a.precision + 2)
		return (a.width);
	if (a.precision > 12)
		return (a.precision + 2);
	if (arg == 0 && a.precision == 1)
		return (3);
	return (a.precision + 2);
}

int				format_print_p(void *arg, char *str, t_parse p)
{
	t_structlist	a;
	int				i;
	int				num;

	i = p.i;
	a = zero_struct();
	a.fd = p.fd;
	a = add_star(p.star, a);
	a.precision = count_hex((unsigned long long)arg, 'x');
	a = fill_struct(a, &i, str);
	num = count_num_p(a, arg);
	if (arg == 0 && a.isp == 0)
		a.precision = 1;
	if (str[i] == 'p')
	{
		format_p_all_conditions(arg, &a, i);
		return (num);
	}
	return (0);
}

void			format_p_all_conditions(const void *arg, t_structlist *a, int i)
{
	if ((*a).zero == 1 && (*a).isp == 1)
		(*a).zero = 0;
	if ((*a).min == 1)
		format_p_min(arg, a, i);
	else
	{
		(*a) = format_p_zero(arg, a, i);
		if (arg == 0)
		{
			if ((*a).isp == 1)
			{
				i = 4;
				while (i < (*a).precision)
				{
					ft_write_my(0, (*a).fd, '0');
					i++;
				}
			}
			else if ((*a).isp == 0)
				ft_write_my(0, (*a).fd, '0');
		}
		else
			print_pointer(arg, (*a).fd);
	}
}
