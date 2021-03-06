/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:28:10 by gstarvin          #+#    #+#             */
/*   Updated: 2020/03/13 17:31:20 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

int				count_len_pointlist(t_pointlist *map)
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

void			give_j(int len, t_gr_block *buff)
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

void			parse_and_solve(int len, t_pointlist **mapa, int ants)
{
	t_gr_block	buff[len];
	t_pointlist *map;
	int			i;
	int			j;
	t_pointlist *test;

	map = (*mapa);
	test = (*mapa);
	i = 1;
	j = 0;
//	while (map)
//	{
//		if (ft_strcmp("start", map->start_end) == 0)
//		{
			buff[0] = create_gr_block_start(map->links_list, map->name_point);
			buff[0].start = 0;
			buff[0].weight_edge = 0;
			buff[0].code = 0;
			//	i++;
//		}
//		map = map->next;
//	}
//	map = *mapa;
	while (map)
	{
	/*	if (ft_strcmp("start", map->start_end) == 0)
		{
			buff[0] = create_gr_block_start(map->links_list, map->name_point);
			buff[0].start = 1;
			buff[0].weight_edge = 0;
		//	i++;
		}
		else if (ft_strcmp("end", map->start_end) == 0)
		{
			buff[len - 1] = create_gr_block_end(map->links_list, map->name_point);
			buff[len - 1].end = 1;
		//	i++;
		}
		else
		{*/
			if (ft_strcmp("start", map->start_end) == 0)
			{
				buff[0] = create_gr_block_start(map->links_list, map->name_point);
				buff[0].start = 1;
				buff[0].weight_edge = 0;
				buff[0].code = 0;
				//	i++;
			}
			if (ft_strcmp("end", map->start_end) == 0)
			{
//				buff[i] = create_gr_block_end(map->links_list, map->name_point);
//				buff[i].end = 0;
//				buff[i].code = len - 1;
				test = map;
				//	i++;
			}
			if ((i != 0 && i != (len - 1) )&& (ft_strcmp("start", map->start_end) != 0) && (ft_strcmp("end", map->start_end) != 0)) {
				buff[i] = create_gr_block_out(map->links_list, map->name_point);
				buff[i].code = i;
				i++;
				buff[i] = create_gr_block_in(map->links_list, map->name_point);
				buff[i].code = i - 1;
				i++;

		//	}
		}
		map = map->next;
	}
	map = *mapa;
//	while (map)
//	{
//		if (ft_strcmp("end", map->start_end) == 0)
//		{
			buff[len - 1] = create_gr_block_end(test->links_list, test->name_point);
			buff[len - 1].end = 1;
			buff[len - 1].code = len-1;
			//	i++;
//		}
//		map = map->next;
//	}
//	del_pointlist(mapa);
	give_j(len, buff);
//	print_graph(buff, len);

	belman_ford_req(buff, len, ants);
//	del_buff_links(len, buff);
}
