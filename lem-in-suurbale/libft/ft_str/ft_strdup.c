/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:26:03 by mburnett          #+#    #+#             */
/*   Updated: 2019/09/16 15:41:41 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*s2;

	i = 0;
	while (s1[i])
		i++;
	s2 = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	if (!s2)
		return (NULL);
	else
	{
		while (s1[i])
		{
			s2[i] = s1[i];
			i++;
		}
	}
	s2[i] = '\0';
	return (s2);
}
