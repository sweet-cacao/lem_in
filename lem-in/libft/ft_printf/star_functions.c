/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:23:57 by gstarvin          #+#    #+#             */
/*   Updated: 2019/11/19 14:23:57 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_structlist	add_star(t_star star, t_structlist a)
{
	if (star.star_w >= 0 && a.isw == 0)
		a.width = star.star_w;
	if (star.star_p >= 0 && a.isw == 0)
		a.precision = star.star_p;
	if (star.minus == 1)
		a.min = 1;
	if (star.star_p == -2)
		a.isp = 0;
	return (a);
}

t_star			set_star_s(t_star star, char *format, int end)
{
	if (star.star_p < 0)
	{
		if (format[end] == 's')
			star.star_p *= -1;
		else
			star.star_p = -2;
	}
	return (star);
}

t_star			star_func(va_list ap, char *format, int i, int end)
{
	t_star star;

	star.star_w = -1;
	star.star_p = -1;
	star.minus = -1;
	while (i < end)
	{
		if ((format[i]) == '*' && (format[i - 1]) != '.')
		{
			star.star_w = (va_arg(ap, int));
			if (star.star_w < 0)
			{
				star.star_w *= -1;
				star.minus = 1;
			}
		}
		if ((format[i]) == '*' && (format[i - 1]) == '.')
		{
			star.star_p = (va_arg(ap, int));
			star = set_star_s(star, format, end);
		}
		i++;
	}
	return (star);
}
