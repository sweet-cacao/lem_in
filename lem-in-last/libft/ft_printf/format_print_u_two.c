/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_print_u_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:22:53 by gstarvin          #+#    #+#             */
/*   Updated: 2019/11/21 14:02:02 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_structlist	print_u_isp1(const char *str, int start, t_structlist *a)
{
	if ((*a).isp == 1 && str[start] == 'o')
	{
		if ((*a).precision > (*a).len_arg)
		{
			while ((*a).len_arg < (*a).precision)
			{
				ft_write_my(0, (*a).fd, '0');
				(*a).len_arg++;
			}
		}
	}
	if ((*a).isp == 1 && (str[start] == 'X' || str[start] == 'x' ||
							str[start] == 'u' || str[start] == 'p'))
	{
		if ((*a).precision > (*a).len_arg)
		{
			while ((*a).ilenarg < (*a).precision)
			{
				ft_write_my(0, (*a).fd, '0');
				(*a).ilenarg++;
				(*a).len_arg++;
			}
		}
	}
	return (*a);
}

void			modif_lenarg(const char *str, int start, t_structlist *a)
{
	if (str[start] == 'o')
		(*a).len_arg++;
	if (str[start] == 'x')
		(*a).len_arg += 2;
	if (str[start] == 'X')
		(*a).len_arg += 2;
}

t_structlist	print_u_isp2(const char *str, int start, t_structlist *a)
{
	if ((*a).hash == 1 && (*a).precision < (*a).len_arg)
		modif_lenarg(str, start, a);
	if ((*a).precision > (*a).len_arg)
	{
		(*a).len_arg = (*a).precision;
		if ((*a).hash == 1 && (str[start] == 'x' ||
		str[start] == 'X' || str[start] == 'p'))
			modif_lenarg(str, start, a);
	}
	if ((*a).zero == 0)
		format_width((*a), (*a).len_arg);
	return (*a);
}

t_structlist	print_u_hash2(const char *str, int start, t_structlist *a)
{
	if ((*a).hash == 1)
	{
		if (str[start] == 'o')
		{
			write_prefix(a, 'o');
			(*a).ilenarg++;
		}
		if (str[start] == 'x' || str[start] == 'p')
			write_prefix(a, 'x');
		if (str[start] == 'X')
			write_prefix(a, 'X');
	}
	if ((*a).zero == 1)
		format_width((*a), (*a).len_arg);
	while ((*a).precision > (*a).ilenarg)
	{
		ft_write_my(0, (*a).fd, '0');
		(*a).ilenarg++;
	}
	return (*a);
}

void			write_hash(const char *str, int start, int fd)
{
	if (str[start] == 'o')
		ft_write_my(0, fd, '0');
	if (str[start] == 'x' || str[start] == 'p')
	{
		ft_write_my(0, fd, '0');
		ft_write_my(0, fd, 'x');
	}
	if (str[start] == 'X')
	{
		ft_write_my(0, fd, '0');
		ft_write_my(0, fd, 'X');
	}
}
