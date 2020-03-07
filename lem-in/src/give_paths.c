#include "../includes/lem-in.h"

int		is_sorted(t_otv *otv)
{
	t_otv	*tmp;
	t_otv	*tmp2;

	if (!otv)
		return (0);
	tmp = otv;
	tmp2 = otv->next;
	while (tmp && tmp2)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->len > tmp2->len)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

int     choose_path(int last_ants, t_otv *tmp)
{
	t_otv *walk;
	int len_now;
	int sum;

	len_now = tmp->len;
	sum = 0;
	walk = tmp;
	if (walk->number == 1)
	{
		return (1);
	}
	while(walk->prev)
	{
		walk = walk->prev;
		sum += len_now - walk->len;
	}
	if (last_ants > sum)
	{
		return (tmp->number);
	}
	return (0);
}

void    sort_with_len(t_otv **solutions)
{
	t_otv *tmp;
	t_otv *new;
	t_otv *tmp2;
	int len_tmp;
	t_graph *solve_tmp;
	int i;

	i = 1;
	tmp = (*solutions);
	while(tmp)
	{
		tmp->len = count_links(tmp->solve);
		tmp = tmp->next;
	}
	tmp = (*solutions);
	tmp2 = tmp->next;
	if (is_sorted(*solutions) != 1)
	{
		while (tmp)
		{
			while (tmp2)
			{
				if (tmp->len > tmp2->len)
				{
					len_tmp = tmp->len;
					solve_tmp = tmp->solve;
					tmp->len = tmp2->len;
					tmp->solve = tmp2->solve;
					tmp2->len = len_tmp;
					tmp2->solve = solve_tmp;
				}
				tmp2 = tmp2->next;
			}
			tmp = tmp->next;
			if (tmp)
				tmp2 = tmp->next;
		}
	}
	tmp = *solutions;
	while (tmp)
	{
		tmp->number = i;
		tmp = tmp->next;
		i++;
	}
}

void    give_paths(int ants, t_otv *solutions, t_ants *ants_buff)
{
	int i;
	t_otv *tmp;

	tmp = solutions;
	int k;

	k =  0;
	i = 1;
	sort_with_len(&solutions);
	while (i <= ants)
	{
		ants_buff[i-1].number = i;
		k = choose_path(ants - i - 1, tmp);
		if (k != 0)
		{
			ants_buff[i - 1].path = k;
			i++;
		}
		if (tmp->next)
		{
			tmp = tmp->next;
		}
		else
		{
			tmp = solutions;
		}
	}
}

int     is_in_room(t_ants *buff, int i, int ants)
{
	int j;

	j = 0;
	while (j < i)
	{
		if (buff[i].path == buff[j].path && buff[i].room->next && ft_strcmp(buff[i].room->next->link, buff[j].room->link) == 0 &&
		ft_strcmp(buff[i].room->next->link, get_next_graph(buff[i].room)->link) != 0)
			return (1);
		j++;
	}
	return (0);
}

t_graph *return_graph(t_otv *solutions, int path)
{
	t_otv *tmp;

	tmp = solutions;
	while (tmp)
	{
		if (tmp->number == path)
			return (tmp->solve);
		tmp = tmp->next;
	}
	return (0);
}

void    print_ants_and_paths(int ants, t_otv *solutions)
{
	int i;
	t_graph *graph;
	t_ants buff[ants];

	i = 0;
	give_paths(ants, solutions, buff);
	while (i < ants)
	{
		graph = return_graph(solutions, buff[i].path);
		buff[i].room = graph;
		i++;
	}
	while (1)
	{
		i = 0;
		while (i < ants)
		{
			if (ft_strcmp(buff[i].room->link, get_next_graph(solutions->solve)->link) != 0)
				break ;
			i++;
		}
		if (i == ants)
			break ;
		i = 0;
		while (i < ants)
		{
			if (buff[i].room->next && is_in_room(buff, i, ants) == 0) //учитывать то, что совпадает номер пути
			{
				buff[i].room = buff[i].room->next;
				printf("L%d-%s ", buff[i].number, buff[i].room->link);
			}
			i++;
		}
		printf("\n");
	}
}