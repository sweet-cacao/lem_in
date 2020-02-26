#include "../includes/lem-in.h"

t_otv     *add_block_solution(char *name)
{
    t_otv *otv;

    otv = (t_otv*)malloc(sizeof(t_otv));
    otv->solve = add_block_graph(name, name);
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

void    push_front_solution(t_otv **otv, t_graph buff)
{
    t_otv	*tmp;

  //  if ((*otv) == NULL)
  //      (*otv) =
 //   else
  //  {
        tmp = get_last_solution(*otv);
        if (*otv)
            (*otv)->prev = tmp;
        tmp->next = (*otv);
        (*otv) = tmp;
    //}
}
