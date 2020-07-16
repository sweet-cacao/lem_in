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

t_pointlist	*sort_list(t_pointlist *point_info)
{
	t_pointlist		*save_point_before;
	t_pointlist		*save_point;
	t_pointlist		*save_end;

	save_point = point_info;
	save_point_before = search_list_(point_info, 't');
	point_info = save_point_before->next;
	save_point_before->next = point_info->next;
	point_info->next = save_point;
	save_point = point_info;
	save_point_before = search_list_(point_info, 'n');
	point_info = save_point_before->next;
	save_end = point_info;
	save_point_before->next = point_info->next;
	point_info = save_point;
	while (point_info->next != NULL)
		point_info = point_info->next;
	point_info->next = save_end;
	save_end->next = NULL;
	point_info->next = save_end;
	return (put_nums(save_point));
}

int			ants(char *str, char *markers)
{
	long int		ant_number;
	int				k;

	ant_number = -1;
	while ((k = get_next_line(0, &str)) > 0 && str[0] != '\0' && str != NULL)
	{
		if (dotka_help(str, markers, 0, k) || str[0] == '\0' || k == 0)
			return (-1);
		if (is_it_numbers_on_str(str, 0))
		{
			ant_number = atoi(str);
			ft_printf("%d\n", ant_number);
			break ;
		}
		free(str);
	}
	gnl_minus(str, markers, 1, k);
	free(str);
	return (ant_number);
}

t_params	*first_part(t_params *params, char **split, char *str)
{
	split = ft_strsplit(str, ' ');
	params->plus_part = list_creation();
	params->plus_part->start_end = "end";
	params->plus_part->name_point = split[0];
	params->plus_part->coordinates[0] = ft_atoi(split[1]);
	if (split[2])
		params->plus_part->coordinates[1] = ft_atoi(split[2]);
	params->plus_part->links_list = NULL;
	params->plus_part->next = params->point_info;
	params->point_info = params->plus_part;
	if (str[0] == 'L' || !(split[1]) || !(split[2]))
		params->error_flag = 1;
	free(split[1]);
	free(split[2]);
	free(split);
	return (params);
}

t_params	*second_part(t_params *params, char **split, char *str)
{
	split = ft_strsplit(str, ' ');
	params->plus_part = list_creation();
	params->plus_part->start_end = "start";
	params->plus_part->name_point = split[0];
	params->plus_part->coordinates[0] = ft_atoi(split[1]);
	if (split[2])
		params->plus_part->coordinates[1] = ft_atoi(split[2]);
	params->plus_part->links_list = NULL;
	params->plus_part->next = params->point_info;
	params->point_info = params->plus_part;
	if (str[0] == 'L' || !(split[1]) || !(split[2]))
		params->error_flag = 1;
	free(split[1]);
	free(split[2]);
	free(split);
	return (params);
}

t_params	*last_part(t_params *params, char **split, char *str)
{
	params->plus_part = list_creation();
	split = ft_strsplit(str, ' ');
	if (len_double_star_char(split) != 3)
		params->error_flag = 1;
	params->plus_part->name_point = split[0];
	params->plus_part->start_end = "simple";
	params->plus_part->coordinates[0] = ft_atoi(split[1]);
	if (split[2])
		params->plus_part->coordinates[1] = ft_atoi(split[2]);
	params->plus_part->links_list = NULL;
	params->plus_part->next = params->point_info;
	params->point_info = params->plus_part;
	if (str[0] == 'L' || !(split[1]) || !(split[2]))
		params->error_flag = 1;
	free(split[1]);
	free(split[2]);
	free(split);
	return (params);
}
