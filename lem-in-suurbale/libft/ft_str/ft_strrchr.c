/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <mburnett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:25:41 by mburnett          #+#    #+#             */
/*   Updated: 2019/09/20 21:25:41 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	while (len-- > 0 && *s != (char)c)
		s--;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}
