#include "../includes/lem-in.h"

void    delete_output_same_level_links(int len, t_gr_block *buff, t_gr_block *buff2)
{
	t_graph *tmp;

	tmp = buff2->links;
	while(tmp)
	{
		if (return_level(buff, tmp->link, len) == buff2->level || return_level(buff, tmp->link, len) == -1)
		{
			delete_one_graph(&buff2->links, tmp->link);
			return ;
		}
		tmp = tmp->next;
	}
}

void    delete_dead_ends(int len, t_gr_block *buff)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (buff[i].links == NULL)
			buff[i].dead_end = 1;
		i++;
	}
}

void    delete_useless_links(int len, t_gr_block *buff)
{
	int i;

	i = 0;
	while (i < len)
	{
		delete_output_same_level_links(len, buff, &buff[i]);
		i++;
	}
	delete_dead_ends(len, buff);
}