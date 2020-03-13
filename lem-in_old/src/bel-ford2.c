#include "../includes/lem-in.h"

int     return_j(t_gr_block *buff, int len, char *name)
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

void    fill_source(int **source, int len, t_gr_block *buff)
{
	int i;
	t_graph *links;
	int j;

	j = 0;
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			source[i][j] = 0;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < len)
	{
		links = buff[i].links;
		while (links)
		{
			source[i][return_j(buff, len, links->link)] = 1;
			links = links->next;
		}
		i++;
	}
}

void    bel_ford2(int len, t_gr_block *buff)
{
	int *min_path;
	int **source_mass;
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	source_mass = (int **)malloc(len * sizeof(int *));
	min_path = (int *)malloc(len * sizeof(int));
	while (i < len)
	{
		source_mass[i] = (int *)malloc(len * sizeof(int));
		min_path[i] = INT32_MAX;
		i++;
	}
	fill_source(source_mass, len, buff);
	min_path[0] = 0;
	i = 0;
	while (k < len)
	{
		i = 0;
		while (i < len)
		{
			j = 0;
			while (j < len)
			{
				if (source_mass[i][j] != 0)
				{
					if (min_path[j] > (min_path[i] + source_mass[i][j]))
						min_path[j] = min_path[i] + source_mass[i][j];
				}
				j++;
			}
			i++;
		}
		k++;
	}
	i = 0;
	while (i < len)
	{
		printf("%d-->", min_path[i]);
		i++;
	}
}

int     check_parents_bel_ford2(t_gr_block *buff, int len, char *name)
{
	t_gr_block tmp;
	t_gr_block one_block;

	one_block = return_t_gr_block(buff, len, name);
	if (one_block.parent_name == NULL)
		return (0);
	tmp = return_t_gr_block(buff, len, one_block.parent_name);
	while (1)
	{
		if (ft_strcmp(one_block.name, tmp.name) == 0)
			return (1);
		if (tmp.parent_name == NULL)
			return (0);
		tmp = return_t_gr_block(buff, len, tmp.parent_name);
	}
	return (0);
}

void    bel_ford3(t_gr_block *buff, int len)
{
	int i;
	int j;
	int k;
	int change;
	k = 0;
	t_graph *links;
	j = 0;
	i = 0;
//	t_gr_block block = return_t_gr_block(buff, len, get_start(buff, len));
	while (k < len - 1)
	{
		i = 0;
		change = 0;
		while (i < len)
		{
			j = 0;

			links = buff[i].links;
//		links = block.links;
			while (links)
			{
				//buff[return_j(buff, len, links->link)].start != 1 &&
				if (buff[i].dead_end != 1 && buff[i].end != 1 && buff[links->num_buff].iter != 1 && buff[i].weight_edge != INT32_MAX && links->out == 1 && buff[links->num_buff].weight_edge > (buff[i].weight_edge + links->weight_link))
				{
				/*	if ((buff[i].weight_edge + links->weight_link) < 0)
					{
						buff[return_j(buff, len, links->link)].weight_edge = buff[i].weight_edge;
					}
					else
					{*/
						buff[links->num_buff].weight_edge = buff[i].weight_edge + links->weight_link;
						buff[links->num_buff].parent = &buff[i];
						buff[links->num_buff].parent_name = buff[i].name;
				//	}
					change++;
					if (links->weight_link == -1)
						buff[return_j(buff, len, links->link)].iter = 1;
				}
				links = links->next;
			}
			i++;
		}
		if (change == 0)
			break;
		k++;
	}
}

