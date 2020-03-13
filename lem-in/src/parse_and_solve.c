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
		links = buff[i].links;
		while (links)
		{
			links->num_buff = return_j(buff, len, links->link);
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

	map = (*mapa);
	i = 0;
	while (i < len)
	{
		buff[i] = create_gr_block(map->links_list, map->name_point);
		if (ft_strcmp("start", map->start_end) == 0)
		{
			buff[i].start = 1;
			buff[i].weight_edge = 0;
		}
		if (ft_strcmp("end", map->start_end) == 0)
			buff[i].end = 1;
		map = map->next;
		i++;
	}
	del_pointlist(mapa);
	give_j(len, buff);
	belman_ford_req(buff, len, ants);
	del_buff_links(len, buff);
}
