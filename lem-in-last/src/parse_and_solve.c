/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:28:10 by gstarvin          #+#    #+#             */
/*   Updated: 2020/05/17 15:18:11 by sweet-cacao      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			count_len_pointlist(t_pointlist *map)
{
	int			i;

	i = 0;
	if (!map)
		return (0);
	while (map)
	{
		i++;
		map = map->next;
	}
	return (i);
}

void		give_j(int len, t_gr_block *buff)
{
	int			i;
	t_graph		*links;

	i = 0;
	while (i < len)
	{
		buff[i].num = i;
		links = buff[i].links;
		while (links)
		{
			links->num_buff = return_j(buff, len, links);
			links->code_link = buff[links->num_buff].code;
			links = links->next;
		}
		i++;
	}
}

int			start_point(t_gr_block *buff, t_pointlist *map, int len, int flag)
{
	if (flag == 0)
	{
		buff[0] = create_gr_block_start(map->links_list, map->name_point);
		buff[0].start = 1;
		buff[0].weight_edge = 0;
		buff[0].code = 0;
	}
	else if (flag == 1)
	{
		buff[len - 1] = create_gr_block_end(map->links_list, map->name_point);
		buff[len - 1].end = 1;
		buff[len - 1].code = len - 1;
	}
	else
	{
		buff[len] = create_gr_block_out(map->links_list, map->name_point);
		buff[len].code = len;
		len++;
		buff[len] = create_gr_block_in(map->links_list, map->name_point);
		buff[len].code = len - 1;
		len++;
	}
	return (len);
}

void		part_solve(int len, int ants, t_gr_block *buff, char *str)
{
	give_j(len, buff);
	belman_ford_req(buff, len, ants, str);
	del_buff_links(len, buff);
}

void		parse_and_solve(int len, t_pointlist **mapa, int ants, char *str)
{
	t_gr_block	buff[len];
	t_pointlist *map;
	int			i;
	t_pointlist *test;

	map = (*mapa);
	test = (*mapa);
	i = 1;
	start_point(buff, map, len, 0);
	while (map)
	{
		if (ft_strcmp("start", map->start_end) == 0)
		{
			del_graph(&buff[0].links);
			start_point(buff, map, len, 0);
		}
		else if (ft_strcmp("end", map->start_end) == 0)
			test = map;
		else if (i != (len - 1))
			i = start_point(buff, map, i, 2);
		map = map->next;
	}
	start_point(buff, test, len, 1);
	del_pointlist(mapa);
	part_solve(len, ants, buff, str);
}
