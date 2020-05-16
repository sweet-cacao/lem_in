/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   belman_ford.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 13:21:29 by gstarvin          #+#    #+#             */
/*   Updated: 2020/05/15 16:35:33 by sweet-cacao      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

int		check_all_links(int buff_code, int link_code,
		int all_links[1000][2], int change)
{
	int i;

	i = 0;
	change++;
	while (i < change)
	{
		if (all_links[i][0] == buff_code && all_links[i][1] == link_code)
			return (1);
		if (all_links[i][1] == buff_code && all_links[i][0] == link_code)
			return (1);
		i++;
	}
	return (0);
}

void	weight_op(t_gr_block *buff, t_num num, int *otriz,
		t_graph *links)
{
	buff[links->num_buff].weight_edge =
			buff[num.i].weight_edge + links->weight_link;
	buff[links->num_buff].parent = &buff[num.i];
	buff[links->num_buff].parent_name = buff[num.i].name;
	if (links->weight_link == -1)
	{
		*otriz = 1;
		buff[return_j(buff, num.len, links)].iter = 1;
	}
}

int		change_weight(t_gr_block *buff, t_num num,
		int *otriz, int all_links[1000][2])
{
	t_graph	*links;
	int		change;

	change = 0;
	links = buff[num.i].links;
	while (links)
	{
		if (buff[links->num_buff].start != 1 && buff[num.i].dead_end != 1
		&& buff[num.i].end != 1 && buff[links->num_buff].iter != 1
		&& buff[num.i].weight_edge != INT32_MAX && links->out == 1
		&& check_all_links(buff[num.i].code, links->code_link, all_links,
		(num.change + change)) == 0 && buff[links->num_buff].weight_edge >
		(buff[num.i].weight_edge + links->weight_link))
		{
			all_links[change][0] = links->code_link;
			all_links[change][1] = buff[num.i].code;
			change++;
			weight_op(buff, num, otriz, links);
		}
		links = links->next;
	}
	return (change);
}

void	bel_ford3(t_gr_block *buff, int len, int *otriz)
{
	int		k;
	int		all_links[1000][2];
	t_num	num;

	num.len = len;
	k = -1;
	while(k++ < 1000)
	{
		all_links[k][0] = 0;
		all_links[k][1] = 0;
//		k++;
	}
	k = 0;
	while (k++ < len)
	{
		num.i = 0;
		num.i = 0;
		num.change = 0;
		while (num.i < len)
		{
			num.change += change_weight(buff, num, otriz, all_links);
			num.i++;
		}
		if (num.change == 0)
			break ;
	}
}
