#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

#include "../libft/ft_str/libft.h"

typedef struct      s_lemin
{
	int             ants;
	int             rooms;
	char            *start;
	char            *end;
}                   t_lemin;

typedef struct      s_graph
{
	 char           *name;
	 char           *link;
	 struct s_graph *next;
}                   t_graph;

typedef struct      s_gr_block
{
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

void                solve_lemin(int len, t_gr_block *buff);

t_graph             *add_line(char **connections, char *name);

t_graph             *get_next_graph(t_graph *graph);
t_graph             *add_block_graph(char *name, char *connection);
void                push_front_graph(t_graph **graph, char *name, char *connection);

t_gr_block          create_gr_block(char **connections, char *name);

void                push_front_solution(t_otv **otv, t_graph buff);
t_otv               *add_block_solution(char *name);

#endif
