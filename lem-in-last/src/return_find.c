/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:09:10 by gstarvin          #+#    #+#             */
/*   Updated: 2020/03/13 16:11:48 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

t_gr_block	find_end(t_gr_block *buff, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (buff[i].end == 1)
			return (buff[i]);
		i++;
	}
}

t_gr_block	return_t_gr_block(t_gr_block *buff, int len, char *name)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (ft_strcmp(buff[i].name, name) == 0)
			return (buff[i]);
		i++;
	}
}

t_gr_block	return_t_gr_block_by_block(t_gr_block *buff, int len, t_gr_block *one_block)
{
	int		i;
	char    *name;

	name = one_block->name;
	i = 0;
	while (i < len)
	{
		if (ft_strcmp(buff[i].name, name) == 0 && ((one_block->in == 1 && buff[i].in == 1) || (one_block->out == 1 && buff[i].out == 1)))
			return (buff[i]);
		i++;
	}
}

char		*get_start(t_gr_block *buff, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (buff[i].start == 1)
			return (buff[i].name);
		i++;
	}
	return (NULL);
}

char		*get_end(t_gr_block *buff, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (buff[i].end == 1)
			return (buff[i].name);
		i++;
	}
	return (NULL);
}

t_graph		*return_graph(t_otv *solutions, int path)
{
	t_otv	*tmp;

	tmp = solutions;
	while (tmp)
	{
		if (tmp->number == path)
			return (tmp->solve);
		tmp = tmp->next;
	}
	return (0);
}
