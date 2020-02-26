/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oxXp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:23:51 by gstarvin          #+#    #+#             */
/*   Updated: 2019/11/19 14:49:24 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printhex2(unsigned long long int n, char a, int fd)
{
	char	arr[16];
	int		i;

	ft_bzero(arr, 16);
	i = 0;
	if (n == 0)
		ft_write_my(0, fd, '0');
	while (n > 0 && i < 16)
	{
		if (a == 'X')
			arr[i] = find_hex_upper(n % 16);
		else if (a == 'x' || a == 'p')
			arr[i] = find_hex_lower(n % 16);
		n = n / 16;
		i++;
	}
	while (--i >= 0)
		ft_write_my(0, fd, arr[i]);
}

void	ft_printoct(unsigned long long int n, int fd)
{
	char	arr[22];
	int		i;

	ft_bzero(arr, 22);
	i = 0;
	if (n == 0)
		ft_write_my(0, fd, '0');
	while (n > 0 && i < 22)
	{
		arr[i] = find_hex_lower(n % 8);
		n = n / 8;
		i++;
	}
	while (--i >= 0)
		ft_write_my(0, fd, arr[i]);
}

void	print_pointer(const void *addr, int fd)
{
	unsigned long long p;

	p = (unsigned long long)addr;
	ft_printhex2(p, 'x', fd);
}
