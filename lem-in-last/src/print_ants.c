/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:53:54 by gstarvin          #+#    #+#             */
/*   Updated: 2020/05/16 12:55:34 by sweet-cacao      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

int			choose_path(int last_ants, t_otv *tmp)
{
	t_otv	*walk;
	int		len_now;
	int		sum;

	len_now = tmp->len;
	sum = 0;
	walk = tmp;
	if (walk->number == 1)
		return (1);
	while (walk->prev)
	{
		walk = walk->prev;
		sum = sum + (len_now - walk->len);
	}
	if (last_ants > sum)
		return (tmp->number);
	return (0);
}

void		give_paths(int ants, t_otv *solutions, t_ants *ants_buff)
{
	int		i;
	t_otv	*tmp;
	int		k;

	i = 0;
	tmp = solutions;
	give_numbers_solution(&solutions);
	while (i++ <= ants)
		ants_buff[i - 1].number = i;
	i = 1;
	while (i <= ants)
	{
		k = choose_path(ants - i + 1, tmp);
		if (k != 0)
		{
			ants_buff[i - 1].path = k;
			i++;
		}
		if (tmp->next && k != 0)
			tmp = tmp->next;
		else
			tmp = solutions;
	}
}

t_otv		*give_rooms(int ants, t_otv *solutions, t_ants *buff)
{
	int		i;
	t_graph *graph;

	i = 0;
	give_paths(ants, solutions, buff);
	while (i < ants)
	{
		buff[i].room = return_graph(solutions, buff[i].path);
		i++;
	}
	printf("\n");
	return (solutions);
}

void		print_ants(t_ants *buff, int ants)
{
	int		i;

	i = 0;
	while (i < ants)
	{
		if (buff[i].room->next && is_in_room(buff, i, ants) == 0)
		{
			buff[i].room = buff[i].room->next;
			printf("L%d-%s ", buff[i].number, buff[i].room->link);
		}
		i++;
	}
}

void		print_ants_and_paths(int ants, t_otv *solutions)
{
	int		i;
	t_ants	buff[ants];

	solutions = give_rooms(ants, solutions, buff);
	while (1)
	{
		i = 0;
		while (i < ants)
		{
			if (ft_strcmp(buff[i].room->link,
				get_next_graph(solutions->solve)->link) != 0)
				break ;
			i++;
		}
		if (i == ants)
			break ;
		print_ants(buff, ants);
		printf("\n");
	}
}
