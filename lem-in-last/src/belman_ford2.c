/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   belman_ford2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:27:46 by gstarvin          #+#    #+#             */
/*   Updated: 2020/05/17 15:18:00 by sweet-cacao      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		count_links(t_graph *graph)
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

int		count_solutions(t_otv *graph)
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

int		count_max_paths(t_gr_block *buff, int len)
{
	int max_n_end_paths;
	int max_n_start_paths;
	int max_n_paths;

	max_n_end_paths = INT32_MAX;
	max_n_start_paths =
	count_links(return_t_gr_block(buff, len, get_start(buff, len)).links);
	if (max_n_end_paths > max_n_start_paths)
	{
		max_n_paths = max_n_start_paths;
	}
	else
		max_n_paths = max_n_end_paths;
	return (max_n_paths);
}

int		return_j(t_gr_block *buff, int len, t_graph *links)
{
	int		i;
	char	*name;

	name = links->link;
	i = 0;
	while (i < len)
	{
		if (ft_strcmp(buff[i].name, name) == 0 && ((links->buff_in == 1 &&
		buff[i].in == 1) || (links->buff_out == 1 && buff[i].out == 1)))
			return (i);
		i++;
	}
	return (0);
}
