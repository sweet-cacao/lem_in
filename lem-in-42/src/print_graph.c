/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_graph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sweet-cacao <sweet-cacao@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 01:03:07 by sweet-cacao       #+#    #+#             */
/*   Updated: 2020/05/17 16:38:49 by sweet-cacao      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_content(t_gr_block *buff, int i)
{
	if ((buff[i].in == 1) && (buff[i].out == 1))
		ft_printf("**[start/end ");
	else if (buff[i].in == 1)
		ft_printf("**[in ");
	else if (buff[i].out == 1)
		ft_printf("**[out ");
	ft_printf("%s]  Weight = %d, Parent_name = %s ",
	buff[i].name, buff[i].weight_edge, buff[i].parent_name);
}

void	inner_print(t_gr_block *buff, int i, t_graph *links)
{
	if ((buff[i].in == 1) && (buff[i].out == 1))
		ft_printf("[start/end ");
	else if (buff[i].in == 1)
		ft_printf("[in ");
	else if (buff[i].out == 1)
		ft_printf("[out ");
	ft_printf("%s] ", buff[i].name);
	if (links->in == 1 && links->out == 1)
		ft_printf("<--->");
	else if (links->in == 0 && links->out == 1)
		ft_printf("--->");
	else if (links->in == 1 && links->out == 0)
		ft_printf("<---");
	else
		ft_printf("--- ");
	if ((links->buff_in == 1) && (links->buff_out == 1))
		ft_printf("[start/end ");
	else if (links->buff_in == 1)
		ft_printf("[in ");
	else if (links->buff_out == 1)
		ft_printf("[out ");
	ft_printf("%s], weight = %d\n", links->link, links->weight_link);
}

void	print_parent(t_gr_block *buff, int i)
{
	if ((buff[i].parent->in == 1) && (buff[i].parent->out == 1))
		ft_printf("start/end\n ");
	else if (buff[i].parent->in == 1)
		ft_printf("in\n ");
	else if (buff[i].parent->out == 1)
		ft_printf("out\n ");
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
			ft_printf("\n");
		while (links)
		{
			inner_print(buff, i, links);
			links = links->next;
		}
		ft_printf("\n");
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
		ft_printf("%d solution : %d  ", i, otv->len);
		while (links)
		{
			ft_printf("%s", links->link);
			if (links->next != NULL)
				ft_printf("-->");
			links = links->next;
		}
		i++;
		ft_printf("\n");
		otv = otv->next;
	}
}
