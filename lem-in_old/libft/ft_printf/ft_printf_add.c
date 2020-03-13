/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:39:44 by mburnett          #+#    #+#             */
/*   Updated: 2019/11/23 17:39:48 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_parse		ft_printf_one(char *walk, t_parse *p)
{
	if (walk[(*p).i] && walk[(*p).i + 1] && walk[(*p).i] == '[' &&
		(is_number(walk[(*p).i + 1]) || walk[(*p).i + 1] == '0' ||
		walk[(*p).i + 1] == '-'))
	{
		(*p).i++;
		(*p).fd = ft_atoi(&walk[(*p).i]);
		while (walk[(*p).i] && (is_number(walk[(*p).i]) ||
								walk[(*p).i] == '0' || walk[(*p).i] == '-'))
			(*p).i++;
		(*p).i++;
	}
	return (*p);
}

int			ft_printf_two(t_parse *p)
{
	if ((*p).sum != 0)
		print_final(p);
	return ((*p).sum);
}

int			ft_printf_three(t_parse *p)
{
	if ((*p).parse != 0)
		print_final(p);
	return ((*p).parse);
}

int			ft_printf_four(t_parse *p)
{
	if ((*p).sum != 0)
		print_final(p);
	return ((*p).sum);
}

int			skip(char *walk, t_parse p)
{
	if (walk[p.end] && (!(is_dioux(walk[p.end]))) &&
		(!(is_csp(walk[p.end]))) && walk[p.end] != 'f' && walk[p.end] != '%')
		return (1);
	return (0);
}
