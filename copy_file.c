/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:34:00 by vlaine            #+#    #+#             */
/*   Updated: 2022/03/17 17:37:23 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_fdf	*new_list(t_fdf *head)
{
	t_fdf	*new;

	new = malloc(sizeof(t_fdf));
	if (new == NULL)
	{
		//free_list(head);
		exit (0);
	}
	new->next = NULL;
	return (new);
}

static void		malloc_coordinates(t_params *params, t_fdf *head)
{
	t_fdf	*elem;
	int		index;
	int		x;
	int		y;

	elem = head;
	y = 0;
	while (elem && elem->line)
	{
        index = 0;
        x = 0;
        while (elem->line[index])
        {
            if (index > 0)
                if ((elem->line[index - 1] != ' ' && elem->line[index] == ' ') || elem->line[index + 1] == '\0')
                    x++;
            index++;
        }
        params->coord[y] = (int **)malloc(sizeof(int *) * x + 1);
        params->coord[y][x] = NULL;
        y++;
        elem = elem->next;
	}
}

t_fdf	*read_file(t_params *params, int fd)
{
	t_fdf	*head;
	t_fdf	*elem;
	char	*line;
	int		gnl;
	int		index;

	index = 0;
	head = new_list(NULL);
	elem = head;
	gnl = get_next_line(fd, &elem->line);
	params->loc_x = ft_strlen(elem->line);
	while (gnl > 0)
	{
		elem->next = new_list(elem);
		elem = elem->next;
		index++;
		gnl = get_next_line(fd, &elem->line);
		/*if (elem->line && params->loc_x != ft_strlen(elem->line))
		{
			ft_putendl("error lines dont match in length");
			//free
			exit(0);
		}*/
	}
	elem->line = NULL;
	params->coord = (int ***)malloc(sizeof(int **) * index + 1);
	malloc_coordinates(params, head);
	return(head);
}
