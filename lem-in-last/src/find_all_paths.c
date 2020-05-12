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

void		exit_no_way(t_otv *otv, int len, t_gr_block *buff)
{
	if (otv == NULL)
	{
		printf("NO WAY\n");
		del_buff_links(len, buff);
		exit(0);
	}
}

void		check_simmilar(t_otv **otv, t_graph *graph, t_graph *walk)
{
	t_graph *tmp;
	t_graph *tmp2;

	tmp2 = graph->next;
	graph = graph->next;
	while(tmp2->next)
	{
		tmp = walk->next;
		while(tmp->next)
		{
			if (ft_strcmp(tmp->link, graph->link) == 0)
			{
				if (count_links(graph)>count_links(walk))
					del_sol_last_two(otv, graph, graph);
				else
					del_sol_last_two(otv, walk, walk);
			}
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
	}
}

void 		check_solutions_last(t_otv **otv)
{
	t_otv *tmp;
	t_otv *tmp2;
	t_graph *graph;
	t_graph *walk;

	tmp = (*otv);
	while(tmp)
	{
		graph = tmp->solve->next;
		tmp2 = tmp->next;
		while(tmp2)
		{
			walk = tmp2->solve;
			check_simmilar(otv, graph, walk);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void		belman_ford_req(t_gr_block *buff, int len, int ants)
{
	t_graph *first_answer;
	t_otv *first;
	int		k;
	int otriz;

	k = count_max_paths(buff, len);
	first = NULL;
	first_answer = NULL;
	while (k-- >= 0)
	{
		otriz = 0;
		bel_ford3(buff, len, &otriz);
		if (!(make_path_back(buff, len, buff[len-1])))//не нужно
			break ;
		first_answer = make_first(buff, len, buff[len - 1]);
		if (first_answer == NULL)
			break;
		if (check_same_link(first_answer, &first, ants) == 3)
			break;
		if (!make_path_back_minus(buff, len, buff[len-1]))
			break;
		reconstruct_initial(buff, len);
	}
	exit_no_way(first, len, buff);
	check_solutions_last(&first);
	print_ants_and_paths(ants, first);
}
