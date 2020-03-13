/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <mburnett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:25:31 by mburnett          #+#    #+#             */
/*   Updated: 2019/09/20 21:25:31 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (j < len && haystack[j])
	{
		while (needle[i] != '\0' && needle[i] == haystack[j + i] &&
			haystack[j] != '\0' && (i + j) < len)
			i++;
		if (needle[i] == '\0')
			return ((char *)&haystack[j]);
		i = 0;
		j++;
	}
	if (!needle[0])
		return ((char *)&haystack[j]);
	return (0);
}
