/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <mburnett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:21:31 by mburnett          #+#    #+#             */
/*   Updated: 2019/09/21 09:44:09 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	i = 0;
	if (s && *s)
	{
		p = ft_strnew(len);
		if (!p)
			return (NULL);
		s = s + start;
		while (len-- > 0)
		{
			p[i] = s[i];
			i++;
		}
		return (p);
	}
	return (NULL);
}
