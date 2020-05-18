/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_print_p_extra.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:22:15 by gstarvin          #+#    #+#             */
/*   Updated: 2019/11/21 14:03:26 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_structlist	format_p_zero(const void *arg, t_structlist *a, int i)
{
	if ((*a).zero == 1)
	{
		ft_write_my(0, (*a).fd, '0');
		ft_write_my(0, (*a).fd, 'x');
		i = 14;
		if ((*a).width > 14)
		{
			while (i < (*a).width)
			{
				ft_write_my(0, (*a).fd, '0');
				i++;
			}
		}
	}
	else
		format_p_conditions_for_pre(arg, a, i);
	return (*a);
}

void			format_p_conditions_for_pre(const void *arg,
											t_structlist *a, int i)
{
	i = count_hex((unsigned long long)arg, 'x') + 2;
	if ((*a).width > (*a).precision + 2)
	{
		while (i < (*a).width)
		{
			ft_write_my(0, (*a).fd, ' ');
			i++;
		}
	}
	ft_write_my(0, (*a).fd, '0');
	ft_write_my(0, (*a).fd, 'x');
	if ((*a).precision > count_hex((unsigned long long)arg, 'x'))
	{
		i = count_hex((unsigned long long)arg, 'x');
		while (i < (*a).precision)
		{
			ft_write_my(0, (*a).fd, '0');
			i++;
		}
	}
}

void			format_p_min(const void *arg, t_structlist *a, int i)
{
	ft_write_my(0, (*a).fd, '0');
	ft_write_my(0, (*a).fd, 'x');
	if ((*a).precision > 12)
	{
		i = 12;
		while (i < (*a).precision)
		{
			ft_write_my(0, (*a).fd, '0');
			i++;
		}
	}
	if (arg == 0)
		format_p_is_precision(a, i);
	else
		print_pointer(arg, (*a).fd);
	if ((*a).width > ((*a).precision + 2))
	{
		i = (*a).precision + 2;
		while (i < (*a).width)
		{
			ft_write_my(0, (*a).fd, ' ');
			i++;
		}
	}
}

void			format_p_is_precision(t_structlist *a, int i)
{
	if ((*a).isp == 1)
	{
		i = 0;
		while (i < (*a).precision)
		{
			ft_write_my(0, (*a).fd, '0');
			i++;
		}
	}
	else if ((*a).isp == 0)
		ft_write_my(0, (*a).fd, '0');
}
