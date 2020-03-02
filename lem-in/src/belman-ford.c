#include "../includes/lem-in.h"

void    give_directions(t_gr_block *buff, int len)
{
	int i;
	t_graph *links;

	i = 0;
	while (i < len)
	{
		links = buff[i].links;
		while (links)
		{
			if (return_level(buff, links->link, len) > buff[i].level)
			{
				links->in = 0;
				links->out = 1;
			}
			if (return_level(buff, links->link, len) < buff[i].level)
			{
				links->in = 1;
				links->out = 0;
			}
		//	if (return_level(buff, links->link, len) == buff[i].level)
		//	{
		//		links->in = 0;
		//		links->out = 0;
		//	}
			links = links->next;
		}
		i++;
	}
}

void    add_weight(t_gr_block *buff, int len, t_graph *links, int iter, t_gr_block tmp)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (ft_strcmp(buff[i].name, links->link) == 0 && buff[i].iter != iter)
		{
			buff[i].weight_edge = tmp.parent->weight_edge + links->weight_link;
			buff[i].iter = iter;
		}
		i++;
	}
}

void    req(t_gr_block *buff, int len, t_gr_block one_block, int i)
{
	t_graph *links;
	t_gr_block tmp;

	if (one_block.end == 1)
		return ;
	else
	{
		links = one_block.links;
		while (links)
		{
			tmp = return_t_gr_block(buff, len, links->link);
			if (links->out == 1)
			{
				tmp.parent = &one_block;
				add_weight(buff, len, links, i, tmp);
				req(buff, len, tmp, i);
			}

			links = links->next;
		}
	}
}

void    belman_ford_req(t_gr_block *buff, int len)
{
	int i;
	t_gr_block tmp;
	t_graph *links;

	i = 0;

	while (i < len)
	{
		req(buff, len, return_t_gr_block(buff, len, get_start(buff, len)), i);
		i++;
	}
}

/*
void    belman_ford(int len, t_gr_block *buff)
{
	int     i;
	int     j;
	t_graph *links;
	t_gr_block tmp;
	j = 0;
	i = 0;
	while (i < len)
	{
		j = 0;
		while (buff[j].end != 1)
		{
			links = buff[j].links;
			while (links)
			{
				tmp = return_t_gr_block(buff, len, links->link);
				if (links->out == 1) {
					add_weight(buff, len, links, i);
				}
				links = links->next;
			}
		}
		i++;
	}
}*/

