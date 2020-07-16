/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:28:10 by gstarvin          #+#    #+#             */
/*   Updated: 2020/05/17 16:38:49 by sweet-cacao      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				gnl_minus(char *str, char *markers, int n, int k)
{
	if (!(k > 0) || str[0] == '\0' || str == NULL)
	{
		ft_printf("[2]ERROR\n");
		exit(-1);
	}
	return (0);
}

char			*delspace_h(char *str)
{
	char	*new;
	int		i;
	int		len;

	i = 0;
	len = 1;
	while (str[i] != '\0' && len++)
	{
		while ((str[i] == ' ' || str[i] == '	') && str[i] != '\0')
			i++;
		i++;
	}
	new = (char *)malloc(sizeof(char) * (len));
	new[len - 1] = '\0';
	i = 0;
	len = 0;
	while (str[i])
	{
		while ((str[i] == ' ' || str[i] == '	') && str[i])
			i++;
		new[len++] = str[i++];
	}
	free(str);
	return (new);
}

t_params		*help_norm(t_params *params, char **str, char **split,
				char *markers)
{
	if ((*str)[0] == '#' && (*str)[1] == '#' && params->check_point == 2)
		params->error_flag = 1;
	else if (((int)ft_strstr(markers, *str) - (int)markers) == 0 &&
			!(ft_strchr((*str), '-')))
		params = short_part_1(params, split, str);
	else if (((int)ft_strstr(markers, *str) - (int)markers) == 7 &&
			!(ft_strchr((*str), '-')))
		params = short_part_2(params, split, str);
	else if (is_it_numbers_on_str(*str, 1) &&
			!(ft_strchr(*str, '-')))
		params = last_part(params, split, *str);
	else if ((ft_strchr((*str), '-') && *str && (split =
		ft_strsplit(*str, '-')) && len_double_star_char(split) == 2)
		&& params->check_point == 2)
	{
		params->error_flag = search_same_coord(params);
		if (params->error_flag == 0)
			params->error_flag = search_same_room_name(params);
		params = help_func(params, split);
	}
	else if (((ft_strchr((*str), '-') && (*str)[0] != '#') ||
			((int)ft_strstr(markers, *str) - (int)markers) == 0))
		params->error_flag = 1;
	return (params);
}

int				search_same_coord(t_params *params)
{
	t_pointlist	*save_point_info;
	t_pointlist	*point_f;

	save_point_info = params->point_info;
	point_f = params->point_info;
	while (point_f->next)
	{
		save_point_info = point_f->next;
		while (save_point_info != NULL && ((save_point_info->coordinates[0] !=
			point_f->coordinates[0]) || (save_point_info->coordinates[1] !=
			point_f->coordinates[1])))
			save_point_info = save_point_info->next;
		if (save_point_info)
			return (1);
		point_f = point_f->next;
	}
	return (0);
}

int				search_same_room_name(t_params *params)
{
	t_pointlist	*save_point_info;
	t_pointlist	*point_f;

	save_point_info = params->point_info;
	point_f = params->point_info;
	while (point_f->next)
	{
		save_point_info = point_f->next;
		while (save_point_info != NULL &&
		(ft_strcmp(save_point_info->name_point, point_f->name_point)) != 0)
			save_point_info = save_point_info->next;
		if (save_point_info)
			return (1);
		point_f = point_f->next;
	}
	return (0);
}
