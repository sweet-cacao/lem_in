#include "../includes/lem-in.h"

int     return_level(t_gr_block *buff, char *name, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (ft_strcmp(name, buff[i].name) == 0)
			return (buff[i].level);
		i++;
	}
}

void    get_level(t_gr_block *buff, int level, char *name, int len, t_graph **solution)
{
	int i;

	i = 0;
//	t_gr_block edges[len] = buff[len];
	while (i < len)
	{
		if (ft_strcmp(name, buff[i].name) == 0)
        {
		    if (buff[i].level == -1)// && buff[i].start == 0)
		        buff[i].level = level + 1;
        }
		i++;

	}
}

//BFS
void    bfs_algorythm(int len, t_gr_block *buff)
{
	t_graph *solution;
	int i;
//	t_gr_block edges[len] = buff;
	t_graph *links;
	//t_graph *follow_links;

	links = NULL;
	//edges[len] = buff[len];
//	len = 4;
	i = 0;
	while (i < (len - 1))
	{
		links = buff[i].links;
		printf("buff[i] = %s\n", buff[i].name);
//		follow_links = buff[i + 1].links;
		while (links)
		{
            printf("link = %s\n", links->link);
			get_level(buff, buff[i].level, links->link, len, &solution);
			links = links->next;
		}
		i++;
	}
}


