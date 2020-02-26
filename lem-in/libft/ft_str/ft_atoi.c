/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:43:16 by mburnett          #+#    #+#             */
/*   Updated: 2020/02/21 12:21:42 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	help(char c, int *otriz, int *i)
{
	if (c == '-')
		*otriz = -1;
	if (c == '+' || c == '-')
		(*i)++;
}

int		ft_atoi(const char *str)
{
	int			i;
	int			otv;
	long int	otv2;
	int			otriz;

	i = 0;
	otv = 0;
	otv2 = 0;
	otriz = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
	str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (ft_strcmp(&str[i], "-2147483648") == 0)
		return (-2147483648);
	help(str[i], &otriz, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		otv = 10 * otv + (str[i] - 48);
		if (otv != (otv2 * 10 + (str[i] - 48)))
			return (-1);
		i++;
		otv2 = otv;
	}
	otv = otv * otriz;
	return (otv);
}
