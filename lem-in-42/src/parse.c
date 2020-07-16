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

t_params	*short_part_1(t_params *params, char **split, char **str)
{
	ft_strdel(str);
	if (get_next_line(0, &(*str)) > 0)
	{
		ft_printf("%s\n", (*str));
		if ((*str)[0] == '#')
		{
			while ((*str)[0] == '#' && (*str)[1] != '#')
			{
				get_next_line(0, &(*str));
				ft_printf("%s\n", (*str));
			}
			if (((*str)[0] == '#' && (*str)[1] == '#') || (*str)[0] == 'L')
			{
				params->error_flag = 1;
				return (params);
			}
		}
		params->check_point++;
		params = second_part(params, split, *str);
	}
	return (params);
}

t_params	*short_part_2(t_params *params, char **split, char **str)
{
	ft_strdel(str);
	if (get_next_line(0, &(*str)) > 0)
	{
		ft_printf("%s\n", (*str));
		if ((*str)[0] == '#')
		{
			while ((*str)[0] == '#' && (*str)[1] != '#')
			{
				get_next_line(0, &(*str));
				ft_printf("%s\n", (*str));
			}
			if (((*str)[0] == '#' && (*str)[1] == '#') || (*str)[0] == 'L')
			{
				params->error_flag = 1;
				return (params);
			}
		}
	}
	params->check_point++;
	params = first_part(params, split, *str);
	return (params);
}

t_params	*help_func(t_params *params, char **split)
{
	if ((search_list(params->point_info, split[0])) != NULL)
		(search_list(params->point_info, split[0]))->links_list =
		plus_on_double_star_char((search_list(params->point_info,
		split[0]))->links_list, ft_strdup(split[1]));
	else
		params->error_flag = 1;
	if ((search_list(params->point_info, split[1])) != NULL)
		(search_list(params->point_info, split[1]))->links_list =
		plus_on_double_star_char((search_list(params->point_info,
		split[1]))->links_list, ft_strdup(split[0]));
	else
		params->error_flag = 1;
	free(split[0]);
	free(split[1]);
	free(split);
	return (params);
}

t_params	*final_fight(t_params *params, char **split, char **str,
			char *markers)
{
	params->check_point = 0;
	while (get_next_line(0, str) > 0 && (*str)[0] != '\n' && (*str)[0] != '\0')
	{
		ft_printf("%s\n", (*str));
		if ((*str)[0] == '#' && (*str)[1] != '#')
			;
		if ((*str)[0] == 'L')
		{
			params->error_flag = 1;
			return (params);
		}
		params = help_norm(params, str, split, markers);
		if ((*str)[0] == 'L' || (params->check_point != 2 &&
			ft_strchr((*str), '-')) || params->error_flag == 1)
		{
			ft_strdel(str);
			params->error_flag = 1;
			return (params);
		}
		ft_strdel(str);
	}
	if (params->check_point != 2)
		gnl_minus((*str), markers,1,0);
	ft_strdel(str);
	return (params);
}

t_params	*parse_map(void)
{
	char			*str;
	char			**split;
	char			*markers;
	t_params		*params;
	int				index;

	params = (t_params *)malloc(sizeof(t_params) * 1);
	params->ant_number = -1;
	markers = create_markers_line();
	index = 0;
	params->error_flag = 0;
	params->point_info = NULL;
	params->ant_number = ants(str, markers);
	if (params->ant_number < 0)
		return (params);
	params = final_fight(params, split, &str, markers);
	free(markers);
	return (params);
}
