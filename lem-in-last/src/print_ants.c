/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:53:54 by gstarvin          #+#    #+#             */
/*   Updated: 2020/03/13 16:30:44 by gstarvin         ###   ########.fr       */
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
	{
		return (1);
	}
	while (walk->prev)
	{
		walk = walk->prev;
		sum = sum + (len_now - walk->len);
	}
//	printf("оставшиеся муравьи = %d, len_now = %d, cумма = %d\n", last_ants, len_now, sum);
	if (last_ants > sum)
	{
		return (tmp->number);
	}
/*	else
	{
		return (tmp->prev->number);
	}*/
	return (0);
}

void		give_paths(int ants, t_otv *solutions, t_ants *ants_buff)
{
	int		i;
	t_otv	*tmp;
	int		k;

	i = 1;
	//give_len(&solutions);
	tmp = solutions;
//	sort_with_len(&solutions);
	give_numbers_solution(&solutions);
	while (i <= ants)
	{
		ants_buff[i - 1].number = i;
		i++;
	}
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

void		give_rooms(int ants, t_otv *solutions, t_ants *buff)
{
	int		i;
	t_graph *graph;

	i = 0;
	give_paths(ants, solutions, buff);
	while (i < ants)
	{
		graph = return_graph(solutions, buff[i].path);
		buff[i].room = graph;
		i++;
	}
	printf("\n");
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

	give_rooms(ants, solutions, buff);
//	print_solutions(solutions);
//	i = 0;
/*	while (i < ants)
	{
		printf("номер муравья = %d, номер пути = %d\n", buff[i].number, buff[i].path);
		i++;
	}*/
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
	del_solutions(&solutions);
}
