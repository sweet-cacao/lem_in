/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <mburnett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:18:48 by mburnett          #+#    #+#             */
/*   Updated: 2019/09/21 09:07:20 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*p;

	i = 0;
	if (s && *s)
	{
		p = ft_strnew(ft_strlen(s));
		if (!p)
			return (NULL);
		while (s[i])
		{
			p[i] = f(i, s[i]);
			i++;
		}
		return (p);
	}
	return (NULL);
}
