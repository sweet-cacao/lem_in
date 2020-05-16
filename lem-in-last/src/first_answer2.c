/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_answer2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:27:46 by gstarvin          #+#    #+#             */
/*   Updated: 2020/03/13 17:31:41 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

t_graph		*make_first(t_gr_block *buff, t_gr_block one_block)
{
	t_graph *graph;

	graph = NULL;
	while (one_block.parent)
	{
		if (!check_duplicate_room(graph, one_block.name, one_block.code))
		{
			push_front_graph(&graph, one_block.name, one_block.name);
			graph->code_link = one_block.code;
		}
		one_block = buff[one_block.parent->num];
	}
	push_front_graph(&graph, one_block.name, one_block.name);
	if (one_block.start != 1)
		return (NULL);
	return (graph);
}

t_graph		*get_first_answer(t_graph *end_new, t_graph *whole_first)
{
	t_graph *graph;
	t_graph *tmp;

	graph = NULL;
	while (whole_first)
	{
		push_end_graph(&graph, whole_first->link, whole_first->link);
		tmp = end_new;
		while (tmp)
		{
			if (ft_strcmp(whole_first->link, tmp->link) == 0)
				break ;
			tmp = tmp->next;
		}
		if (tmp && ft_strcmp(whole_first->link, tmp->link) == 0)
			break ;
		whole_first = whole_first->next;
	}
	tmp = tmp->next;
	while (tmp)
	{
		push_end_graph(&graph, tmp->link, tmp->link);
		tmp = tmp->next;
	}
	return (graph);
}

t_graph		*get_second_answer(t_graph *whole_new, t_graph *end_first)
{
	t_graph *graph;
	t_graph *tmp;

	graph = NULL;
	while (ft_strcmp(whole_new->link, end_first->link) != 0)
	{
		push_end_graph(&graph, whole_new->link, whole_new->link);
		whole_new = whole_new->next;
	}
	tmp = end_first;
	while (tmp)
	{
		push_end_graph(&graph, tmp->link, tmp->link);
		tmp = tmp->next;
	}
	return (graph);
}

int			check_useful(t_otv **first, int ants)
{
	t_otv	*tmp;
	int		last_ants;
	int		sum;
	int		len;

	sum = 0;
	last_ants = ants - count_solutions(*first) + 1;
	tmp = get_next_solution(*first);
	len = tmp->len;
	while (tmp->prev)
	{
		tmp = tmp->prev;
		if (tmp->old != 1)
			sum += len - tmp->len;
	}
	if (last_ants > sum + 10)
		return (1);
	else
		return (0);
}

int			compare_graph(t_graph *one, t_graph *two)
{
	if (!one || !two)
		return (0);
	while (one && two)
	{
		if (ft_strcmp(one->link, two->link) != 0)
			return (0);
		one = one->next;
		two = two->next;
	}
	if (one == NULL && two == NULL)
		return (1);
	else
		return (0);
}
