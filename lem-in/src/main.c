#include <stdio.h>
#include "../includes/lem-in.h"

int main()
{
	t_otv *solution;
	char *name = "4";
	int num = 4;
	t_gr_block buff[num];
	int i;
	char **connections;

	connections = malloc(sizeof(char *) * num + 1);
	i = 0;
	while (i < num)
	{
		connections[i] = (char *)malloc(sizeof(char) * 2);
		i++;
	}
    connections[0] = "2";
    connections[1] = "3";
    connections[2] = NULL;
    connections[3] = NULL;
  //  connections[4] = NULL;
 //   connections[5] = NULL;
//	connections = {"1", "2", "3"};
	i = 0;
	name = "1";
    buff[0] = create_gr_block(connections, name);
	buff[0].level = 0;
    buff[0].start = 1;
    name = "2";
	connections[0] = "1";
    connections[1] = "6";
    connections[2] = NULL;
    connections[3] = NULL;
 //   connections[4] = NULL;
 //   connections[5] = NULL;
    buff[1] = create_gr_block(connections, name);
    name = "3";
    connections[0] = "1";
    connections[1] = "6";
    connections[2] = NULL;
    connections[3] = NULL;
  //  connections[4] = NULL;
 //   connections[5] = NULL;
    buff[2] = create_gr_block(connections, name);
    name = "6";
    connections[0] = "2";
    connections[1] = "3";
    connections[2] = NULL;
    connections[3] = NULL;
 //   connections[4] = NULL;
//    connections[5] = NULL;
    buff[3] = create_gr_block(connections, name);
    buff[3].end = 1;
    buff[3].level = INT32_MAX;

            /*	while(i < num)
	{
	    buff[i] = create_gr_block(connections, name);
	//	buff[i] = add_line(connections, name);
		name = "5";
		i++;
	}*/
//	buff[i] = NULL;

	bfs_algorythm(4, buff);
	give_directions(buff, 4);
//	delete_useless_links(4, buff);
//	solution = get_solution(4, buff);
	belman_ford_req(buff, 4);
	/*while (solution->solve)
	{
		printf("%s\n", solution->solve->link);
		solution->solve = solution->solve->next;
	}*/

	i = 0;
	while (i < 4)
	{
		printf("%s : lev = %d, %s, in = %d, out = %d, %s, in = %d, out = %d\n", buff[i].name, buff[i].weight_edge, buff[i].links->link, buff[i].links->in, buff[i].links->out, buff[i].links->next->link, buff[i].links->next->in, buff[i].links->next->out );//, buff[i].links->next->next->link);
		i++;
	}
	return 0;
}
