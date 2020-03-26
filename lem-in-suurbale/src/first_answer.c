#include "../includes/lem-in.h"

t_graph		*make_first(t_gr_block *buff, int len,
								   t_gr_block one_block)
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
	//	if (one_block.end != 1 && one_block.start != 1)
	//		buff[one_block.num].dead_end = 1;
		one_block = buff[one_block.parent->num];// return_t_gr_block_by_block(buff, len, one_block.parent);
	}
	push_front_graph(&graph, one_block.name, one_block.name);
	if (one_block.start != 1)
		return (NULL);
	return (graph);
}

t_graph *get_first_answer(t_graph *end_new, t_graph *whole_first)
{
	t_graph *graph;

	graph = NULL;
	while (ft_strcmp(whole_first->link, end_new->link) != 0)
	{
		push_end_graph(&graph, whole_first->link, whole_first->link);
		whole_first = whole_first->next;
	}
	t_graph *tmp;
	tmp = end_new;
	whole_first = whole_first->next;
	while(whole_first)
	{
		tmp = end_new;
		while(tmp)
		{
			if (ft_strcmp(whole_first->link, tmp->link) == 0)
				break;
			tmp = tmp->next;
		}
		whole_first = whole_first->next;
	}
	end_new = end_new->next->next;
	while(tmp)
	{
		push_end_graph(&graph, tmp->link, tmp->link);
		tmp = tmp->next;
	}
	return (graph);
}

t_graph *get_second_answer(t_graph *whole_new, t_graph *end_first)
{
	t_graph *graph;

	graph = NULL;
	while (ft_strcmp(whole_new->link, end_first->link) != 0)
	{
		push_end_graph(&graph, whole_new->link, whole_new->link);
		whole_new = whole_new->next;
	}
	t_graph *tmp;
	tmp = end_first;
/*	whole_new = whole_new->next;
	while(whole_new)
	{
		tmp = end_first;
		while(tmp)
		{
			if (ft_strcmp(whole_new->link, tmp->link) == 0)
				break;
			tmp = tmp->next;
		}
		whole_new = whole_new->next;
	}*/
//	end_first = end_first->next;

	while(tmp)
	{
		push_end_graph(&graph, tmp->link, tmp->link);
		tmp = tmp->next;
	}
	return (graph);
}


int 	check_useful(t_otv **first, int ants)
{
	t_otv *tmp;
	int last_ants;
	int sum;
	int len;

	sum = 0;
	tmp = get_next_solution(*first);
	len = tmp->len;
	last_ants = ants - count_solutions(*first) + 1;
	while(tmp->prev)
	{
		tmp = tmp->prev;
		if (tmp->old == 0)
		{
			sum += len - tmp->len;
		}
	}
	if (last_ants > sum)
	{
		return (1);
	}
	else
		return (0);
}

void	del_sol_last_two(t_otv **otv, t_graph *first, t_graph *second)//нужно проверку на налл два раза и пофришить
{
	t_otv *tmp;
	int len_one;
	int len_two;

	len_one = count_links(first);
	len_two = count_links(second);
	tmp = *otv;
	while (tmp)
	{
		if (tmp->len == len_one)
		{
			if (!tmp->prev)//пофришить
			{
				tmp = tmp->next;
				free(tmp->prev);
				tmp->prev = NULL;
				(*otv) = tmp;
			} else if (!tmp->next)
			{
				tmp = NULL;
			}
			else {
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
			}
			free(tmp);
			break;
		}
		tmp = tmp->next;
	}
	tmp = *otv;
	while (tmp)
	{
		if (tmp->len == len_two)
		{
			if (!tmp->prev)//пофришить
			{
				tmp = tmp->next;
				free(tmp->prev);
				tmp->prev = NULL;
				(*otv) = tmp;
			} else if (!tmp->next)
			{
				tmp = NULL;
			}
			else {
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
			}
		//	free(tmp);
			break;
		}
		tmp = tmp->next;
	}
//	tmp = get_next_solution(*otv);
//	tmp->prev->prev = NULL;
//	tmp->prev = NULL;
}

void	del_sol_old(t_otv **first)
{
	t_otv *tmp;

	tmp = *first;
	while (tmp) {
		if (tmp->old == 1) {
			if (!tmp->prev)//пофришить, вроде это не особо правильно работает
			{
				tmp = tmp->next;
				free(tmp->prev);
				tmp->prev = NULL;
				(*first) = tmp;
			} else if (!tmp->next)
			{
				tmp = NULL;
				//free(tmp);
			} else
			{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;

			}

			break;
		}
		tmp = tmp->next;
	}
}

int	check_same_link(t_graph *answer, t_otv **first, int ants)
{
	t_otv *tmp;
	t_graph *graph;
	t_graph *walk;
	t_graph *new_answer_1;
	t_graph *new_answer_2;

	new_answer_1 = NULL;
	new_answer_2 = NULL;
	tmp = *first;
	while(tmp)
	{
		graph = answer->next;
		walk = tmp->solve->next;
		while (graph->next)
		{
			walk = tmp->solve->next;
			while (walk->next)
			{
				if (ft_strcmp(graph->link, walk->link) == 0) {

					new_answer_1 = get_first_answer(graph, tmp->solve);//конец нового графа
					new_answer_2 = get_second_answer(answer, walk);//
					tmp->old = 1;
			//		printf("\ntmp_len = %d\n", tmp->len);
					push_end_solution(first, new_answer_1);
					push_end_solution(first, new_answer_2);
					sort_with_len(first);
					if (check_useful(first, ants) == 0)
					{
						del_sol_last_two(first, new_answer_1, new_answer_2);//не правильно нужно четко знать какие именно удалять
						tmp->old = 0;
						return (3);
					} else {
						del_sol_old(first);
						return (1);
					}
				}
				walk = walk->next;
			}
			graph = graph->next;
		}
		tmp = tmp->next;
	}
	push_end_solution(first, answer);
//	sort_with_len(first);
	tmp = get_next_solution(*first);
	if (check_useful(first, ants) == 0)
	{
	//	free(tmp);
		tmp = NULL;
		return (3);
	}
	return (2);
}
