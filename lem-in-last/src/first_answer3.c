#include "../includes/lem-in.h"

void	delete_first_gr(t_otv **sort)
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
			if (!tmp->prev)
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
			break ;
		}
		tmp = tmp->next;
	}
}

void	del_sol_last_two(t_otv **otv, t_graph *first,
		t_graph *second)//нужно проверку на налл два раза и пофришить
{
	t_otv *tmp;

	tmp = *otv;
	find_delete(otv, first, tmp);
	find_delete(otv, second, tmp);
}

void	choose_place_for_del(t_otv **first, t_otv *tmp)
{
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
}

void	del_sol_old(t_otv **first)
{
	t_otv	*tmp;
	int		count;

	count = 0;
	tmp = *first;
	while (tmp)
	{
		if (tmp->old == 1 && count == 0)
		{
			count++;
			choose_place_for_del(first, tmp);
			break ;
		}
		tmp = tmp->next;
	}
}
