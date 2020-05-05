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
		if ((buff[i].in == 1) && (buff[i].out == 1))
			printf("**[start/end ");
		else if (buff[i].in == 1)
			printf("**[in ");
		else if (buff[i].out == 1)
			printf("**[out ");
		printf("%s]  Weight = %d, Parent_name = %s ", buff[i].name, buff[i].weight_edge, buff[i].parent_name);
		if (buff[i].parent_name)
		{
			if ((buff[i].parent->in == 1) && (buff[i].parent->out  == 1))
				printf("start/end\n ");
			else if (buff[i].parent->in == 1)
				printf("in\n ");
			else if (buff[i].parent->out == 1)
				printf("out\n ");
		}
		else
			printf("\n");
		while (links)
		{
			if ((buff[i].in == 1) && (buff[i].out == 1))
				printf("[start/end ");
			else if (buff[i].in == 1)
				printf("[in ");
			else if (buff[i].out == 1)
				printf("[out ");
			printf("%s] ", buff[i].name);
			if (links->in == 1 && links->out == 1)
			{
				printf("<--->");// [%s], weight = %d\n", links->link, links->weight_link);
			}
			else if (links->in == 0 && links->out == 1)
			{
		//		printf("[%s] ", buff[i].name);
				printf("--->");// [%s], weight = %d\n", links->link, links->weight_link);
			}
			else if (links->in == 1 && links->out == 0)
			{
		//		printf("[%s] ", buff[i].name);
				printf("<---");// [%s], weight = %d\n", links->link, links->weight_link);
			}
			else
			{
		//		printf("[%s] ", buff[i].name);
				printf("--- ");// [%s], weight = %d\n", links->link, links->weight_link);
			}
			if ((links->buff_in == 1) && (links->buff_out == 1))
				printf("[start/end ");
			else if (links->buff_in == 1)
				printf("[in ");
			else if (links->buff_out == 1)
				printf("[out ");
			printf("%s], weight = %d\n", links->link, links->weight_link);
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
		printf("%d solution : %d  ", i, otv->len);
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

void	print_links(char *text, t_graph *graph)
{
	printf("%s\n", text);
	while (graph)
	{
		printf("%s", graph->link);
		if (graph->next != NULL)
		{
			printf("-->");
		}
		graph = graph->next;
	}
	printf("\n");
}

