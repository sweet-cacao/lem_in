#include "../includes/lem-in.h"

void overlay_solve(const t_gr_block *buff, t_gr_block *one_block, t_graph *links, t_graph *links2)
{
	links->out = 1;
	links->time++;
	links->in = 0;
	links->weight_link = -1;
	if (links->code_link == (*one_block).code)
		links->weight_link = 0;
	links2 = buff[links->num_buff].links;
	while (links2)
	{
		if (links2->num_buff == (*one_block).num)
		{
			links2->out = 0;
			links2->in = 1;
			if (links->time > 1 || links2->time >= 1)
			{
				links->out = 0;
				links2->in = 0; // ссылка обратно должна убираться тожеi
			}
			links2->time++;
			break;
		}
		links2 = links2->next;
	}
}

int			make_path_back(t_gr_block *buff, int len, t_gr_block one_block)
{
	buff[one_block.num].count++;
	while (one_block.parent)
	{
		one_block = buff[one_block.parent->num];
		if (one_block.count == 1)
		{
			return (0);
		}
		buff[one_block.num].count++;
	}
	if (one_block.start == 1)
		return (1);
	else
		return (0);
}

int			make_path_back_minus(t_gr_block *buff, int len, t_gr_block one_block)
{
	t_graph *links;
	t_graph *links2;

	links = one_block.links;
	while (one_block.parent && one_block.start != 1)
	{
		links = one_block.links;
		while(links)
		{
			if (links->num_buff == one_block.parent->num)
			{
				overlay_solve(buff, &one_block, links, links2);
				break;
			}
			links = links->next;
		}
		one_block = buff[one_block.parent->num];
	}
	if (one_block.start == 1)
		return (1);
	else
		return (0);
}

int			check_duplicate_room(t_graph *graph, char *name, int code_gr)
{
	while(graph)
	{
		if (graph->code_link == code_gr)
			return (1);
		graph = graph->next;
	}
	return (0);
}

void		reconstruct_initial(t_gr_block *buff, int len)
{
	int		i;
	t_graph *links;

	i = 0;
	while (i < len) {
		buff[i].count = 0;
		buff[i].weight_edge = INT32_MAX;
		buff[i].parent_name = NULL;
		buff[i].parent = NULL;
		buff[i].iter = -1;
		i++;
	}
	buff[0].weight_edge = 0;
}
