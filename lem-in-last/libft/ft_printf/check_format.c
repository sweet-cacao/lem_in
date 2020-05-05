/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:20:55 by gstarvin          #+#    #+#             */
/*   Updated: 2019/11/21 12:18:09 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		first_flag(char c)
{
	return (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ');
}

int		is_dioux(char c)
{
	return (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' ||
	c == 'X');
}

int		is_csp(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'k' || c == 'b' ||
	c == 'r');
}

int		is_number(char c)
{
	return (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' ||
	c == '6' || c == '7' || c == '8' || c == '9');
}

int		is_f(char c)
{
	return (c == 'f');
}
