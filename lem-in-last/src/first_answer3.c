/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_answer3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:27:46 by gstarvin          #+#    #+#             */
/*   Updated: 2020/05/16 20:46:35 by sweet-cacao      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void	delete_first_gr(t_otv **sort)
{
	t_otv	*tmp;

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

t_graph *find_delete(t_otv **otv, t_graph *first, t_otv *tmp)
{
	t_graph *graph;

	graph = NULL;
	while (tmp)
	{
		if (compare_graph(tmp->solve, first) == 1)
		{
			graph = tmp->solve;
//			if (tmp->solve)
//				del_graph(&tmp->solve);
			if (!tmp->prev)
			{
				delete_first_gr(otv);
			}
			else if (!tmp->next)
			{
//				del_graph(&tmp->solve);
				tmp->prev->next= NULL;
				free(tmp);
				tmp = NULL;
			}
			else
			{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
//				del_graph(&tmp->solve);
				free(tmp);
				tmp = NULL;
			}
			break ;
		}
		tmp = tmp->next;
	}
	return (graph);
}

void	del_sol_last_two(t_otv **otv, t_graph *first,
		t_graph *second)//нужно проверку на налл два раза и пофришить
{
	t_otv *tmp;
	t_graph *graph;

	tmp = *otv;
	graph = find_delete(otv, first, tmp);
//	del_graph(&graph);
	tmp = *otv;
	graph = find_delete(otv, second, tmp);
//	del_graph(&graph);
}

void	choose_place_for_del(t_otv **first, t_otv *tmp)
{
	if (!tmp->prev)//пофришить, вроде это не особо правильно работает
	{
		del_graph(&(*first)->solve);
		delete_first_gr(first);
	}
	else if (!tmp->next)
	{
		del_graph(&tmp->solve);
		tmp->prev->next = NULL;
		free(tmp);
	}
	else
	{
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		del_graph(&tmp->solve);
		free(tmp);
	}
}

void	del_sol_old(t_otv **first)
{
	t_otv	*tmp;
	int		count;

	count = 0;
	tmp = *first;
	while (tmp)
	{
		if (tmp->old == 1 && count == 0)
		{
			count++;
			choose_place_for_del(first, tmp);
			break ;
		}
		tmp = tmp->next;
	}
}
