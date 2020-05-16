/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_answer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:27:46 by gstarvin          #+#    #+#             */
/*   Updated: 2020/05/16 15:18:01 by sweet-cacao      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

int		check_same_link_inner_while(t_otv **first, int ants,
		t_glob glob, t_graph *answer)
{
	glob.walk = glob.tmp->solve->next;
	while (glob.walk->next)
	{
		if (ft_strcmp(glob.graph->link, glob.walk->link) == 0)
		{
			glob.new_answer_1 = get_first_answer(glob.graph, glob.tmp->solve);
			glob.new_answer_2 = get_second_answer(answer, glob.walk);
			glob.tmp->old = 1;
			return (new_solutions(first, glob.new_answer_1,
					glob.new_answer_2, ants));
		}
		glob.walk = glob.walk->next;
	}
	return (0);
}

int		check_same_link(t_graph *answer, t_otv **first, int ants)
{
	t_glob	glob;
	int		k;

	k = 0;
	glob.tmp = *first;
	while (glob.tmp)
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
