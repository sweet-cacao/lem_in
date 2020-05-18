/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:29:27 by gstarvin          #+#    #+#             */
/*   Updated: 2020/02/24 19:34:52 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_str/libft.h"

void	sort_del(t_sort **sort)
{
	t_sort *next;

	if (!sort || !(*sort))
		return ;
	while (*sort)
	{
		next = (*sort)->next;
		free((*sort));
		(*sort) = NULL;
		(*sort) = next;
	}
	if (sort && (*sort))
	{
		free((*sort));
		*sort = NULL;
	}
	sort = NULL;
}
