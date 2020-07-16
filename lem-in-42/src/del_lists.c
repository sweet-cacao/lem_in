/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:30:24 by gstarvin          #+#    #+#             */
/*   Updated: 2020/05/17 16:38:49 by sweet-cacao      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		dotka_help(char *str, char *markers, int n, int k)
{
	char	*new;

	new = ft_itoa(ft_atoi(str));
	if (n == 0 && (ft_strstr(markers, str) != NULL || !(str) ||
			ft_strcmp(new, str) != 0 || str[0] == '\0' || !(k > 0)))
	{
		ft_printf("[2]ERROR\n");
		if (*str)
			free(str);
		ft_strdel(&new);
		exit(-1);
		return (1);
	}
	free(new);
	return (0);
}

void	del_pointlist(t_pointlist **pointlist)
{
	t_pointlist *next;
	t_links		*next_link;

	if (!pointlist)
		return ;
	while (*pointlist)
	{
		next = (*pointlist)->next;
		while ((*pointlist)->links_list)
		{
			next_link = (*pointlist)->links_list->next;
			free((*pointlist)->links_list->link);
			free((*pointlist)->links_list);
			(*pointlist)->links_list = NULL;
			(*pointlist)->links_list = next_link;
		}
		free((*pointlist)->name_point);
		free(*pointlist);
		(*pointlist) = NULL;
		(*pointlist) = next;
	}
	pointlist = NULL;
}

void	del_buff_links(int len, t_gr_block *buff)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (buff[i].links)
			del_graph(&buff[i].links);
		i++;
	}
}

void	del_solutions(t_otv **solutions)
{
	t_otv *next;

	if (!solutions || !(*solutions))
		return ;
	while (*solutions)
	{
		next = (*solutions)->next;
		del_graph(&(*solutions)->solve);
		free(*solutions);
		(*solutions) = NULL;
		(*solutions) = next;
	}
	solutions = NULL;
}

void	del_graph(t_graph **graph)
{
	t_graph *next;

	if (!graph || !(*graph))
		return ;
	if ((*graph) == NULL)
		return ;
	while (*graph)
	{
		next = (*graph)->next;
		free(*graph);
		(*graph) = NULL;
		(*graph) = next;
	}
	(*graph) = NULL;
	graph = NULL;
}
