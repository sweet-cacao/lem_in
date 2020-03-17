/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_print_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:21:43 by gstarvin          #+#    #+#             */
/*   Updated: 2019/11/21 12:18:09 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	format_width_c(t_structlist a, int i)
{
	while (a.width > i)
	{
		if (a.zero == 1)
			ft_write_my(0, a.fd, '0');
		else
			ft_write_my(0, a.fd, ' ');
		a.width--;
	}
}

int		count_num_c(t_structlist a)
{
	if (a.width > 0)
		return (a.width);
	else
		return (1);
}

int		print_c(char arg, t_structlist *a, int num)
{
	if ((*a).min == 1)
	{
		ft_write_my(0, (*a).fd, arg);
		while ((*a).width > 1)
		{
			ft_write_my(0, (*a).fd, ' ');
			(*a).width--;
		}
	}
	else
	{
		if ((*a).width > 1)
			format_width_c((*a), 1);
		ft_write_my(0, (*a).fd, arg);
	}
	return (num);
}

int		format_print_c(char arg, char *str, t_parse p)
{
	t_structlist	a;
	int				i;
	int				num;

	i = p.i;
	a = zero_struct();
	a.fd = p.fd;
	a = fill_struct(a, &i, str);
	a = add_star(p.star, a);
	num = count_num_c(a);
	if (str[i] == 'c')
		return (print_c(arg, &a, num));
	return (0);
}
