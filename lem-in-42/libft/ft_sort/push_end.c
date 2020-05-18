/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:12:54 by gstarvin          #+#    #+#             */
/*   Updated: 2020/02/24 12:30:50 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_str/libft.h"

void	push_end(int data, int order, t_sort **sort)
{
	t_sort	*last;
	t_sort	*tmp;

	last = get_next(*sort);
	tmp = add_block(data, order);
	if (last == NULL)
	{
		(*sort) = tmp;
	}
	else
	{
		last->next = tmp;
		last->next->prev = last;
	}
}
