/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_oct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:23:44 by gstarvin          #+#    #+#             */
/*   Updated: 2019/11/19 14:23:44 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	find_hex_upper(unsigned long long int n)
{
	char *str;

	str = "0123456789ABCDEF";
	return (str[n]);
}

char	find_hex_lower(unsigned long long int n)
{
	char *str;

	str = "0123456789abcdef";
	return (str[n]);
}

int		count_hex(unsigned long long int n, char a)
{
	char	arr[16];
	int		i;

	ft_bzero(arr, 16);
	i = 0;
	if (n == 0)
		return (1);
	while (n > 0 && i < 16)
	{
		if (a == 'X')
			arr[i] = find_hex_upper(n % 16);
		else if (a == 'x' || a == 'p')
			arr[i] = find_hex_lower(n % 16);
		n = n / 16;
		i++;
	}
	arr[i] = '\0';
	return (ft_strlen(arr));
}

int		count_oct(unsigned long long int n)
{
	char	arr[22];
	int		i;

	ft_bzero(arr, 22);
	i = 0;
	if (n == 0)
		return (1);
	while (n > 0 && i < 22)
	{
		arr[i] = find_hex_lower(n % 8);
		n = n / 8;
		i++;
	}
	arr[i] = '\0';
	return (ft_strlen(arr));
}
