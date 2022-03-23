/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:42:41 by vlaine            #+#    #+#             */
/*   Updated: 2022/03/17 17:24:43 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_params(t_params *params)
{
	int	x;
	int	y;

	y = 0;
	while (params->coord[y])
	{
		x = 0;
		while (params->coord[y][x])
		{
			free(params->coord[y][x]);
			x++;
		}
		free(params->coord[y]);
		y++;
	}
}

void	free_fdf(t_fdf *head)
{
	t_fdf	*hold;

	while (head != NULL)
	{
		hold = head->next;
		if (head->line != NULL)
			free(head->line);
		free(head);
		head = hold;
	}
}

void	free_all(t_params *params, t_fdf *head)
{
	free_fdf(head);
	free_params(params);
}
