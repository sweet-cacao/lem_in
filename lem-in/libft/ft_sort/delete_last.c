/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:26:31 by gstarvin          #+#    #+#             */
/*   Updated: 2020/02/18 10:29:08 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_str/libft.h"

void	delete_last(t_sort **sort)
{
	t_sort *tmp;

	tmp = (*sort);
	if (!tmp->next)
	{
		free(*sort);
		(*sort) = NULL;
		return ;
	}
	while (tmp->next->next)
	{
		tmp = tmp->next;
	}
	tmp->next->prev = NULL;
	free(tmp->next);
	tmp->next = NULL;
}
