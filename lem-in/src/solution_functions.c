#include "../includes/lem-in.h"

t_otv     *add_block_solution(t_graph *graph)
{
    t_otv *otv;

    otv = (t_otv*)malloc(sizeof(t_otv));
    otv->solve = graph;
    otv->next = NULL;
    otv->prev = NULL;
    return (otv);
}

t_otv    *get_last_solution(t_otv *solution)
{
    if (solution == NULL)
        return (NULL);
    while(solution->next)
        solution = solution->next;
    return (solution);
}

void    push_front_solution(t_otv **otv, t_graph *graph)
{
    t_otv	*tmp;

	tmp = add_block_solution(graph);
    if ((*otv) == NULL)
        (*otv) = tmp;
    else
    {

        if (*otv)
            (*otv)->prev = tmp;
        tmp->next = (*otv);
        (*otv) = tmp;
    }
}
