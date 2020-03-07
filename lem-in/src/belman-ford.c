#include "../includes/lem-in.h"
/*
void    give_directions(t_gr_block *buff, int len)
{
	int i;
	t_graph *links;

	i = 0;
	while (i < len)
	{
		links = buff[i].links;
		while (links)
		{
			if (return_level(buff, links->link, len) > buff[i].level)
			{
				links->in = 0;
				links->out = 1;
			}
			if (return_level(buff, links->link, len) < buff[i].level)
			{
				links->in = 1;
				links->out = 0;
			}
			links = links->next;
		}
		i++;
	}
}
*/

void    make_path_back_minus(t_gr_block *buff, int len, t_gr_block one_block)
{
	t_graph *links;
	t_gr_block tmp;

	while (one_block.parent)
	{
		links = one_block.links;
		while (links)
		{
			if (ft_strcmp(one_block.parent_name, links->link) == 0)
			{
				if (links->weight_link == -1)
				{
					links->out = 0;
					links->in = 0;
				}
				else
				{
					links->weight_link = -1;
					links->out = 1;
					links->in = 0;
				}
				tmp = return_t_gr_block(buff, len, links->link);
                links = tmp.links;
				while (links)
				{
					if (ft_strcmp(one_block.name, links->link) == 0)
					{
						if (links->weight_link == -1)
						{
							links->out = 0;
							links->in = 0;
						} else
						{
							links->weight_link = -1;
							links->out = 0;
							links->in = 1;
						}
						break;
					}
					links = links->next;
				}
				break;
			}
			links = links->next;
		}
		one_block = return_t_gr_block(buff, len, one_block.parent_name);
	}
}

int        is_in_solutions(t_otv *otv, char *name)
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

t_graph    *make_path_back_del(t_gr_block *buff, int len, t_gr_block one_block, t_otv *otv)
{
	t_graph *links;
	t_gr_block tmp;
	t_graph *graph;

	graph = NULL;
	while (one_block.parent)
	{
		if (one_block.end != 1 && one_block.start != 1 && is_in_solutions(otv, one_block.name))
			return (NULL);
		push_front_graph(&graph, one_block.name, one_block.name);
		links = one_block.links;
		while (links)
		{
			if (ft_strcmp(one_block.parent_name, links->link) == 0)
			{
				links->weight_link = -1;
				links->out = 0;
				links->in = 0;
				tmp = return_t_gr_block(buff, len, links->link);
				links = tmp.links;
				while (links)
				{
					if (ft_strcmp(one_block.name, links->link) == 0)
					{
						links->weight_link = -1;
						links->out = 0;
						links->in = 0;
						break;
					}
					links = links->next;
				}
				break;
			}
			links = links->next;
		}
		one_block = return_t_gr_block(buff, len, one_block.parent_name);
	}
	push_front_graph(&graph, one_block.name, one_block.name);
	return (graph);
}

int    add_weight(t_gr_block *buff, int len, t_graph *links, int iter, t_gr_block tmp, t_gr_block one_block)
{
	int i;
	int n;

	n = 0;
	i = 0;
	tmp.parent = &one_block;
	tmp.parent_name = one_block.name;
	while (i < len)
	{
		if (ft_strcmp(buff[i].name, links->link) == 0 )//&& (buff[i].iter != iter || buff[i].iter == -1))
		{
			n = tmp.parent->weight_edge + links->weight_link;
			if (buff[i].weight_edge == INT32_MAX || n < buff[i].weight_edge)//(buff[i].iter == -1 || (buff[i].iter != -1 && n < buff[i].weight_edge))
			{

				buff[i].weight_edge = tmp.parent->weight_edge + links->weight_link;
				buff[i].iter = iter;
				return (1);
			}
		}
		i++;
	}
	return (0);
}

void    set_parent(t_gr_block *buff, int len, t_gr_block tmp, t_gr_block one_block)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (ft_strcmp(tmp.name, buff[i].name) == 0)
		{
			buff[i].parent = &one_block;
			buff[i].parent_name = one_block.name;
		}
		i++;
	}
}

void    set_prev(t_gr_block *buff, int len, t_gr_block tmp, t_gr_block one_block)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (ft_strcmp(tmp.name, buff[i].name) == 0)
		{
			buff[i].prev = one_block.name;
		}
		i++;
	}
}

void    set_count(t_gr_block *buff, int len, t_gr_block one_block)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (ft_strcmp(one_block.name, buff[i].name) == 0)
			buff[i].count++;
		i++;
	}
}
int     check_edge(t_graph *graph, char *name)
{
	if (!graph)
		return (1);
	while(graph)
	{
		if (ft_strcmp(name, graph->link) == 0)
			return (0);
		graph = graph->next;
	}
	return (1);
}

void    req(t_gr_block *buff, int len, t_gr_block one_block, int i, t_graph *list_edges)
{
	t_graph *links;
	t_gr_block tmp;
	int j;
	int k;

	k = 0;
	j = 0;
	if (one_block.end == 1 || one_block.count >= 1 || check_edge(list_edges, one_block.name) == 0) //|| one_block.start == 1)
	{
	/*	while (j < len)
		{
			buff[j].count = 0;
			j++;
		}
		printf("here");
		buff[0].weight_edge = 0;*/
		return ;
	}
	else
	{
		links = one_block.links;
		push_front_graph(&list_edges, one_block.name, one_block.name);
		while (links)
		{
			tmp = return_t_gr_block(buff, len, links->link);
			if (links->out == 1 && (one_block.parent == NULL || (one_block.parent && ft_strcmp(one_block.parent->name, tmp.name) != 0)))
			{
					if (tmp.start != 1)
					{
						k = add_weight(buff, len, links, i, tmp, one_block);
						tmp = return_t_gr_block(buff, len, links->link);
						tmp.parent = &one_block;
						tmp.parent_name = one_block.name;
						set_count(buff, len, one_block);
						if (k)
							set_parent(buff, len, tmp, one_block);
					//	tmp = return_t_gr_block(buff, len, links->link);
				//		if (one_block.prev == NULL || (one_block.prev && ft_strcmp(one_block.prev, tmp.name) != 0))
				//		{
				//			set_prev(buff, len, tmp, one_block);
					//	if (check_edge(list_edges, tmp.name) == 0)
					//	{

						req(buff, len, tmp, i, list_edges);
					//	}

				//		}
				//		else
				//			return;

					}

				//	printf("%d\n", one_block.count);
			}
			links = links->next;
		}
	}
}

void    reconstruct_initial(t_gr_block *buff, int len)
{
	int i;
	t_graph *links;

	i = 0;
	while (i < len)
	{
		buff[i].count = 0;
		buff[i].weight_edge = INT32_MAX;
		buff[i].parent_name = NULL;
		buff[i].parent = NULL;
		links = buff[i].links;
		while (links)
		{
			if ((links->in == 0 && links->out == 1) || (links->in == 1 && links->out == 0) || (links->in == 1 && links->out == 1))
			{
				links->weight_link = 1;
				links->in = 1;
				links->out = 1;
			}
			links = links->next;
		}
		i++;
	}
	buff[0].weight_edge = 0;
}

int     count_links(t_graph *graph)
{
	int i;

	i = 0;
	while (graph)
	{
		i++;
		graph = graph->next;
	}
	return (i);
}

int    count_max_paths(t_gr_block *buff, int len)
{
	int max_n_end_paths;
	int max_n_start_paths;
	int max_n_paths;

	max_n_end_paths = count_links(find_end(buff, len).links);
	max_n_start_paths = count_links(return_t_gr_block(buff, len, get_start(buff, len)).links);
	if (max_n_end_paths > max_n_start_paths)
		max_n_paths = max_n_start_paths;
	else
		max_n_paths = max_n_end_paths;
	return (max_n_paths);
}

void    belman_ford_req(t_gr_block *buff, int len, int ants)
{
	int i;
	t_graph *answer;
	i = 0;
	t_otv *otv;
	int k;
	int max_n_paths;
	t_graph *list_edges;

	list_edges = NULL;
	max_n_paths = count_max_paths(buff, len);
	otv = NULL;
	k = 0;
	//printf("\n%d\n" , return_t_gr_block(buff, len, get_start(buff, len)).weight_edge);
//	req(buff, len, return_t_gr_block(buff, len, get_start(buff, len)), i, list_edges);
	while (k < max_n_paths)
	{
		list_edges = NULL;
		req(buff, len, return_t_gr_block(buff, len, get_start(buff, len)), i, list_edges);

		if (find_end(buff, len).parent_name == NULL)
			break ;
		make_path_back_minus(buff, len, return_t_gr_block(buff, len, get_end(buff, len)));
	//	print_graph(buff, len);
	//	print_graph(buff, len);

		i = 0;
		while (i < len)
		{
			buff[i].count = 0;
			buff[i].weight_edge = INT32_MAX;
			buff[i].parent_name = NULL;
			buff[i].parent = NULL;
			i++;
		}
		buff[0].weight_edge = 0;
		k++;
	}

	while (k > 0)
	{
		list_edges = NULL;
		reconstruct_initial(buff, len);
	//	printf("AFTER RECONSTRUCTION");
	//	print_graph(buff, len);
		req(buff, len, return_t_gr_block(buff, len, get_start(buff, len)), i, list_edges);
	//	if (k == 1)
	//		print_graph(buff, len);
		answer = make_path_back_del(buff, len, return_t_gr_block(buff, len, get_end(buff, len)), otv);
		if (answer)
			push_front_solution(&otv, answer);
		k--;
	}
//	print_solutions(otv);
	printf("\n");
	print_ants_and_paths(ants, otv);
}
/*
void    belman_ford_second(t_gr_block *buff, int len)
{
	int i;
	int j;
	t_graph *links;

	j = 0;
	i = 0;
	while (i < len)
	{
		j = 0;
		links = buff[i].links;
		while (links)
		{
			if (links->weight_link < INT32_MAX)
			{

			}
			if (buff[j].weight_edge == INT32_MAX || buff[j].weight_edge < )
			links = links->next;
		}
		i++;
	}
}
 */
/*
void    belman_ford(int len, t_gr_block *buff)
{
	int     i;
	int     j;
	t_graph *links;
	t_gr_block tmp;
	j = 0;
	i = 0;
	while (i < len)
	{
		j = 0;
		while (buff[j].end != 1)
		{
			links = buff[j].links;
			while (links)
			{
				tmp = return_t_gr_block(buff, len, links->link);
				if (links->out == 1) {
					add_weight(buff, len, links, i);
				}
				links = links->next;
			}
		}
		i++;
	}
}*/

