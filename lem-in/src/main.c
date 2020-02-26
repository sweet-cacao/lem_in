#include <stdio.h>
#include "../includes/lem-in.h"

int main()
{
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

            /*	while(i < num)
	{
	    buff[i] = create_gr_block(connections, name);
	//	buff[i] = add_line(connections, name);
		name = "5";
		i++;
	}*/
//	buff[i] = NULL;
    solve_lemin(4, buff);

	i = 0;
	while (i < 4)
	{
		printf("%s : lev = %d, %s, %s\n", buff[i].name, buff[i].level, buff[i].links->link, buff[i].links->next->link);//, buff[i].links->next->next->link);
		i++;
	}
	return 0;
}
