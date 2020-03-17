/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:27:46 by gstarvin          #+#    #+#             */
/*   Updated: 2020/03/13 17:31:41 by gstarvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

int				main(void)
{
	t_pointlist *map;
	int			ants;
	int			len;

	map = parse_map();
	len = ((count_len_pointlist(map) - 2) * 2) + 2;
	ants = map->ants;
	parse_and_solve(len, &map, ants);
	return (0);
}
