/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:23:25 by gstarvin          #+#    #+#             */
/*   Updated: 2019/11/21 12:18:09 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_parse_di(va_list ap, char *walk, t_parse *p, int count)
{
	if ((*p).end > 1 && walk[(*p).end - 1] == 'h' && walk[(*p).end - 2] == 'h')
		count += format_print_di(((signed char)(va_arg(ap, int))), walk, (*p));
	else if (walk[(*p).end - 1] == 'h' && walk[(*p).end - 2] != 'h')
		count += format_print_di(((short int)(va_arg(ap, int))), walk, (*p));
	else if ((*p).end > 1 && walk[(*p).end - 1] == 'l' &&
								walk[(*p).end - 2] == 'l')
		count += format_print_di(va_arg(ap, long long int), walk, (*p));
	else if (walk[(*p).end - 1] == 'l' && walk[(*p).end - 2] != 'l')
		count += format_print_di(va_arg(ap, long int), walk, (*p));
	else
		count += format_print_di(va_arg(ap, int), walk, (*p));
	return (count);
}

int		ft_parse_uox(va_list ap, char *walk, t_parse *p, int count)
{
	if ((*p).end > 1 && walk[(*p).end - 1] == 'h' && walk[(*p).end - 2] == 'h')
		count += format_print_u(((unsigned char)
				(va_arg(ap, unsigned int))), walk, (*p));
	else if (walk[(*p).end - 1] == 'h' && walk[(*p).end - 2] != 'h')
		count += format_print_u(((unsigned short int)
				(va_arg(ap, unsigned int))), walk, (*p));
	else if ((*p).end > 1 && walk[(*p).end - 1] == 'l' &&
								walk[(*p).end - 2] == 'l')
		count += format_print_u(va_arg(ap, unsigned long long int), walk, (*p));
	else if (walk[(*p).end - 1] == 'l' && walk[(*p).end - 2] != 'l')
		count += format_print_u(va_arg(ap, unsigned long int), walk, (*p));
	else
		count += format_print_u(va_arg(ap, unsigned int), walk, (*p));
	return (count);
}

int		ft_parse_f(va_list ap, char *walk, t_parse *p, int count)
{
	if (walk[(*p).end - 1] == 'L' || (walk[(*p).end - 1] == 'l' &&
										walk[(*p).end - 2] == 'l'))
		count += format_print_f((va_arg(ap, long double)), walk, (*p));
	else
		count += format_print_f((va_arg(ap, double)), walk, (*p));
	return (count);
}

int		ft_parse(va_list ap, char *walk, t_parse p)
{
	int count;

	count = 0;
	if (walk[p.end] == '%')
		count += format_percent('%', walk, p.i, p);
	if (walk[p.end] == 'd' || walk[p.end] == 'i')
		count = ft_parse_di(ap, walk, &p, count);
	if (walk[p.end] == 'u' || walk[p.end] == 'o' ||
				walk[p.end] == 'x' || walk[p.end] == 'X')
		count = ft_parse_uox(ap, walk, &p, count);
	if (walk[p.end] == 'c')
		count += format_print_c((char)(va_arg(ap, int)), walk, p);
	if (walk[p.end] == 's')
		count += format_print_s((va_arg(ap, char *)), walk, p);
	if (walk[p.end] == 'p')
		count += format_print_p((va_arg(ap, void *)), walk, p);
	if (walk[p.end] == 'f')
		count += ft_parse_f(ap, walk, &p, count);
	if (walk[p.end] == 'b')
		count += binary((va_arg(ap, int)), p);
	if (walk[p.end] == 'r')
		count += nonprintable(p);
	if (walk[p.end] == 'k')
		count += unix_timestamp(va_arg(ap, unsigned long long), p);
	return (count);
}
