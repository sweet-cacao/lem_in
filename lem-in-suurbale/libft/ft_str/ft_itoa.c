/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <mburnett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:22:59 by mburnett          #+#    #+#             */
/*   Updated: 2019/09/21 10:45:24 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_countchars(int nb)
{
	size_t	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		len++;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	size_t	len;
	char	*p;

	len = ft_countchars(n);
	if (!(p = ft_strnew(len)))
		return (NULL);
	if (n < 0)
	{
		p[0] = '-';
		if (n == -2147483648)
		{
			p[1] = ('2');
			n = -147483648;
		}
		n = -n;
	}
	if (n == 0)
		p[0] = '0';
	while (n != 0)
	{
		p[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (p);
}
