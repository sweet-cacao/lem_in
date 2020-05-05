/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <mburnett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:21:28 by mburnett          #+#    #+#             */
/*   Updated: 2019/09/22 16:47:08 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*p1;
	char	*p2;

	p1 = (char *)dest;
	p2 = (char *)src;
	if (!src && !dest)
		return (0);
	while (n-- > 0)
		*(p1++) = *(p2++);
	return (dest);
}
