/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <mburnett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:21:44 by mburnett          #+#    #+#             */
/*   Updated: 2019/09/21 08:46:32 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)dst;
	p2 = (unsigned char *)src;
	i = 0;
	if (!p1 && !p2)
		return (0);
	if (p2 < p1)
	{
		while (++i <= len)
			p1[len - i] = p2[len - i];
	}
	else
	{
		while (len-- > 0)
			*(p1++) = *(p2++);
	}
	return (dst);
}
