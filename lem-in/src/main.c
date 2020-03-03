#include <stdio.h>
#include "../includes/lem-in.h"

int main()
{
	t_otv *solution;
	char *name;
	char *name2;
	int num = 5;
	t_gr_block buff[11];
	int i;
	char **connections;

//	connections[i] = (char *)malloc(sizeof(char) * 3);
	connections = malloc(sizeof(char *) * num + 1);
	i = 0;
	while (i < num)
	{
		connections[i] = (char *)malloc(sizeof(char) * 3);
		i++;
	}
    connections[0] = "1";
    connections[1] = "9";
    connections[2] = "10";
    connections[3] = NULL;
    connections[4] = NULL;
 //   connections[5] = NULL;
//	connections = {"1", "2", "3"};
	i = 0;
	name = "0";
    buff[0] = create_gr_block(connections, name);
	buff[0].level = 0;
    buff[0].start = 1;
    name = "1";
	connections[0] = "2";
    connections[1] = "0";
    connections[2] = NULL;
    connections[3] = NULL;
    connections[4] = NULL;
 //   connections[5] = NULL;
    buff[1] = create_gr_block(connections, name);
    name = "9";
    connections[0] = "8";
    connections[1] = "0";
    connections[2] = NULL;
    connections[3] = NULL;
    connections[4] = NULL;
 //   connections[5] = NULL;
    buff[2] = create_gr_block(connections, name);
    name = "10";
	connections[0] = "0";
	connections[1] = "7";
	connections[2] = NULL;
	connections[3] = NULL;
	connections[4] = NULL;
//    connections[5] = NULL;
	buff[3] = create_gr_block(connections, name);
	name = "2";
	connections[0] = "1";
	connections[1] = "3";
	connections[2] = NULL;
	connections[3] = NULL;
	connections[4] = NULL;
//    connections[5] = NULL;
	buff[4] = create_gr_block(connections, name);
	name = "8";
	connections[0] = "9";
	connections[1] = "7";
	connections[2] = NULL;
	connections[3] = NULL;
	connections[4] = NULL;
//    connections[5] = NULL;
	buff[5] = create_gr_block(connections, name);
	name = "7";
	connections[0] = "10";
	connections[1] = "8";
	connections[2] = "4";
	connections[3] = "6";
	connections[4] = NULL;
//    connections[5] = NULL;
	buff[6] = create_gr_block(connections, name);
	name = "3";
	connections[0] = "2";
	connections[1] = "4";
	connections[2] = NULL;
	connections[3] = NULL;
	connections[4] = NULL;
//    connections[5] = NULL;
	buff[7] = create_gr_block(connections, name);
	name = "4";
	connections[0] = "5";
	connections[1] = "7";
	connections[2] = NULL;
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
	buff[10] = create_gr_block(connections, name);
    buff[10].end = 1;
    buff[10].level = INT32_MAX;

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
	belman_ford_req(buff, 11);
	print_graph(buff, 11);
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
