#include "../includes/lem-in.h"
#include <stdio.h>

void    print_graph(t_gr_block *buff, int len)
{
	int i;
	t_graph *links;

	i = 0;
	while (i < len)
	{
		links = buff[i].links;
		printf("**[%s]  Weight = %d, Parent_name = %s :**\n", buff[i].name, buff[i].weight_edge, buff[i].parent_name);
		while (links)
		{
			if (links->in == 1 && links->out == 1)
			{
				printf("[%s] ", buff[i].name);
				printf("<---> [%s], weight = %d\n", links->link, links->weight_link);
			}
			else if (links->in == 0 && links->out == 1)
			{
				printf("[%s] ", buff[i].name);
				printf("---> [%s], weight = %d\n", links->link, links->weight_link);
			}
			else if (links->in == 1 && links->out == 0)
			{
				printf("[%s] ", buff[i].name);
				printf("<--- [%s], weight = %d\n", links->link, links->weight_link);
			}
			else
			{
				printf("[%s] ", buff[i].name);
				printf("--- [%s], weight = %d\n", links->link, links->weight_link);
			}
			links = links->next;
		}
		printf("\n");
		i++;
	}
}

