/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_functions3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:08:42 by gstarvin          #+#    #+#             */
/*   Updated: 2020/03/13 16:11:11 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

t_graph			*add_line_out(t_links *connections, char *name)
{
	t_graph		*graph;

	graph = NULL;
	while (connections)
	{
		push_front_graph(&graph, name, connections->link);
		graph->in = 0;
		graph->out = 1;
		graph->buff_in = 1;
		graph->buff_out = 0;
		connections = connections->next;
	}
	push_front_graph(&graph, name, name);
	graph->in = 1;
	graph->out = 0;
	graph->buff_in = 1;
	graph->buff_out = 0;
	graph->weight_link = 0;
	graph->no = -1;
	return (graph);
}

t_graph			*add_line_out_start(t_links *connections, char *name)
{
	t_graph		*graph;

	graph = NULL;
	while (connections)
	{
		push_front_graph(&graph, name, connections->link);
		graph->in = 0;
		graph->out = 1;
		graph->buff_in = 1;
		graph->buff_out = 0;
		connections = connections->next;
	}
	return (graph);
}

t_graph			*add_line_in_end(t_links *connections, char *name)
{
	t_graph		*graph;

	graph = NULL;
	while (connections)
	{
		push_front_graph(&graph, name, connections->link);
		graph->in = 1;
		graph->out = 0;
		graph->buff_in = 0;
		graph->buff_out = 1;
		graph->no = -1;
		connections = connections->next;
	}
	return (graph);
}
