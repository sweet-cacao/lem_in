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


void    make_path_back_minus(t_gr_block *buff, int len, t_gr_block one_block)
{
	t_graph *links;
	t_gr_block tmp;

	while (one_block.parent)
	{
		links = one_block.links;
		while (links)
		{
			if (ft_strcmp(one_block.parent_name, links->link) == 0)
			{
				links->weight_link = -1;
				links->out = 1;
				links->in = 0;
				tmp = return_t_gr_block(buff, len, links->link);
                links = tmp.links;
				while (links)
				{
					if (ft_strcmp(one_block.name, links->link) == 0)
					{
						links->weight_link = -1;
						links->out = 0;
						links->in = 1;
						break;
					}
					links = links->next;
				}
				break;
			}
			links = links->next;
		}
		one_block = return_t_gr_block(buff, len, one_block.parent_name);
	}
}

int    add_weight(t_gr_block *buff, int len, t_graph *links, int iter, t_gr_block tmp, t_gr_block one_block)
{
	int i;
	int n;

	n = 0;
	i = 0;
	tmp.parent = &one_block;
	tmp.parent_name = one_block.name;
	while (i < len)
	{
	/*	if (ft_strcmp(buff[i].name, links->link) == 0)
		{
			buff[i].count++;
		}*/
		if (ft_strcmp(buff[i].name, links->link) == 0 )//&& (buff[i].iter != iter || buff[i].iter == -1))
		{

	//		buff[i].parent = &one_block;
		//	tmp.parent_name = one_block.name;
			n = tmp.parent->weight_edge + links->weight_link;
			if (buff[i].weight_edge == 0 || n < buff[i].weight_edge)//(buff[i].iter == -1 || (buff[i].iter != -1 && n < buff[i].weight_edge))
			{

				buff[i].weight_edge = tmp.parent->weight_edge + links->weight_link;
				buff[i].iter = iter;
				return (1);
			}
		}
		i++;
	}
	return (0);
}

void    set_parent(t_gr_block *buff, int len, t_gr_block tmp, t_gr_block one_block)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (ft_strcmp(tmp.name, buff[i].name) == 0)
		{
			buff[i].parent = &one_block;
			buff[i].parent_name = one_block.name;
		//	buff[i].count++;
		}
		i++;
	}
}

void    set_count(t_gr_block *buff, int len, t_gr_block one_block)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (ft_strcmp(one_block.name, buff[i].name) == 0)
			buff[i].count++;
		i++;
	}
}

void    req(t_gr_block *buff, int len, t_gr_block one_block, int i)
{
	t_graph *links;
	t_gr_block tmp;
	int j;
	int k;

	k = 0;

	j = 0;
	if (one_block.end == 1 || one_block.count >= 1) //|| one_block.start == 1)
	{
		while (j < len)
		{
			buff[j].count = 0;
			j++;
		}
		return ;
	}
	else
	{
		links = one_block.links;
		while (links)
		{
			tmp = return_t_gr_block(buff, len, links->link);
			if (links->out == 1 && (one_block.parent == NULL || (one_block.parent && ft_strcmp(one_block.parent->name, tmp.name) != 0)))
			{
			//	set_parent(buff, len, tmp, one_block);
			//	if (tmp.iter != i)
			//	{
				//	tmp.parent = &one_block;
			//		tmp.parent_name = one_block.name;
					if (tmp.start != 1)
					{

						k = add_weight(buff, len, links, i, tmp, one_block);
						//	set_parent(buff, len, tmp, one_block);
						tmp = return_t_gr_block(buff, len, links->link);
						tmp.parent = &one_block;
						tmp.parent_name = one_block.name;
						//	if (k)
						set_count(buff, len, one_block);
						//	tmp.count++;
						if (k)
							set_parent(buff, len, tmp, one_block);
						req(buff, len, tmp, i);
					}
			//	}
				printf("%d\n", tmp.count);

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

//	while (i < len)
//	{
		req(buff, len, return_t_gr_block(buff, len, get_start(buff, len)), i);
	//	i++;
	//}
	make_path_back_minus(buff, len, return_t_gr_block(buff, len, get_end(buff, len)));
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

