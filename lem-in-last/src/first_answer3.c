/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_answer3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:27:46 by gstarvin          #+#    #+#             */
/*   Updated: 2020/05/16 21:20:06 by sweet-cacao      ###   ########.fr       */
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

void	find_delete(t_otv **otv, t_graph *first, t_otv *tmp)
{
	while (tmp)
	{
		if (compare_graph(tmp->solve, first) == 1)
		{
			if (!tmp->prev)
			{
				delete_first_gr(otv);
			}
			else if (!tmp->next)
			{
				tmp->prev->next = NULL;
				free(tmp);
				tmp = NULL;
			}
			else
			{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				free(tmp);
				tmp = NULL;
			}
			break ;
		}
		tmp = tmp->next;
	}
}

void	del_sol_last_two(t_otv **otv, t_graph *first,
		t_graph *second)
{
	t_otv *tmp;

	tmp = *otv;
	find_delete(otv, first, tmp);
	tmp = *otv;
	find_delete(otv, second, tmp);
}

void	choose_place_for_del(t_otv **first, t_otv *tmp)
{
	if (!tmp->prev)
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

	tmp = *first;
	while (tmp)
	{
		if (tmp->old == 1)
		{
			choose_place_for_del(first, tmp);
			break ;
		}
		tmp = tmp->next;
	}
}
