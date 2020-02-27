#include "../includes/lem-in.h"

void    get_null_levels(int len, t_gr_block *buff)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (buff[i].start == 1)
			buff[i].level = 0;
		else if (buff[i].end == 1)
			buff[i].level = INT32_MAX;
		else
			buff[i].level = -1;
		i++;
	}
}


t_otv   *suurbale(int len, t_gr_block *buff, int ants)
{
	t_otv *solution;
	t_otv *new_solution;

	solution = get_solution();
	while (sensible(new_solution, ants) < sensible(solution, ants))
	{
		get_null_levels(len, buff);
		
	}
}