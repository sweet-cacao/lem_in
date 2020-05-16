/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:30:24 by gstarvin          #+#    #+#             */
/*   Updated: 2020/05/16 16:33:02 by sweet-cacao      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void	del_pointlist(t_pointlist **pointlist)
{
	t_pointlist *next;

	if (!pointlist || !(*pointlist))
		return ;
	while (*pointlist)
	{
		next = (*pointlist)->next;
		free(*pointlist);
		(*pointlist) = NULL;
		(*pointlist) = next;
	}
	pointlist = NULL;
}

void	del_buff_links(int len, t_gr_block *buff)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (buff[i].links)
			del_graph(&buff[i].links);
//		buff[i].parent_name = NULL;
//		buff[i].name = NULL;
//		free(buff[i].name);
//		free(&buff[i].parent);
		i++;
	}
}

void	del_solutions(t_otv **solutions)
{
	t_otv *next;

	if (!solutions || !(*solutions))
		return ;
	while (*solutions)
	{
		next = (*solutions)->next;
		del_graph(&(*solutions)->solve);
		free(*solutions);
		(*solutions) = NULL;
		(*solutions) = next;
	}
	solutions = NULL;
}

void	del_graph(t_graph **graph)
{
	t_graph *next;

	if (!graph || !(*graph))
		return ;
	if ((*graph) == NULL)
		return;
	while (*graph)
	{
		next = (*graph)->next;
		free(*graph);
		(*graph) = NULL;
		(*graph) = next;
	}
	(*graph) = NULL;
	graph = NULL;
}
