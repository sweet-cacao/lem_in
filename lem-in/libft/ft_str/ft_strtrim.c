/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:47:18 by mburnett          #+#    #+#             */
/*   Updated: 2020/02/20 17:01:33 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_iswspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

char	*ft_strtrim(char const *s)
{
	char		*str;
	size_t		i;
	size_t		j;

	i = 0;
	str = NULL;
	if (!(s))
		return (str);
	while (s[i] && ft_iswspace(s[i]) == 1)
		i++;
	j = ft_strlen(&s[i]) - 1;
	while (s[j] && ft_iswspace(s[j + i]) == 1)
	{
		j--;
	}
	if (!(str = ft_strnew(j + 1)))
		return (NULL);
	ft_strncpy(str, (s + i), (j + 1));
	return (str);
}
