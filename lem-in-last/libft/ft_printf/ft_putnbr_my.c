/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_my.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:23:36 by gstarvin          #+#    #+#             */
/*   Updated: 2019/11/21 14:02:02 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_long(long long int n, int fd)
{
	int		i;
	char	*buff;

	i = 0;
	if (n == (-9223372036854775807 - 1))
	{
		buff = "9223372036854775808";
		while (i < 19)
		{
			ft_write_my(0, fd, buff[i]);
			i++;
		}
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		ft_write_my(0, fd, '-');
	}
	if (n >= 10)
		ft_putnbr_long(n / 10, fd);
	ft_write_my(0, fd, n % 10 + 48);
}

void	ft_putnbr_long_u(unsigned long long int n, int fd)
{
	if (n >= 10)
		ft_putnbr_long_u(n / 10, fd);
	ft_write_my(0, fd, n % 10 + 48);
}

void	ft_putnbr_unsigned_long(unsigned long long int n, int fd)
{
	if (n <= 9)
		ft_write_my(0, fd, (n + '0'));
	if (n > 9)
	{
		ft_putnbr_unsigned_long(n / 10, fd);
		ft_putnbr_unsigned_long(n % 10, fd);
	}
}
