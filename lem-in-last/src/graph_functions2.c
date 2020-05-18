/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:08:42 by gstarvin          #+#    #+#             */
/*   Updated: 2020/05/17 15:18:00 by sweet-cacao      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_graph			*add_block_graph(char *name, char *connection)
{
	t_graph		*graph;

	graph = (t_graph*)malloc(sizeof(t_graph));
	graph->in = 1;
	graph->out = 1;
	graph->weight_link = 1;
	graph->link = connection;
	graph->next = NULL;
	graph->num_buff = 0;
	graph->no = 0;
	graph->time = 0;
	if (ft_strcmp(name, connection) == 0)
	{
		graph->weight_link = 0;
	}
	return (graph);
}

void			push_end_graph(t_graph **graph, char *name, char *connection)
{
	t_graph		*last;
	t_graph		*tmp;

	last = get_next_graph(*graph);
	tmp = add_block_graph(name, connection);
	if (last == NULL)
	{
		(*graph) = tmp;
	}
	else
	{
		last->next = tmp;
	}
}

void			push_front_graph(t_graph **graph, char *name, char *connection)
{
	t_graph		*tmp;

	if ((*graph) == NULL)
		(*graph) = add_block_graph(name, connection);
	else
	{
		tmp = add_block_graph(name, connection);
		tmp->next = (*graph);
		(*graph) = tmp;
	}
}

t_graph			*add_line(t_links *connections, char *name)
{
	t_graph		*graph;

	graph = NULL;
	while (connections)
	{
		push_end_graph(&graph, name, connections->link);
		connections = connections->next;
	}
	return (graph);
}
