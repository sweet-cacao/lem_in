#include "lem-in.h"

void            printf_double_star_char(char **links)
{
	int     index;

	index = 0;
	while (links[index] != NULL)
	{
		printf("%s ",links[index]);
		index++;    }
	printf("\n");
}

void            mas_struct_print(t_pointlist *structs)
{
	t_pointlist     *index;

	index = 0;
	while (structs != NULL)
	{
		printf("\nstart_end = %s\nname_point = %s\ncoorditates = [%d, %d]\n", structs->start_end, structs->name_point, structs->coordinates[0], structs->coordinates[1]);
		printf("Links :");
		while (structs->links_list != NULL)
		{
			printf("%s, ", structs->links_list->link);
			structs->links_list = structs->links_list->next;
		}
		printf("\n");
		// printf_double_start_char(structs[index].links);
		structs = structs->next;
	}
	//printf("start_end = %s\nname_point = %s\ncoorditates = [%d, %d]\n\n", structs->start_end, structs->name_point, structs->coordinates[0], structs->coordinates[1]);
	//  printf_double_start_char(structs[index].links);
}

t_pointlist             *search_list(t_pointlist *point_info, char *search_name)
{
	while (point_info != NULL && ft_strcmp(point_info->name_point, search_name) != 0)
		point_info = point_info->next;
	if (point_info == NULL && ft_strcmp(point_info->name_point, search_name) != 0)
	{
		ft_putstr("ERROR\n");
		return (NULL);
	}
	return (point_info);
}

int             is_it_numbers_on_str(char *str, int a)
{
	int     i;

	i = 0;
	if (a)
	{
		while (str[i] != ' ' && str[i] != '\0')
			i++;
	}
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

/*int             for_each(char **str)
{
    int     index;

    index = 0;
    while (str[index] != NULL && is_it_numbers_on_str(str[index]))
        index++;
    if (str[index] == NULL)
        return (1);
    return (0);
}*/

int             len_double_star_char(char **str)
{
	int     index;

	index = 0;
	while (str[index] != NULL)
		index++;
	return (index);
}

t_pointlist     *list_creation()
{
	t_pointlist     *new_list;

	new_list = (t_pointlist *)malloc(sizeof(t_pointlist) * (1));
	return (new_list);
}

/*t_pointlist     *struct_calc(t_pointlist *main_list, t_pointlist *plus_struct)
{
    int             len_list;
    int             index;
    t_pointlist     *new_list;

    len_list = 0;
    index = 0;
    while (main_list->next != NULL)
    {
        len_list++;
    }
    new_list = (t_pointlist *)malloc(sizeof(t_pointlist) * (len_list + 1));
    printf("==============struct len = %d\n", len_list + 1);
    while (index <= len_list)
    {
        if (main_list->next == NULL)
        {
            plus_struct->next = NULL;
            new_list = plus_struct;
        }
        else
        {
            main_list->next;
            new_list = main_list;
        }
        index++;
    }
    return(new_list);
}*/

t_links            *plus_on_double_star_char(t_links *links_list, char *new_elem)
{
	t_links     *new;

	new = (t_links *)malloc(sizeof(t_links) * (1));
	new->link = new_elem;
	new->next = links_list;
	return (new);
}

t_pointlist            *parse_map()
{
	char            *str;
	char            **split;
	char            *markers;
	t_pointlist     *start;
	t_pointlist     *point_info;
	t_pointlist     *plus_part;
	int             ant_number;
	int             Links_check;
	int             index;

	ant_number = -1;
	Links_check = 0;
	index = ft_strlen("##start##end");
	markers = (char *)malloc(sizeof(char) * (index + 1));
	markers[index] = '\0';
	markers[0] = '#';
	markers[1] = '#';
	markers[2] = 's';
	markers[3] = 't';
	markers[4] = 'a';
	markers[5] = 'r';
	markers[6] = 't';
	markers[7] = '#';
	markers[8] = '#';
	markers[9] = 'e';
	markers[10] = 'n';
	markers[11] = 'd';
	index = 0;
	/* ft_putstr("sdl");
	 split = ft_strsplit(markers, '#');
	 ft_putstr("gggg");
	 printf("%s\n",split[0]);
	 while (split[index] != NULL)
		 ft_putstr(split[index++]);*/
	point_info = NULL;
//	int fd =0;
	int fd = 0;
	while (get_next_line(fd, &str) > 0) //число муравьев
	{
		ft_putstr(str);
		ft_putstr("\n");
		if(ft_strstr(markers, str) != NULL)
		{
			ft_putstr("ERROR\n");
			return (0);
		}
		if (is_it_numbers_on_str(str, 0))
		{
			ant_number = atoi(str);
			break;
		}
	}
	if (ant_number < 0)
	{
		printf("ERROR\n");
		return(0);
	}
	/*while (get_next_line(0, &str) > 0) //старт
	{
		ft_putstr(str);
		ft_putstr("\n");
		if (((int)ft_strstr(markers, str) - (int)markers) == 0 &&
			get_next_line(0, &str) > 0)
		{
			ft_putstr(str);
			ft_putstr("\n");
			split = ft_strsplit(str, ' ');
			plus_part = list_creation();
			plus_part->start_end = "start";
			plus_part->name_point = split[0];
			plus_part->coordinates[0] = ft_atoi(split[1]);
			plus_part->coordinates[1] = ft_atoi(split[2]);
			plus_part->links_list = NULL;
			plus_part->next = point_info;
			point_info = plus_part;
			break;
		}
		if (((int)ft_strstr(markers, str) - (int)markers == 7) || (ft_strchr(str, '-') && str[0] != '#'))
		{
			ft_putstr("ERROR\n");
			break;
		}
	}*/
	while (get_next_line(fd, &str) > 0) //конец и вершины+
	{
		ft_putstr(str);
		ft_putstr("\n");
		if (((int)ft_strstr(markers, str) - (int)markers) == 0 &&
		    get_next_line(fd, &str) > 0)
		{
			ft_putstr(str);
			ft_putstr("\n");
			split = ft_strsplit(str, ' ');
			plus_part = list_creation();
			plus_part->start_end = "start";
			plus_part->name_point = split[0];
			plus_part->coordinates[0] = ft_atoi(split[1]);
			plus_part->coordinates[1] = ft_atoi(split[2]);
			plus_part->links_list = NULL;
			plus_part->next = point_info;
			point_info = plus_part;
		}
		else if (((int)ft_strstr(markers, str) - (int)markers) == 7 &&
		         get_next_line(fd, &str) > 0)
		{
			ft_putstr(str);
			ft_putstr("\n");
			plus_part = list_creation();
			split = ft_strsplit(str, ' ');
			plus_part->start_end = "end";
			plus_part->name_point = split[0];
			plus_part->coordinates[0] = ft_atoi(split[1]);
			plus_part->coordinates[1] = ft_atoi(split[2]);
			plus_part->links_list = NULL;
			plus_part->next = point_info;
			point_info = plus_part;
		}
		else if (is_it_numbers_on_str(str, 1) && !(ft_strchr(str, '-')))
		{
			plus_part = list_creation();
			split = ft_strsplit(str, ' ');
			plus_part->name_point = split[0];
			plus_part->start_end = "simple";
			plus_part->coordinates[0] = ft_atoi(split[1]);
			plus_part->coordinates[1] = ft_atoi(split[2]);
			plus_part->links_list = NULL;
			plus_part->next = point_info;
			point_info = plus_part;
		}
		else if (str && (split = ft_strsplit(str, '-')) && len_double_star_char(split) == 2)
		{
			Links_check = 1;
			(search_list(point_info, split[0]))->links_list = plus_on_double_star_char((search_list(point_info, split[0]))->links_list, split[1]);
			(search_list(point_info, split[1]))->links_list = plus_on_double_star_char((search_list(point_info, split[1]))->links_list, split[0]);
		}
		else if ((ft_strchr(str, '-') && str[0] != '#') || ((int)ft_strstr(markers, str) - (int)markers) == 0)
		{
			ft_putstr("ERROR\n");
			break;
		}
	}
	point_info->ants = ant_number;
	return (point_info);
}