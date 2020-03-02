#include "../includes/lem-in.h"

void    get_null_levels(int len, t_gr_block *buff)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (buff[i].start == 1)
			buff[i].level = 0;
		else if (buff[i].end == 1)
			buff[i].level = INT32_MAX;
		else
			buff[i].level = -1;
		i++;
	}
}


//void    find_min_link_push()
t_otv   *get_solution(int len, t_gr_block *buff)
{
	t_otv *solutions;
	t_graph *links;
	char *need_name;
	int min;

	need_name = NULL;
	min = INT32_MAX;
	links = find_end(buff, len).links;
	solutions = NULL;
	solutions = add_block_solution(get_end(buff, len));
	while (return_level(buff, solutions->solve->link, len) > 0)
	{
		min = INT32_MAX;
		while (links)
		{
			if (return_level(buff, links->link, len) < min) { //также возвращаемый уровень не должен быть равен первому в решении
				min = return_level(buff, links->link, len);
				need_name = links->link;
			}
			links = links->next;
		}
		push_front_graph(&solutions->solve, need_name, need_name);
		links = return_t_gr_block(buff, len, solutions->solve->link).links;
	}
	return (solutions);
}

int     count_len_graph(t_graph *graph)
{
	int i;

	i = 0;
	while(graph)
	{
		i++;
		graph = graph->next;
	}
	return (i);
}

int     count_len_otv(t_otv *graph)
{
	int i;

	i = 0;
	while(graph)
	{
		i++;
		graph = graph->next;
	}
	return (i);
}

int     sensible(t_otv *solution, int ants)
{
	int length_path;
	int answer;
	int sum;

	sum = 0;
	answer = 0;
	length_path = 0;
	sum = count_len_otv(solution);
	length_path = count_len_graph(solution->solve);
	answer = (int)((length_path + ants) / sum);
	return (answer);
}
//сначала найти максимальное количество путей
//нужно еще удалить dead-ends из ссылок
t_otv   *suurbale(int len, t_gr_block *buff, int ants)
{
	t_otv *solution;
	t_otv *new_solution;

	solution = get_solution(len, buff);
	new_solution = get_solution(len, buff);
	while (sensible(new_solution, ants) <= sensible(solution, ants))
	{
		get_null_levels(len, buff);
		
	}
}