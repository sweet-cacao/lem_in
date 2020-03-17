/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:20:25 by mburnett          #+#    #+#             */
/*   Updated: 2019/11/23 16:20:34 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		find_number(char c)
{
	if (c == '0')
		return (0);
	else if (c == '1')
		return (1);
	return (2);
}

void	print_binary(t_parse *p, char *arr, int *i, int *k)
{
	(*i)--;
	ft_write_my(0, (*p).fd, arr[(*i)]);
	(*k)++;
}

void	dop_code(char *arr, int i, t_parse p, int *k)
{
	int j;

	j = -1;
	while (++j < i)
	{
		if (arr[j] == '0')
			arr[j] = '1';
		else
			arr[j] = '0';
	}
	j = -1;
	while (++j < i)
	{
		arr[j] = find_number(arr[j]) + 1 + '0';
		if (find_number(arr[j]) == 2)
			arr[j] = '0';
		else
			break ;
	}
	while (i > 0)
		print_binary(&p, arr, &i, k);
}

void	create_binary(char *arr, long long int *num, int *i)
{
	arr[(*i)] = (*num) % 2 + '0';
	(*num) /= 2;
	(*i)++;
}

int		binary(long long int num, t_parse p)
{
	unsigned int	flag;
	char			arr[33];
	int				i;
	int				k;

	k = 0;
	flag = 0;
	i = 0;
	if (num == 0)
		ft_write_my(0, p.fd, '0');
	if (num < 0)
	{
		flag = 1;
		num = -num;
	}
	while (num > 0)
		create_binary(arr, &num, &i);
	if (flag)
		dop_code(arr, i, p, &k);
	else
	{
		while (i > 0)
			print_binary(&p, arr, &i, &k);
	}
	return (k);
}
