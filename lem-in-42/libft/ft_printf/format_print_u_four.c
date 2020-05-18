/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_print_u_four.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:50:13 by mburnett          #+#    #+#             */
/*   Updated: 2019/11/23 16:50:16 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	write_prefix(t_structlist *a, char c)
{
	ft_write_my(0, (*a).fd, '0');
	if (c != 'o')
		ft_write_my(0, (*a).fd, c);
}

void	print_final(t_parse *p)
{
	char	*buff;
	int		i;
	int		sum;
	int		len;

	i = 0;
	sum = 0;
	buff = ft_write_my(0, (*p).fd, '\0');
	while (!(is_null(buff, i)))
	{
		if (buff[i] != '\x00')
			sum++;
		i++;
	}
	if (sum > (*p).sum)
		len = sum;
	else
		len = (*p).sum;
	if ((*p).sum != 100)
		write((*p).fd, buff, len % 100);
	ft_write_my(1, (*p).fd, '\0');
}
