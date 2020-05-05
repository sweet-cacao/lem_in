/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:23:30 by gstarvin          #+#    #+#             */
/*   Updated: 2019/11/21 18:24:06 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_parse	ft_printf_parse(char *walk, t_parse *p, va_list ap)
{
	(*p).star = star_func(ap, walk, (*p).i, (*p).end);
	(*p).parse = ft_parse(ap, walk, (*p));
	if ((*p).parse == -1)
	{
		ft_putstr("(null)");
		(*p).parse = 6;
	}
	if ((*p).parse == -2)
		(*p).parse = 0;
	(*p).sum += (*p).parse;
	(*p).i = (*p).end;
	(*p).i++;
	return (*p);
}

t_parse	ft_printf_while_percent(char *walk, t_parse *p)
{
	ft_write_my(0, (*p).fd, walk[(*p).i]);
	(*p).sum++;
	(*p).i++;
	return (*p);
}

t_parse	zero_parse(t_parse *p)
{
	(*p).parse = 0;
	(*p).sum = 0;
	(*p).i = 0;
	(*p).fd = 1;
	return (*p);
}

int		ft_printf(char *walk, ...)
{
	t_parse p;
	va_list ap;

	p = zero_parse(&p);
	va_start(ap, walk);
	while (walk[p.i])
	{
		p = ft_printf_one(walk, &p);
		while (walk[p.i] != '%')
		{
			p = ft_printf_while_percent(walk, &p);
			if (!(walk[p.i]))
				return (ft_printf_two(&p));
		}
		if (!(walk[++p.i]))
			return (ft_printf_two(&p));
		p.end = p.i;
		while (skip(walk, p))
			p.end++;
		if (!(walk[p.end]))
			return (ft_printf_three(&p));
		p = ft_printf_parse(walk, &p, ap);
	}
	va_end(ap);
	return (ft_printf_four(&p));
}

int		is_null(char *buff, int i)
{
	while (i < 99)
	{
		if (buff[i] != '\0')
			return (0);
		i++;
	}
	return (1);
}
