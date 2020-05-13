#include "../includes/lem-in.h"

int		new_solutions_branch(t_otv **first, t_graph *new_answer_1,
		t_graph *new_answer_2, int ants)
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

int		is_in_solutions_graph_links(t_otv **first, t_otv *tmp,
				t_graph *answer, int ants)
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
				glob.new_answer_1 = get_first_answer(glob.graph, tmp->solve);
				glob.new_answer_2 = get_second_answer(answer, glob.walk);
				del_sol_last_two(first, glob.tmp->solve, glob.tmp->solve);
				return (new_solutions_branch(first,
						glob.new_answer_1, glob.new_answer_2, ants));
			}
			glob.walk = glob.walk->next;
		}
		glob.graph = glob.graph->next;
	}
	return (0);
}

int		is_in_solutions_graph(t_otv **first, t_graph *tmp, int ants)
{
	t_otv	*otv;
	int		res;

	otv = *first;
	res = 0;
	while (otv)
	{
		if (otv->old == 0)
		{
			res = is_in_solutions_graph_links(first, otv, tmp, ants);
			if (res == 2)
				break ;
			if (res == 3)
				return (0);
		}
		otv = otv->next;
	}
	return (res);
}

int		new_solutions(t_otv **first, t_graph *new_answer_1,
		t_graph *new_answer_2, int ants)
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
		//free(tmp);
		tmp = NULL;
		return (3);
	}
	return (2);
}