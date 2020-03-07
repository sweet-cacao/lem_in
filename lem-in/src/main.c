#include <stdio.h>
#include "../includes/lem-in.h"

int     count_len_pointlist(t_pointlist *map)
{
	int i;

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

/*t_gr_block  *create_buff(int len, t_pointlist *map, t_gr_block **buff)
{
	int i;
//	t_gr_block buff[len];
	i = 0;
	buff = malloc(sizeof(t_gr_block*) * len);
	while (i < len)
	{
		(*buff[i]) = create_gr_block(map->links_list, map->name_point);
		i++;
	}
	return (*buff);
}*/

int main()
{
	t_otv *solution;
	char *name;
	char *name2;
	int num = 5;
	int ants;

	int i;
	char **connections;
	t_pointlist *map;
	int len;
	i = 0;
	map = parse_map();
	len = count_len_pointlist(map);
	ants = map->ants;
	t_gr_block buff[len];
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
	i = 0;
	t_gr_block one = return_t_gr_block(buff, len, get_start(buff, len));

//	buff = create_buff(len, map, &buff);

//	t_gr_block buff[len];


//	connections[i] = (char *)malloc(sizeof(char) * 3);
/*	connections = malloc(sizeof(char *) * num + 1);

	while (i < num)
	{
		connections[i] = (char *)malloc(sizeof(char) * 3);
		i++;
	}
    connections[0] = "1";
    connections[1] = "2";
    connections[2] = NULL;
    connections[3] = NULL;
    connections[4] = NULL;
 //   connections[5] = NULL;
//	connections = {"1", "2", "3"};
	i = 0;
	name = "0";
    buff[0] = create_gr_block(connections, name);
    buff[0].weight_edge = 0;
	buff[0].level = 0;
    buff[0].start = 1;
    name = "1";
	connections[0] = "4";
    connections[1] = "0";
    connections[2] = NULL;
    connections[3] = NULL;
    connections[4] = NULL;
 //   connections[5] = NULL;
    buff[1] = create_gr_block(connections, name);
    name = "2";
    connections[0] = "5";
    connections[1] = "3";
    connections[2] = "0";
    connections[3] = NULL;
    connections[4] = NULL;
 //   connections[5] = NULL;
    buff[2] = create_gr_block(connections, name);
    name = "3";
	connections[0] = "2";
	connections[1] = "5";
	connections[2] = "6";
	connections[3] = NULL;
	connections[4] = NULL;
//    connections[5] = NULL;
	buff[3] = create_gr_block(connections, name);
	name = "4";
	connections[0] = "1";
	connections[1] = "5";
	connections[2] = NULL;
	connections[3] = NULL;
	connections[4] = NULL;
//    connections[5] = NULL;
	buff[4] = create_gr_block(connections, name);
	name = "5";
	connections[0] = "4";
	connections[1] = "2";
	connections[2] = "3";
	connections[3] = "7";
	connections[4] = NULL;
//    connections[5] = NULL;
	buff[5] = create_gr_block(connections, name);
	name = "6";
	connections[0] = "7";
	connections[1] = "3";
	connections[2] = NULL;
	connections[3] = NULL;
	connections[4] = NULL;
//    connections[5] = NULL;
	buff[6] = create_gr_block(connections, name);
	name = "7";
	connections[0] = "5";
	connections[1] = "6";
	connections[2] = NULL;
	connections[3] = NULL;
	connections[4] = NULL;
//    connections[5] = NULL;
	buff[7] = create_gr_block(connections, name);*/
/*	name = "4";
	connections[0] = "5";
	connections[1] = "7";
	connections[2] = "3";
	connections[3] = NULL;
	connections[4] = NULL;
//    connections[5] = NULL;
	buff[8] = create_gr_block(connections, "4");
	name = "6";
	connections[0] = "7";
	connections[1] = "5";
	connections[2] = NULL;
	connections[3] = NULL;
	connections[4] = NULL;
//    connections[5] = NULL;
	buff[9] = create_gr_block(connections, name);
	name = "5";
	connections[0] = "4";
	connections[1] = "6";
	connections[2] = NULL;
	connections[3] = NULL;
	connections[4] = NULL;
//    connections[5] = NULL;
	buff[10] = create_gr_block(connections, name);*/
 /*   buff[7].end = 1;
    buff[7].level = INT32_MAX;*/

            /*	while(i < num)
	{
	    buff[i] = create_gr_block(connections, name);
	//	buff[i] = add_line(connections, name);
		name = "5";
		i++;
	}*/
//	buff[i] = NULL;

//	bfs_algorythm(4, buff);
//	give_directions(buff, 4);
//	delete_useless_links(4, buff);
//	solution = get_solution(4, buff);

	belman_ford_req(buff, len, ants);
//	print_graph(buff, len);
	/*while (solution->solve)
	{
		printf("%s\n", solution->solve->link);
		solution->solve = solution->solve->next;
	}*/

/*	i = 0;
	while (i < 4)
	{
		printf("%s : lev = %d, %s, in = %d, out = %d, %s, in = %d, out = %d\n", buff[i].name, buff[i].weight_edge, buff[i].links->link, buff[i].links->in, buff[i].links->out, buff[i].links->next->link, buff[i].links->next->in, buff[i].links->next->out );//, buff[i].links->next->next->link);
		i++;
	}*/
	return 0;
}


