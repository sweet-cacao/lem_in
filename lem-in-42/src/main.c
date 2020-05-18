/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstarvin <gstarvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:27:46 by gstarvin          #+#    #+#             */
/*   Updated: 2020/05/18 20:43:13 by sweet-cacao      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				flag_help(char *str)
{
	unsigned int			i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == 'h')
		{
			ft_printf("Usage: lem-in [-hsg] < [map]\n"
	"-h - help\n-g - print graph\n-s - print all "
	"solutions\n\nFor visualizer:\npython3 parse.py "
	"< [lem-in-output]\nP.S.: You need tkinter and PIL\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int				main(int ac, char **av)
{
	t_pointlist *map;
	int			ants;
	int			len;

	if (ac > 2 || (ac == 2 && ft_strlen(av[1]) > 4))
	{
		ft_printf("Wrong number of arguments or flags.\n"
		"Run with -h for help.\n");
		return (0);
	}
	if (ac == 2)
	{
		if (flag_help(av[1]) == 1)
			return (0);
	}
	map = parse_map();
	len = ((count_len_pointlist(map) - 2) * 2) + 2;
	ants = map->ants;
	parse_and_solve(len, &map, ants, av[1]);
	return (0);
}
