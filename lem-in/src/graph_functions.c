#include "../includes/lem-in.h"

int         massiv_len(char **connections)
{
	int i;

	i = 0;
	while(connections[i])
		i++;
	return (i);
}

t_graph     *get_next_graph(t_graph *graph)
{
	if (graph == NULL)
		return (NULL);
	while (graph->next)
		graph = graph->next;
	return (graph);
}

t_graph     *add_block_graph(char *name, char *connection)
{
	t_graph *graph;

	graph = (t_graph*)malloc(sizeof(t_graph));
	graph->in = 1;
	graph->out = 1;
	graph->weight_link = 1;
	graph->link = connection;
	graph->next = NULL;
	return (graph);
}

void        delete_one_graph(t_graph **graph, char *name)
{
	t_graph *tmp;
	t_graph *tmp2;

	if (graph == NULL || (*graph) == NULL)
		return ;
	tmp = (*graph);
	tmp2 = tmp;
	while (tmp)
	{
		if (ft_strcmp(tmp->link, name) == 0)
		{
			if (tmp == tmp2)
			{
				(*graph) = (*graph)->next;
				free(tmp);
				tmp = NULL;
			}
			else
			{
				free(tmp2->next);
				tmp2->next = NULL;
				tmp2->next = tmp2->next->next;
			}
		}
		tmp2 = tmp;
		tmp = tmp->next;//why warning
	}
}

void        push_end_graph(t_graph **graph, char *name, char *connection)
{
	t_graph *last;
	t_graph *tmp;

	last = get_next_graph(*graph);
	tmp = add_block_graph(name, connection);
	if (last ==NULL)
	{
		(*graph) = tmp;
	}
	else
	{
		last->next = tmp;
	}
}

void        push_front_graph(t_graph **graph, char *name, char *connection)
{
    t_graph	*tmp;

    if ((*graph) == NULL)
        (*graph) = add_block_graph(name, connection);
    else
    {
        tmp = add_block_graph(name, connection);
        tmp->next = (*graph);
        (*graph) = tmp;
    }
}

t_graph     *add_line(char **connections, char *name)
{
	t_graph *graph;
	int i;
	int len;

	graph = NULL;
	i = 0;
	len = massiv_len(connections);
//	printf("%d\n", len);
	while (i < len)
	{
		push_end_graph(&graph, name, connections[i]);
		i++;
	}
	return (graph);
}

t_gr_block  create_gr_block(char **connections, char *name)
{
    t_gr_block gr_block;

    gr_block.end = 0;
    gr_block.start = 0;
    gr_block.level = -1;
    gr_block.weight_edge = 0;
    gr_block.iter = -1;
    gr_block.links = add_line(connections, name);
    gr_block.name = name;
    gr_block.parent = NULL;
    gr_block.parent_name = NULL;
    gr_block.count = 0;
    return (gr_block);
}

/*
void    create_graph(int num, char **connections)
{
	t_graph buff[num];
	int i;

	i = 0;
	while(i < num)
	{
		num[i] = add_line(connections, name)
		i++;
	}
}*/

