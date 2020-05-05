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

void overlay_solve(const t_gr_block *buff, t_gr_block *one_block, t_graph *links, t_graph *links2)
{
	links->out = 1;
	links->time++;
	links->in  = 0;
	links->weight_link = -1;
	if (links->code_link == (*one_block).code)
		links->weight_link = 0;
	links2 = buff[links->num_buff].links;
	while (links2)
	{
		if (links2->num_buff == (*one_block).num)
		{
			links2->out = 0;
			links2->in = 1;
			if (links->time > 1 || links2->time >= 1)
			{
				links->out = 0;
				links2->in = 0; // ссылка обратно должна убираться тожеi
			}
			links2->time++;
			break;
		}
		links2 = links2->next;
	}
}

int			make_path_back(t_gr_block *buff, int len, t_gr_block one_block)
{
	buff[one_block.num].count++;
	while (one_block.parent)
	{
		one_block = buff[one_block.parent->num];
		if (one_block.count == 1)
		{
			return (0);
		}
		buff[one_block.num].count++;
	}
	if (one_block.start == 1)
		return (1);
	else
		return (0);
}

int			make_path_back_minus(t_gr_block *buff, int len, t_gr_block one_block)
{
	t_graph *links;
	t_graph *links2;

	links = one_block.links;
	while (one_block.parent && one_block.start != 1)
	{
		links = one_block.links;
		while(links)
		{
			if (links->num_buff == one_block.parent->num)
			{
				overlay_solve(buff, &one_block, links, links2);
				break;
			}
			links = links->next;
		}
		one_block = buff[one_block.parent->num];
	}
	if (one_block.start == 1)
		return (1);
	else
		return (0);
}

int			check_duplicate_room(t_graph *graph, char *name, int code_gr)
{
	while(graph)
	{
		if (graph->code_link == code_gr)
			return (1);
		graph = graph->next;
	}
	return (0);
}

void		reconstruct_initial(t_gr_block *buff, int len)
{
	int		i;
	t_graph *links;

	i = 0;
	while (i < len) {
		buff[i].count = 0;
		buff[i].weight_edge = INT32_MAX;
		buff[i].parent_name = NULL;
		buff[i].parent = NULL;
		buff[i].iter = -1;
		i++;
	}
	buff[0].weight_edge = 0;
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
