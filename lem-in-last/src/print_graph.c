/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_graph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sweet-cacao <sweet-cacao@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 01:03:07 by sweet-cacao       #+#    #+#             */
/*   Updated: 2020/05/17 15:44:50 by sweet-cacao      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	print_content(t_gr_block *buff, int i)
{
	if ((buff[i].in == 1) && (buff[i].out == 1))
		printf("**[start/end ");
	else if (buff[i].in == 1)
		printf("**[in ");
	else if (buff[i].out == 1)
		printf("**[out ");
	printf("%s]  Weight = %d, Parent_name = %s ",
	buff[i].name, buff[i].weight_edge, buff[i].parent_name);
}

void	inner_print(t_gr_block *buff, int i, t_graph *links)
{
	if ((buff[i].in == 1) && (buff[i].out == 1))
		printf("[start/end ");
	else if (buff[i].in == 1)
		printf("[in ");
	else if (buff[i].out == 1)
		printf("[out ");
	printf("%s] ", buff[i].name);
	if (links->in == 1 && links->out == 1)
		printf("<--->");
	else if (links->in == 0 && links->out == 1)
		printf("--->");
	else if (links->in == 1 && links->out == 0)
		printf("<---");
	else
		printf("--- ");
	if ((links->buff_in == 1) && (links->buff_out == 1))
		printf("[start/end ");
	else if (links->buff_in == 1)
		printf("[in ");
	else if (links->buff_out == 1)
		printf("[out ");
	printf("%s], weight = %d\n", links->link, links->weight_link);
}

void	print_parent(t_gr_block *buff, int i)
{
	if ((buff[i].parent->in == 1) && (buff[i].parent->out == 1))
		printf("start/end\n ");
	else if (buff[i].parent->in == 1)
		printf("in\n ");
	else if (buff[i].parent->out == 1)
		printf("out\n ");
}

void	print_graph(t_gr_block *buff, int len)
{
	int		i;
	t_graph	*links;

	i = 0;
	while (i < len)
	{
		links = buff[i].links;
		print_content(buff, i);
		if (buff[i].parent_name)
		{
			print_parent(buff, i);
		}
		else
			printf("\n");
		while (links)
		{
			inner_print(buff, i, links);
			links = links->next;
		}
		printf("\n");
		i++;
	}
}

void	print_solutions(t_otv *otv)
{
	t_graph *links;
	int		i;

	i = 1;
	if (otv == NULL)
		return ;
	while (otv)
	{
		links = otv->solve;
		printf("%d solution : %d  ", i, otv->len);
		while (links)
		{
			printf("%s", links->link);
			if (links->next != NULL)
				printf("-->");
			links = links->next;
		}
		i++;
		printf("\n");
		otv = otv->next;
	}
}
