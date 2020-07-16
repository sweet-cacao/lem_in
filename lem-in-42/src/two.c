/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfreddie <gfreddie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:07:10 by gfreddie          #+#    #+#             */
/*   Updated: 2020/03/08 21:21:32 by gfreddie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_pointlist			*list_creation(void)
{
	t_pointlist		*new_list;

	new_list = (t_pointlist *)malloc(sizeof(t_pointlist) * (1));
	return (new_list);
}

t_links				*plus_on_double_star_char(t_links *links_list,
					char *new_elem)
{
	t_links			*new;

	new = (t_links *)malloc(sizeof(t_links) * (1));
	new->link = new_elem;
	new->next = links_list;
	return (new);
}

t_pointlist			*put_nums(t_pointlist *point_info)
{
	t_pointlist	*t_save;
	int			i;

	i = 0;
	t_save = point_info;
	while (point_info->next != NULL)
	{
		point_info->nums = i++;
		point_info = point_info->next;
	}
	point_info->nums = i++;
	return (t_save);
}

t_pointlist			*search_list_(t_pointlist *point_info, char c)
{
	t_pointlist		*save_point_before;

	while (point_info->start_end[1] != c)
	{
		save_point_before = point_info;
		point_info = point_info->next;
	}
	return (save_point_before);
}

char				*create_markers_line(void)
{
	int		index;
	char	*markers;

	index = ft_strlen("##start##end");
	markers = (char *)malloc(sizeof(char) * (index + 1));
	markers[index] = '\0';
	markers[0] = '#';
	markers[1] = '#';
	markers[2] = 's';
	markers[3] = 't';
	markers[4] = 'a';
	markers[5] = 'r';
	markers[6] = 't';
	markers[7] = '#';
	markers[8] = '#';
	markers[9] = 'e';
	markers[10] = 'n';
	markers[11] = 'd';
	return (markers);
}
