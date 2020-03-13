/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_front.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:15:03 by gstarvin          #+#    #+#             */
/*   Updated: 2020/02/24 12:21:16 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_str/libft.h"

void	push_front(int data, int order, t_sort **sort)
{
	t_sort	*tmp;

	if ((*sort) == NULL)
		(*sort) = add_block(data, order);
	else
	{
		tmp = add_block(data, order);
		if (*sort)
			(*sort)->prev = tmp;
		tmp->next = (*sort);
		(*sort) = tmp;
	}
}
