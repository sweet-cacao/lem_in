/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_print_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:22:23 by gstarvin          #+#    #+#             */
/*   Updated: 2019/11/21 12:18:09 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_putstr_p(char *str, int precision, int fd)
{
	int i;

	i = 0;
	while (i < precision)
	{
		ft_write_my(0, fd, str[i]);
		i++;
	}
}

int			count_num_str(char *arg, t_structlist a)
{
	int len_arg;

	len_arg = ft_strlen(arg);
	if (a.isp && a.width > a.precision)
		return (a.width);
	if (a.width > len_arg)
		len_arg = a.width;
	else
	{
		if (a.isp == 1 && len_arg > a.precision)
		{
			len_arg = a.precision;
		}
	}
	return (len_arg);
}

int			format_s_zero(t_structlist *a, int i)
{
	if ((*a).width == 0)
		return (-2);
	else
	{
		i = 0;
		while (i < (*a).width)
		{
			if ((*a).zero == 1)
				ft_write_my(0, (*a).fd, '0');
			else
				ft_write_my(0, (*a).fd, ' ');
			i++;
		}
		return ((*a).width);
	}
}

void		format_s_all_conditions(char *arg, t_structlist *a)
{
	if ((*a).isp == 1 && (*a).precision < (*a).len_arg)
		(*a).len_arg = (*a).precision;
	else
		(*a).len_arg = ft_strlen(arg);
	if ((*a).min == 1)
	{
		ft_putstr_p(arg, (*a).len_arg, (*a).fd);
		if ((*a).width > (*a).len_arg)
		{
			while ((*a).width > (*a).len_arg)
			{
				ft_write_my(0, (*a).fd, ' ');
				(*a).width--;
			}
		}
	}
	else
	{
		if ((*a).width > (*a).len_arg)
			format_width_c((*a), (*a).len_arg);
		ft_putstr_p(arg, (*a).len_arg, (*a).fd);
	}
}

int			format_print_s(char *arg, char *str, t_parse p)
{
	t_structlist	a;
	int				i;
	int				num;

	i = p.i;
	if (arg == NULL)
		arg = "(null)";
	a = zero_struct();
	a.fd = p.fd;
	a = fill_struct(a, &i, str);
	a = add_star(p.star, a);
	num = count_num_str(arg, a);
	a.len_arg = ft_strlen(arg);
	if (!(ft_strlen(arg)))
		return (format_s_zero(&a, i));
	if (str[i] == 's')
	{
		format_s_all_conditions(arg, &a);
		return (num);
	}
	return (0);
}
