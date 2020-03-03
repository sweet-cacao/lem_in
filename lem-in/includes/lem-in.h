#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

#include "../libft/ft_str/libft.h"
#include <stdio.h>
typedef struct      s_lemin
{
	int             ants;
	int             rooms;
	char            *start;
	char            *end;
}                   t_lemin;

typedef struct      s_graph
{

	char           *link;
	struct s_graph *next;
	int             in;
	int             out;
	int             weight_link;
}                   t_graph;

typedef struct      s_gr_block
{
	int             count;
	struct s_gr_block     *parent;
	char            *parent_name;
	int             iter;
	int             weight_edge;
	int             dead_end;
	int             start;
	int             end;
	int             level;
	char            *name;
	t_graph         *links;
}                   t_gr_block;

typedef struct      s_otv
{
    t_graph         *solve;
    struct s_otv    *next;
    struct s_otv    *prev;
}                   t_otv;

void                bfs_algorythm(int len, t_gr_block *buff);
void                delete_useless_links(int len, t_gr_block *buff);
t_otv               *suurbale(int len, t_gr_block *buff, int ants);
char                *get_end(t_gr_block *buff, int len);
char                *get_start(t_gr_block *buff, int len);
int                 return_level(t_gr_block *buff, char *name, int len);
t_otv               *get_solution(int len, t_gr_block *buff);
void                belman_ford_req(t_gr_block *buff, int len);
void                give_directions(t_gr_block *buff, int len);

t_graph             *add_line(char **connections, char *name);

t_graph             *get_next_graph(t_graph *graph);
t_graph             *add_block_graph(char *name, char *connection);
void                push_front_graph(t_graph **graph, char *name, char *connection);
void                delete_one_graph(t_graph **graph, char *name);

t_gr_block          create_gr_block(char **connections, char *name);
t_gr_block          return_t_gr_block(t_gr_block *buff, int len, char *name);
t_gr_block          find_end(t_gr_block *buff, int len);

void                push_front_solution(t_otv **otv, t_graph buff);
t_otv               *add_block_solution(char *name);

void                print_graph(t_gr_block *buff, int len);

#endif
