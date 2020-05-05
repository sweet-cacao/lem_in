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
		if (!check_duplicate_room(graph, one_block.name, one_block.code))
		{
			push_front_graph(&graph, one_block.name, one_block.name);
			graph->code_link = one_block.code;
		}
		one_block = buff[one_block.parent->num];
	}
	push_front_graph(&graph, one_block.name, one_block.name);
	if (one_block.start != 1)
		return (NULL);
	return (graph);
}

t_graph *get_first_answer(t_graph *end_new, t_graph *whole_first)
{
	t_graph *graph;
	t_graph *tmp;

	graph = NULL;
	while(whole_first)
	{
		push_end_graph(&graph, whole_first->link, whole_first->link);
		tmp = end_new;
		while(tmp)
		{
			if (ft_strcmp(whole_first->link, tmp->link) == 0)
				break;
			tmp = tmp->next;
		}
		if (tmp && ft_strcmp(whole_first->link, tmp->link) == 0)
			break;
		whole_first = whole_first->next;
	}
	tmp = tmp->next;
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
	while(tmp)
	{
		push_end_graph(&graph, tmp->link, tmp->link);
		tmp = tmp->next;
	}
	return (graph);
}


int 	check_useful(t_otv **first, int ants)
{
	t_otv	*tmp;
	int		last_ants;
	int		sum;
	int		len;

	sum = 0;
	last_ants = ants - count_solutions(*first) + 1;
	tmp = get_next_solution(*first);
	len = tmp->len;
	while(tmp->prev)
	{
		tmp = tmp->prev;
		if (tmp->old != 1)
			sum += len - tmp->len;
	}
	if (last_ants > sum+10)
		return (1);
	else
		return (0);
}

int 	compare_graph(t_graph *one, t_graph *two)
{
	if (!one || !two)
		return (0);
	while (one && two)
	{
		if (ft_strcmp(one->link, two->link) != 0)
			return (0);
		one = one->next;
		two = two->next;
	}
	if (one == NULL && two == NULL)
		return (1);
	else
		return (0);
}

void		delete_first_gr(t_otv **sort)
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
			if (!tmp->prev)//пофришить
			{
				delete_first_gr(otv);
			}
			else if (!tmp->next)
			{
				tmp->prev->next = NULL;
			}
			else
			{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
			}
			free(tmp);
			break;
		}
		tmp = tmp->next;
	}
}

void	del_sol_last_two(t_otv **otv, t_graph *first, t_graph *second)//нужно проверку на налл два раза и пофришить
{
	t_otv *tmp;

	tmp = *otv;
	find_delete(otv, first, tmp);
	find_delete(otv, second, tmp);
}

void	del_sol_old(t_otv **first)
{
	t_otv *tmp;
	int count;

	count = 0;
	tmp = *first;
	while (tmp)
	{
		if (tmp->old == 1 && count == 0)
		{
			count++;
			if (!tmp->prev)//пофришить, вроде это не особо правильно работает
			{
				delete_first_gr(first);
			}
			else if (!tmp->next)
			{
				tmp->prev->next = NULL;
			}
			else
			{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
			}
			break;
		}
		tmp = tmp->next;
	}
}

int		new_solutions_branch(t_otv **first, t_graph *new_answer_1, t_graph *new_answer_2, int ants)
{
	push_end_solution(first, new_answer_1);
	push_end_solution(first, new_answer_2);
	sort_with_len(first);
	if (check_useful(first, ants) == 0)
	{
		del_sol_last_two(first, new_answer_1, new_answer_2);
		return (3);
	}
	return (2);
}

int 	is_in_solutions_graph_links(t_otv **first, t_otv *tmp, t_graph *answer, int ants)
{
	t_glob	glob;

	glob.graph = answer->next;
	glob.tmp = tmp;
	while (glob.graph->next)
	{
		glob.walk = glob.tmp->solve->next;
		while (glob.walk->next)
		{
			if (ft_strcmp(glob.walk->link, glob.graph->link) == 0)
			{
				glob.new_answer_1 = get_first_answer(glob.graph, tmp->solve);//конец нового графа
				glob.new_answer_2 = get_second_answer(answer, glob.walk);
				del_sol_last_two(first, glob.tmp->solve, glob.tmp->solve);
				return (new_solutions_branch(first, glob.new_answer_1, glob.new_answer_2, ants));
			}
			glob.walk = glob.walk->next;
		}
		glob.graph = glob.graph->next;
	}
	return (0);
}

int		is_in_solutions_graph(t_otv **first, t_graph *tmp, int ants)
{
	t_otv *otv;
	int res;

	otv = *first;
	res = 0;
	while (otv)
	{
		if (otv->old == 0)
		{
			res = is_in_solutions_graph_links(first, otv, tmp, ants);
			if (res == 2)
				break;
			if (res == 3)
				return (0);
		}
		otv = otv->next;
	}
	return (res);
}

int		new_solutions(t_otv **first, t_graph *new_answer_1, t_graph *new_answer_2, int ants)
{
	if (is_in_solutions_graph(first, new_answer_1, ants) == 0)
		push_end_solution(first, new_answer_1);
	if (is_in_solutions_graph(first, new_answer_2, ants) == 0)
		push_end_solution(first, new_answer_2);
	sort_with_len(first);
	if (check_useful(first, ants) == 0)
	{
		del_sol_last_two(first, new_answer_1, new_answer_2);
		return (3);
	}
	else
	{
		del_sol_old(first);
		return (1);
	}
}

int		simple_solution(t_otv **first, int ants)
{
	t_otv *tmp;

	tmp = get_next_solution(*first);
	if (check_useful(first, ants) == 0)
	{
		//	free(tmp);
		tmp = NULL;
		return (3);
	}
	return (2);
}

int		check_same_link_inner_while(t_otv **first, int ants, t_glob glob, t_graph *answer)
{
	glob.walk = glob.tmp->solve->next;
	while (glob.walk->next)
	{
		if (ft_strcmp(glob.graph->link, glob.walk->link) == 0)
		{
			glob.new_answer_1 = get_first_answer(glob.graph, glob.tmp->solve);//конец нового графа
			glob.new_answer_2 = get_second_answer(answer, glob.walk);
			glob.tmp->old = 1;
			return (new_solutions(first, glob.new_answer_1, glob.new_answer_2, ants));
		}
		glob.walk = glob.walk->next;
	}
	return (0);
}

int		check_same_link(t_graph *answer, t_otv **first, int ants)
{
	t_glob	glob;
	int 	k;

	k = 0;
	glob.tmp = *first;
	while(glob.tmp)
	{
		glob.graph = answer->next;
		while (glob.graph->next)
		{
			k = check_same_link_inner_while(first, ants, glob, answer);
			if (k != 0)
				return (k);
			glob.graph = glob.graph->next;
		}
		glob.tmp = glob.tmp->next;
	}
	push_end_solution(first, answer);
	return (simple_solution(first, ants));
}
