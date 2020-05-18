/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:10:30 by gstarvin          #+#    #+#             */
/*   Updated: 2020/05/17 15:18:00 by sweet-cacao      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		give_len(t_otv **solutions)
{
	t_otv	*tmp;

	tmp = (*solutions);
	while (tmp)
	{
		tmp->len = count_links(tmp->solve);
		tmp = tmp->next;
	}
}

void		give_numbers_solution(t_otv **solutions)
{
	t_otv	*tmp;
	int		i;

	i = 1;
	tmp = (*solutions);
	while (tmp)
	{
		tmp->number = i;
		tmp = tmp->next;
		i++;
	}
}

void		swap_solutions(t_otv *tmp, t_otv *tmp2)
{
	int		len_tmp;
	t_graph *solve_tmp;
	int		old;

	old = tmp->old;
	len_tmp = tmp->len;
	solve_tmp = tmp->solve;
	tmp->old = tmp2->old;
	tmp->len = tmp2->len;
	tmp->solve = tmp2->solve;
	tmp2->len = len_tmp;
	tmp2->solve = solve_tmp;
	tmp2->old = old;
}

void		sort_with_len(t_otv **solutions)
{
	t_otv	*tmp;
	t_otv	*tmp2;

	tmp = (*solutions);
	tmp2 = tmp->next;
	if (is_sorted(*solutions) != 1)
	{
		while (tmp)
		{
			while (tmp2)
			{
				if (tmp->len > tmp2->len)
				{
					swap_solutions(tmp, tmp2);
				}
				tmp2 = tmp2->next;
			}
			tmp = tmp->next;
			if (tmp)
				tmp2 = tmp->next;
		}
	}
}

int			is_in_room(t_ants *buff, int i, int ants)
{
	int		j;

	j = 0;
	while (j < i)
	{
		if (buff[i].path == buff[j].path &&
		buff[i].room->next &&
		ft_strcmp(buff[i].room->next->link, buff[j].room->link) == 0 &&
		ft_strcmp(buff[i].room->next->link,
		get_next_graph(buff[i].room)->link) != 0)
			return (1);
		j++;
	}
	return (0);
}
