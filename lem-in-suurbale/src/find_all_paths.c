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
	buff[one_block.num].count++;
	while (one_block.parent)
	{
		one_block = buff[one_block.parent->num];
		if (one_block.count == 1)
			return (0);// return_t_gr_block_by_block(buff, len, one_block.parent);
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
	//	if (one_block.count)
	//
	//	buff[one_block.num].count++;
		links = one_block.links;
		while(links)
		{
			if (links->num_buff == one_block.parent->num)
			{

//				if (links->time == 1)
//					links->out = 0;
//				else
				links->out = 1;
				links->time++;
				links->in  = 0;
				links->weight_link = -1;
	//			links->no = -1;
				if (ft_strcmp(links->link, one_block.name) == 0) //здесь было парент нэйм и периодически работало но все равно на 2-3 больше
				{
					links->weight_link = 0;
				}
				links2 = buff[links->num_buff].links;
				while (links2)
				{
					if (links2->num_buff == one_block.num)
					{
						links2->out = 0;
						links2->in = 1;

				//		if (ft_strcmp(links2->link, buff[links->num_buff].name) == 0)
				//		{
				//			links2->out = 1;
				//			links2->in = 0;
				//		}
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
				break;
			}

		//	else
		//	{
		//		if (one_block.start != 1 && one_block.end != 1 && links->no == -1 && buff[links->num_buff].start != 1 && buff[links->num_buff].end != 1 )
		//		{
		//			links->out = 1;
		//			links->in = 0;
		//		}
		//	}
			links = links->next;
		}
		one_block = buff[one_block.parent->num];
	//	if (one_block.count == 1)
	//		return (0);//] return_t_gr_block_by_block(buff, len, one_block.parent);
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

int         check_duplicate_room(t_graph *graph, char *name)
{
	while(graph)
	{
		if (ft_strcmp(graph->link, name) == 0)
			return (1);
		graph = graph->next;
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
	//	if (one_block.end != 1 && one_block.start != 1)// &&
	//	is_in_solutions(otv, one_block.name))
	//		k++;
		if (!check_duplicate_room(graph, one_block.name))
			push_front_graph(&graph, one_block.name, one_block.name);
		if (one_block.end != 1 && one_block.start != 1)
			buff[one_block.num].dead_end = 1;
		one_block = buff[one_block.parent->num];// return_t_gr_block_by_block(buff, len, one_block.parent);
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
		if (buff[i].dead_end != 1)
		{
			while (links)
			{
				if (!(links->in == 0 && links->out == 0))
				{
					if (links->no == -1) //может быть еще и 0
					{
						links->out = 0;
						links->in = 1;
					}
					else
					{
						if (buff[i].num == links->num_buff)
							links->weight_link = 0;
						else
							links->weight_link = 1;
						links->in = 0;
						links->out = 1;
					}
				}
				links = links->next;
			}
		}
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

void		belman_ford_req(t_gr_block *buff, int len, int ants)
{
	t_graph	*answer;
	t_otv	*otv;
	int		k;
	int     i;
	i = 0;
	int j;
	int otriz;
	j = 0;
	k = count_max_paths(buff, len);
	//int len_paths[k];
	t_otv *first;
	otv = NULL;
	int check;

	check = 0;
	t_graph *first_answer;
	first = NULL;
	first_answer = NULL;
	//print_graph(buff, len);
	while (k-- >= 0)
	{
		otriz = 0;
		bel_ford3(buff, len, &otriz);
	//	if (!(make_path_back(buff, len, buff[len-1])))
	//		break ;
		first_answer = make_first(buff, len, buff[len - 1]);
		if (first_answer == NULL)
			break;
		if (check_same_link(first_answer, &first, ants) == 3)
			break;
		if (!make_path_back_minus(buff, len, buff[len-1]))
			break;
		j = 0;
		while (j < len)
		{
			buff[j].count = 0;
			buff[j].weight_edge = INT32_MAX;
			buff[j].parent_name = NULL;
			buff[j].parent = NULL;
			buff[j].iter = -1;
			j++;
		}
		buff[0].weight_edge = 0;

		i++;
		//if (i == 15)
		//	break;
	}
//	print_graph(buff, len);
/*	reconstruct_initial(buff, len);
	while (i-- >= -1)
	{
//		print_graph(buff, len);

		bel_ford3(buff, len, &otriz);
		if (!(make_path_back(buff, len,buff[len - 1])))
			break ;
		answer = make_path_back_del(buff, len, buff[len - 1], otv);
		//return_t_gr_block(buff, len, get_end(buff, len)), otv);
		if (answer)
		{
			push_end_solution(&otv, answer);
		}
		j = 0;
		while (j < len)
		{
			buff[j].count = 0;
			buff[j].weight_edge = INT32_MAX;
			buff[j].parent_name = NULL;
			buff[j].parent = NULL;
			buff[j].iter = -1;
			j++;
		}
		buff[0].weight_edge = 0;
	}*/
//	print_solutions(otv);
//	print_solutions(first);
//	del_graph(&answer);
//	exit_no_way(otv, len, buff);
	print_ants_and_paths(ants, first);
}
