#include "../../includes/lem-in.h"
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

void    print_solutions(t_otv *otv)
{
	t_graph *links;
	int i;

	i = 1;
	while (otv)
	{
		links = otv->solve;
		printf("%d solution : ", i);
		while (links)
		{
			printf("%s", links->link);
			if (links->next != NULL)
			{
				printf("-->");
			}
			links = links->next;
		}
		i++;
		printf("\n");
		otv = otv->next;
	}
}

