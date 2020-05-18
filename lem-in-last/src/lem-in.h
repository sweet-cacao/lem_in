#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H
# define INT32_MAX 2147483647
# include "../libft/includes/ft_printf.h"
# include <stdio.h>

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
	int             buff_in;
	int             buff_out;
	int             no;
	int             time;
	int				code_link;
}                   t_graph;

typedef struct      s_gr_block
{
	int             in;
	int             out;
	int             count;
	struct s_gr_block *parent;
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
	int             num;
	int 			code;
}                   t_gr_block;

typedef struct      s_otv
{
    t_graph         *solve;
    struct s_otv    *next;
    struct s_otv    *prev;
    int             number;
    int             len;
    int				old;
}                   t_otv;

typedef struct      s_ants
{
	t_graph         *room;
	int             path;
	int             number;
	struct s_ants   *next;
}                   t_ants;

typedef struct 		s_glob
{
	t_otv			*tmp;
	t_graph			*graph;
	t_graph			*walk;
	t_graph			*new_answer_1;
	t_graph			*new_answer_2;
}					t_glob;

typedef struct 		s_num
{
	int 			i;
	int 			len;
	int 			change;
}					t_num;


char                *get_end(t_gr_block *buff, int len);
char                *get_start(t_gr_block *buff, int len);
int                 return_level(t_gr_block *buff, char *name, int len);
void belman_ford_req(t_gr_block *buff, int len, int ants, char *str);
void                print_ants_and_paths(int ants, t_otv *solutions);

t_graph             *add_line(t_links *connections, char *name);

t_graph             *get_next_graph(t_graph *graph);
t_graph             *add_block_graph(char *name, char *connection);
void                push_front_graph(t_graph **graph, char *name, char *connection);
void                delete_one_graph(t_graph **graph, char *name);
int                 count_links(t_graph *graph);
void			push_end_graph(t_graph **graph, char *name, char *connection);

t_gr_block          create_gr_block(t_links *connections, char *name);
t_gr_block          return_t_gr_block(t_gr_block *buff, int len, char *name);
t_gr_block          find_end(t_gr_block *buff, int len);

void                push_end_solution(t_otv **otv, t_graph *graph);
t_otv               *add_block_solution(t_graph *graph);
t_otv				*get_next_solution(t_otv *graph);
int					count_solutions(t_otv *graph);

void                print_graph(t_gr_block *buff, int len);
void                print_solutions(t_otv *otv);
void				print_links(char *text, t_graph *graph);

t_pointlist         *parse_map();

void bel_ford3(t_gr_block *buff, int len, int *otriz);
int                 return_j(t_gr_block *buff, int len, t_graph *links);
int		            return_j_by_block(t_gr_block *buff, int len, t_gr_block one_block);

int		            count_links(t_graph *graph);
int		            count_max_paths(t_gr_block *buff, int len);
t_graph		        *return_graph(t_otv *solutions, int path);
void		        sort_with_len(t_otv **solutions);
int			        is_in_room(t_ants *buff, int i, int ants);
int					is_sorted(t_otv *otv);
void		        give_len(t_otv **solutions);
void		        give_numbers_solution(t_otv **solutions);
void				del_solutions(t_otv **solutions);
void	            del_graph(t_graph **graph);
void	            del_buff_links(int len, t_gr_block *buff);
void	del_pointlist(t_pointlist **pointlist);
void parse_and_solve(int len, t_pointlist **mapa, int ants, char *str);
int     count_len_pointlist(t_pointlist *map);

t_gr_block		create_gr_block_end(t_links *connections, char *name);
t_gr_block		create_gr_block_start(t_links *connections, char *name);
t_gr_block		create_gr_block_in(t_links *connections, char *name);
t_gr_block		create_gr_block_out(t_links *connections, char *name);

t_gr_block	    return_t_gr_block_by_block(t_gr_block *buff, int len, t_gr_block *one_block);

int				check_duplicate_room(t_graph *graph, char *name, int code_gr);
t_graph *make_first(t_gr_block *buff, t_gr_block one_block);
int				check_same_link(t_graph *answer, t_otv **first, int ants);
void			del_sol_last_two(t_otv **otv, t_graph *first, t_graph *second);

//t_graph			*make_first(t_gr_block *buff, int len,
//						   t_gr_block one_block);
t_graph			*get_first_answer(t_graph *end_new, t_graph *whole_first);
t_graph			*get_second_answer(t_graph *whole_new, t_graph *end_first);
int				check_useful(t_otv **first, int ants);
int				compare_graph(t_graph *one, t_graph *two);
void			delete_first_gr(t_otv **sort);
void find_delete(t_otv **otv, t_graph *first, t_otv *tmp);
//void			del_sol_last_two(t_otv **otv, t_graph *first, t_graph *second);
void 			choose_place_for_del(t_otv **first, t_otv *tmp);
void			del_sol_old(t_otv **first);
void			overlay_solve(const t_gr_block *buff, t_gr_block *one_block, t_graph *links, t_graph *links2);
int				make_path_back(t_gr_block *buff, int len, t_gr_block one_block);
int				make_path_back_minus(t_gr_block *buff, int len, t_gr_block one_block);
//int				make_path_back_minus(t_gr_block *buff, int len, t_gr_block one_block);
void			reconstruct_initial(t_gr_block *buff, int len);
int				new_solutions_branch(t_otv **first, t_graph *new_answer_1, t_graph *new_answer_2, int ants);
int 			is_in_solutions_graph_links(t_otv **first, t_otv *tmp, t_graph *answer, int ants);
int				is_in_solutions_graph(t_otv **first, t_graph *tmp, int ants);
int				new_solutions(t_otv **first, t_graph *new_answer_1, t_graph *new_answer_2, int ants);
int				simple_solution(t_otv **first, int ants);

//t_gr_block		create_gr_block(t_links *connections, char *name);
t_graph			*add_line_out(t_links *connections, char *name);
t_graph			*add_line_out_start(t_links *connections, char *name);
t_graph			*add_line_in_end(t_links *connections, char *name);



#endif
