/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:04:40 by gstarvin          #+#    #+#             */
/*   Updated: 2020/03/13 17:33:37 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

int			make_path_back(t_gr_block *buff, int len, t_gr_block one_block)
{
	while (one_block.parent)
	{
		one_block = return_t_gr_block(buff, len, one_block.parent_name);
	}
	if (one_block.start == 1)
		return (1);
	else
		return (0);
}

int			is_in_solutions(t_otv *otv, char *name)
{
	t_graph *links;

	while (otv)
	{
		links = otv->solve;
		while (links)
		{
			if (ft_strcmp(links->link, name) == 0)
				return (1);
			links = links->next;
		}
		otv = otv->next;
	}
	return (0);
}

t_graph		*make_path_back_del(t_gr_block *buff, int len,
			t_gr_block one_block, t_otv *otv)
{
	t_graph *graph;
	int		k;

	k = 0;
	graph = NULL;
	while (one_block.parent)
	{
		if (one_block.end != 1 && one_block.start != 1 &&
		is_in_solutions(otv, one_block.name))
			k++;
		push_front_graph(&graph, one_block.name, one_block.name);
		if (one_block.end != 1 && one_block.start != 1)
			buff[return_j(buff, len, one_block.name)].dead_end = 1;
		one_block = return_t_gr_block(buff, len, one_block.parent_name);
	}
	push_front_graph(&graph, one_block.name, one_block.name);
	if (k > 0)
		return (NULL);
	return (graph);
}

void		reconstruct_initial(t_gr_block *buff, int len)
{
	int		i;
	t_graph *links;

	i = 0;
	while (i < len)
	{
		buff[i].count = 0;
		buff[i].weight_edge = INT32_MAX;
		buff[i].parent_name = NULL;
		buff[i].parent = NULL;
		buff[i].iter = -1;
		links = buff[i].links;
		while (links)
		{
			if (!(links->in == 0 && links->out == 0))
			{
				links->weight_link = 1;
				links->in = 1;
				links->out = 1;
			}
			links = links->next;
		}
		i++;
	}
	buff[return_j(buff, len, get_start(buff, len))].weight_edge = 0;
}

void		exit_no_way(t_otv *otv, int len, t_gr_block *buff)
{
	if (otv == NULL)
	{
		printf("NO WAY\n");
		del_buff_links(len, buff);
		exit(0);
	}
}

void		belman_ford_req(t_gr_block *buff, int len, int ants)
{
	t_graph	*answer;
	t_otv	*otv;
	int		k;

	k = count_max_paths(buff, len);
	otv = NULL;
	while (k-- >= 0)
	{
		reconstruct_initial(buff, len);
		bel_ford3(buff, len);
		if (!(make_path_back(buff, len,
		return_t_gr_block(buff, len, get_end(buff, len)))))
			break ;
		answer = make_path_back_del(buff, len,
		return_t_gr_block(buff, len, get_end(buff, len)), otv);
		if (answer)
		{
			push_front_solution(&otv, answer);
		}
	}
//	del_graph(&answer);
	exit_no_way(otv, len, buff);
	print_ants_and_paths(ants, otv);
}
