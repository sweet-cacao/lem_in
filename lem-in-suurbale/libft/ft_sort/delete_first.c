/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_first.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:19:06 by gstarvin          #+#    #+#             */
/*   Updated: 2020/02/24 12:25:40 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_str/libft.h"

void		delete_first(t_sort **sort)
{
	t_sort	*tmp;

	if (!sort)
		return ;
	tmp = (*sort);
	if (!tmp)
		return ;
	if (!tmp->next)
	{
		free(*sort);
		(*sort) = NULL;
		sort = NULL;
		return ;
	}
	(*sort) = (*sort)->next;
	free(tmp);
	tmp = NULL;
	(*sort)->prev = NULL;
}
