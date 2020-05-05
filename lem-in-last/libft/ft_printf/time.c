/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:21:12 by mburnett          #+#    #+#             */
/*   Updated: 2019/11/23 16:21:15 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	time_sub(int *time, int num, unsigned long long *stamp)
{
	(*time)++;
	*stamp -= num;
}

size_t	unix_timestamp(unsigned long long stamp, t_parse p)
{
	int year;
	int month;
	int day;

	year = 1970;
	month = 1;
	day = 1;
	while (stamp > 31556926)
		time_sub(&year, 31556926, &stamp);
	while (stamp > 2629743)
		time_sub(&month, 2629743, &stamp);
	while (stamp > 86400)
		time_sub(&day, 86400, &stamp);
	ft_putnbr_long_u(year, p.fd);
	ft_write_my(0, p.fd, '-');
	ft_putnbr_long_u(month, p.fd);
	ft_write_my(0, p.fd, '-');
	ft_putnbr_long_u(day, p.fd);
	return (count_length(year) + count_length(month) + count_length(day) + 2);
}

size_t	nonprintable(t_parse p)
{
	char	*str;
	size_t	len;
	size_t	i;

	str = "NUL SOH STX ETX EOT ENQ ACK BEL BS TAB LF VT FF CR SO SI DLE " \
		"DC1 DC2 DC3 DC4 NAK SYN ETB CAN EM SUB ESC FS GS RS US";
	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		ft_write_my(0, p.fd, str[i]);
		i++;
	}
	ft_write_my(0, p.fd, str[i]);
	return (len);
}
