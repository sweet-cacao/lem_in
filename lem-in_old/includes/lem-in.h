#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

#include "../libft/ft_str/libft.h"
#include <stdio.h>

typedef struct              s_links
{
	char                    *link;
	struct s_links          *next;
}                           t_links;

typedef struct              s_pointlist
{
	int                     ants;
	int                     level;
	char                    *start_end;
	char                    *name_point;
	int                     coordinates[2];
	t_links                 *links_list;
	struct s_pointlist      *next;
}                           t_pointlist;

typedef struct      s_lemin
{
	int             ants;
	int             rooms;
	char            *start;
	char            *end;
}                   t_lemin;

typedef struct      s_graph
{
	int             duplicate;
	char           *link;
	struct s_graph *next;
	int             in;
	int             out;
	int             weight_link;
	int             num_buff;
}                   t_graph;

typedef struct      s_gr_block
{
	int             count;
	struct s_gr_block     *parent;
	char            *prev;
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
    int             number;
    int             len;
}                   t_otv;

typedef struct      s_ants
{
	t_graph            *room;
	int             path;
	int             number;
	struct s_ants   *next;
}                   t_ants;

void                bfs_algorythm(int len, t_gr_block *buff);
void                delete_useless_links(int len, t_gr_block *buff);
t_otv               *suurbale(int len, t_gr_block *buff, int ants);
char                *get_end(t_gr_block *buff, int len);
char                *get_start(t_gr_block *buff, int len);
int                 return_level(t_gr_block *buff, char *name, int len);
t_otv               *get_solution(int len, t_gr_block *buff);
void                belman_ford_req(t_gr_block *buff, int len, int ants);
void                give_directions(t_gr_block *buff, int len);
void                print_ants_and_paths(int ants, t_otv *solutions);

t_graph             *add_line(t_links *connections, char *name);

t_graph             *get_next_graph(t_graph *graph);
t_graph             *add_block_graph(char *name, char *connection);
void                push_front_graph(t_graph **graph, char *name, char *connection);
void                delete_one_graph(t_graph **graph, char *name);
int                 count_links(t_graph *graph);

t_gr_block          create_gr_block(t_links *connections, char *name);
t_gr_block          return_t_gr_block(t_gr_block *buff, int len, char *name);
t_gr_block          find_end(t_gr_block *buff, int len);

void                push_front_solution(t_otv **otv, t_graph *graph);
t_otv               *add_block_solution(t_graph *graph);

void                print_graph(t_gr_block *buff, int len);
void                print_solutions(t_otv *otv);

t_pointlist            *parse_map();

void    bel_ford2(int len, t_gr_block *buff);
void    bel_ford3(t_gr_block *buff, int len);
int     return_j(t_gr_block *buff, int len, char *name);
#endif
