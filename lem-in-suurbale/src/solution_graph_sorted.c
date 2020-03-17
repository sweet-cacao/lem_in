/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_graph_sorted.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:12:11 by gstarvin          #+#    #+#             */
/*   Updated: 2020/03/13 16:13:36 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

t_otv		*add_block_solution(t_graph *graph)
{
	t_otv	*otv;

	otv = (t_otv*)malloc(sizeof(t_otv));
	otv->solve = graph;
	otv->next = NULL;
	otv->prev = NULL;
	return (otv);
}

void		push_front_solution(t_otv **otv, t_graph *graph)
{
	t_otv	*tmp;

	tmp = add_block_solution(graph);
	if ((*otv) == NULL)
		(*otv) = tmp;
	else
	{
		if (*otv)
			(*otv)->prev = tmp;
		tmp->next = (*otv);
		(*otv) = tmp;
	}
}

int			is_sorted(t_otv *otv)
{
	t_otv	*tmp;
	t_otv	*tmp2;

	if (!otv)
		return (0);
	tmp = otv;
	tmp2 = otv->next;
	while (tmp && tmp2)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->len > tmp2->len)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

t_graph		*get_next_graph(t_graph *graph)
{
	if (graph == NULL)
		return (NULL);
	while (graph->next)
		graph = graph->next;
	return (graph);
}
