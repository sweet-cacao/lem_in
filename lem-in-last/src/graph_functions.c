/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:08:42 by gstarvin          #+#    #+#             */
/*   Updated: 2020/05/17 15:18:00 by sweet-cacao      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

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
	gr_block.dead_end = 0;
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
	gr_block.dead_end = 0;
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
	gr_block.dead_end = 0;
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
	gr_block.links = add_line_in_end(connections, name);
	gr_block.name = name;
	gr_block.parent = NULL;
	gr_block.parent_name = NULL;
	gr_block.count = 0;
	gr_block.prev = NULL;
	gr_block.dead_end = 0;
	return (gr_block);
}
