/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   belman_ford.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 13:21:29 by gstarvin          #+#    #+#             */
/*   Updated: 2020/03/13 15:05:40 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

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

int		count_max_paths(t_gr_block *buff, int len)
{
	int max_n_end_paths;
	int max_n_start_paths;
	int max_n_paths;

	max_n_end_paths = count_links(find_end(buff, len).links);
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

int		return_j(t_gr_block *buff, int len, char *name)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (ft_strcmp(buff[i].name, name) == 0)
			return (i);
		i++;
	}
	return (0);
}

int		change_weight(t_gr_block *buff, int len, int i)
{
	t_graph	*links;
	int		change;

	change = 0;
	links = buff[i].links;
	while (links)
	{
		if (buff[i].dead_end != 1 && buff[i].end != 1
		&& buff[links->num_buff].iter != 1
		&& buff[i].weight_edge != INT32_MAX &&
		links->out == 1 &&
		buff[links->num_buff].weight_edge >
		(buff[i].weight_edge + links->weight_link))
		{
			buff[links->num_buff].weight_edge =
			buff[i].weight_edge + links->weight_link;
			buff[links->num_buff].parent = &buff[i];
			buff[links->num_buff].parent_name = buff[i].name;
			change++;
			if (links->weight_link == -1)
				buff[return_j(buff, len, links->link)].iter = 1;
		}
		links = links->next;
	}
	return (change);
}

void	bel_ford3(t_gr_block *buff, int len)
{
	int		i;
	int		k;
	int		change;

	k = 0;
	while (k < len - 1)
	{
		i = 0;
		change = 0;
		while (i < len)
		{
			change += change_weight(buff, len, i);
			i++;
		}
		if (change == 0)
			break ;
		k++;
	}
}
