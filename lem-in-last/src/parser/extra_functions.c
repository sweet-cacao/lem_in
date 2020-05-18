#include "../lem-in.h"

void        delete_one_graph(t_graph **graph, char *name)
{
	t_graph *tmp;
	t_graph *tmp2;

	if (graph == NULL || (*graph) == NULL)
		return ;
	tmp = (*graph);
	tmp2 = tmp;
	while (tmp)
	{
		if (ft_strcmp(tmp->link, name) == 0)
		{
			if (tmp == tmp2)
			{
				(*graph) = (*graph)->next;
				free(tmp);
				tmp = NULL;
			}
			else
			{
				free(tmp2->next);
				tmp2->next = NULL;
				tmp2->next = tmp2->next->next;
			}
		}
		tmp2 = tmp;
		tmp = tmp->next;//why warning
	}
}
