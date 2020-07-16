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

void		printf_double_star_char(char **links)
{
	int index;

	index = 0;
	while (links[index] != NULL)
	{
		ft_printf("%s ", links[index]);
		index++;
	}
	ft_printf("\n");
}

void		mas_struct_print(t_pointlist *structs)
{
	while (structs != NULL)
	{
		while (structs->links_list != NULL)
		{
			ft_printf("%s, ", structs->links_list->link);
			structs->links_list = structs->links_list->next;
		}
		ft_printf("\n");
		structs = structs->next;
	}
}

t_pointlist	*search_list(t_pointlist *point_info, char *search_name)
{
	while (point_info != NULL &&
		ft_strcmp(point_info->name_point, search_name) != 0)
		point_info = point_info->next;
	if (point_info == NULL)
		return (NULL);
	return (point_info);
}

int			is_it_numbers_on_str(char *str, int a)
{
	int i;

	i = 0;
	if (a)
	{
		while (str[i] != ' ' && str[i] != '\0')
			i++;
	}
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') &&
			str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int			len_double_star_char(char **str)
{
	int index;

	index = 0;
	while (str[index] != NULL)
		index++;
	return (index);
}
