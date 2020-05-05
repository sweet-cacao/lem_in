/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_my.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:24:39 by gstarvin          #+#    #+#             */
/*   Updated: 2019/11/21 16:52:46 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_write_my(int flag, int fd, char c)
{
	static char	buff[100];
	static int	i = 0;

	if (flag == 1)
	{
		ft_bzero(buff, 100);
		i = 0;
		return (0);
	}
	if (i == 100)
	{
		write(fd, buff, 100);
		ft_bzero(buff, 100);
		i = 0;
	}
	if (i < 100)
	{
		buff[i] = c;
		i++;
	}
	return (buff);
}
