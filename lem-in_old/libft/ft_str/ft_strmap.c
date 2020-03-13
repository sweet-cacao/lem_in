/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <mburnett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:17:12 by mburnett          #+#    #+#             */
/*   Updated: 2019/09/21 09:07:20 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			p[i] = f(s[i]);
			i++;
		}
		return (p);
	}
	return (NULL);
}
