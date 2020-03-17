/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:08:42 by gstarvin          #+#    #+#             */
/*   Updated: 2020/03/13 16:11:11 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

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

t_gr_block		create_gr_block(t_links *connections, char *name)
{
	t_gr_block	gr_block;

	gr_block.end = 0;
	gr_block.start = 0;
	gr_block.level = -1;
	gr_block.weight_edge = INT32_MAX;
	gr_block.iter = -1;
	gr_block.links = add_line(connections, name);
	gr_block.name = name;
	gr_block.parent = NULL;
	gr_block.parent_name = NULL;
	gr_block.count = 0;
	gr_block.prev = NULL;
	return (gr_block);
}

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

t_graph			*add_line_in(t_links *connections, char *name)
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
	push_front_graph(&graph, name, name);
	graph->in = 0;
	graph->out = 1;
	graph->buff_in = 0;
	graph->buff_out = 1;
	graph->weight_link = 0;
	return (graph);
}

t_gr_block		create_gr_block_out(t_links *connections, char *name)
{
	t_gr_block	gr_block;

	gr_block.end = 0;
	gr_block.start = 0;
	gr_block.out = 1;
	gr_block.in = 0;
	gr_block.level = -1;
	gr_block.weight_edge = INT32_MAX;
	gr_block.iter = -1;
	gr_block.links = add_line_out(connections, name);
	gr_block.name = name;
	gr_block.parent = NULL;
	gr_block.parent_name = NULL;
	gr_block.count = 0;
	gr_block.prev = NULL;
	return (gr_block);
}

t_gr_block		create_gr_block_in(t_links *connections, char *name)
{
	t_gr_block	gr_block;

	gr_block.end = 0;
	gr_block.start = 0;
	gr_block.out = 0;
	gr_block.in = 1;
	gr_block.level = -1;
	gr_block.weight_edge = INT32_MAX;
	gr_block.iter = -1;
	gr_block.links = add_line_in(connections, name);
	gr_block.name = name;
	gr_block.parent = NULL;
	gr_block.parent_name = NULL;
	gr_block.count = 0;
	gr_block.prev = NULL;
	return (gr_block);
}

t_gr_block		create_gr_block_start(t_links *connections, char *name)
{
	t_gr_block	gr_block;

	gr_block.start = 1;
	gr_block.end = 0;
	gr_block.out = 1;
	gr_block.in = 1;
	gr_block.level = -1;
	gr_block.weight_edge = 0;
	gr_block.iter = -1;
	gr_block.links = add_line_out_start(connections, name);
	gr_block.name = name;
	gr_block.parent = NULL;
	gr_block.parent_name = NULL;
	gr_block.count = 0;
	gr_block.prev = NULL;
	return (gr_block);
}

t_gr_block		create_gr_block_end(t_links *connections, char *name)
{
	t_gr_block	gr_block;

	gr_block.start = 0;
	gr_block.end = 1;
	gr_block.out = 1;
	gr_block.in = 1;
	gr_block.level = -1;
	gr_block.weight_edge = INT32_MAX;
	gr_block.iter = -1;
	gr_block.links = NULL;//add_line_in_end(connections, name);
	gr_block.name = name;
	gr_block.parent = NULL;
	gr_block.parent_name = NULL;
	gr_block.count = 0;
	gr_block.prev = NULL;
	return (gr_block);
}