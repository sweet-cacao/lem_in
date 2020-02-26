#include "../includes/lem-in.h"
/*
t_otv     **struct_calc(t_otv **main_list, t_otv **plus_struct)
{
	int             len_list;
	int             index;
	t_otv     **new_list;

	len_list = 0;
	index = 0;
	while (main_list[len_list] != NULL)
		len_list++;
	new_list = (t_pointlist **)malloc(sizeof(t_pointlist *) * (len_list + 2));
	new_list[len_list + 1] = NULL;
	while (index <= len_list)
	{
		if (main_list[index] == NULL)
			new_list[index] = plus_struct[0];
		else
			new_list[index] = main_list[index];
	}
	return(new_list);
}*/

t_otv   create_otv(t_gr_block buff)
{
	t_otv otv;
	otv.solve = buff.links;
	return (otv);
}

//нет возвращаемго значения иногда, но на NULL ругается
t_gr_block find_end(t_gr_block *buff, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (buff[i].end == 1)
			return (buff[i]);
		i++;
	}
}

char     *get_start(t_gr_block *buff, t_graph *tmp, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (buff[i].start == 1)
			return (buff[i].name);
		i++;
	}
	return (NULL);
}

char     *get_end(t_gr_block *buff, t_graph *tmp, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (buff[i].end == 1)
			return (buff[i].name);
		i++;
	}
	return (NULL);
}

char    *get_end()
{
	return (NULL);
}

void    check_last_element(t_otv *otv)
{
	t_graph *tmp;

	tmp = get_next_graph(otv->solve);
	if ()
}

// псевдокод
t_otv   *find_answers(t_gr_block *buff, int len)
{
	t_otv *solutions;
	int num;

	solutions = NULL;
	solutions = add_block_solution(find_end(buff, len).name);
	//		push_front_solution(find_end(buff, len), len);
	//solutions = create_otv(find_end(buff, len));
//	while (1)
//	{
//		if (buff[i].start == 1)
//			break ;
		while(solutions)
		{
			if (check_last_element(solutions))
				break ;
			last = get_last(solution);
			links = last.links;
			num = 0;
			while(links)
			{
				if (num == 0 && (get_level(links->link) < get_level(solutions->solve)))
				{
					num++;
					push_front_graph(solutions->links, links->link)
				}
				else if (num != 0 && (get_level(links->link) < get_level(solutions->solve)))
				{
					push_front_solution(solution);
					delete_last_elemet
					push_new_element
				}
				links = links->next;
			}
			solutions = solutions[first];
		}
//	}
}