/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_block.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:03:06 by gstarvin          #+#    #+#             */
/*   Updated: 2020/02/18 10:04:52 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_str/libft.h"

t_sort		*add_block(int data, int order)
{
	t_sort	*sort;

	sort = malloc(sizeof(t_sort));
	sort->data = data;
	sort->order = order;
	sort->next = NULL;
	sort->prev = NULL;
	return (sort);
}
