/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 10:20:27 by mburnett          #+#    #+#             */
/*   Updated: 2019/09/21 10:20:29 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countwds(char const *s, char c)
{
	size_t words;
	size_t i;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			words++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] == c)
			i++;
	}
	return (words);
}
