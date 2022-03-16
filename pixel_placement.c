/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_placement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:45:29 by vlaine            #+#    #+#             */
/*   Updated: 2022/03/16 14:58:46 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void draw_line(int x0, int y0, int x1, int y1, t_params *params)
{
    int dx, dy, p, x, y, sx, sy, e2, error;

/*	x0 = ((x0 * 1000)/100) + 500;
	y0 = ((y0 * 1000)/100) + 500;
	x1 = ((x1 * 1000)/100) + 500;
	y1 = ((y1 * 1000)/100) + 500;*/
    dx = abs(x1 - x0);
    if (x0 < x1)
        sx = 1;
    else
        sx = -1;
    dy = -abs(y1 - y0);
    if (y0 < y1)
        sy = 1;
    else
        sy = -1;
    error = dx + dy;
    while (1)
    {
        mlx_pixel_put(params->mlx_ptr, params->win_ptr, x0, y0, 0xffffff);
        if (x0 == x1 && y0 == y1)
            break;
        e2 = 2 * error;
        if (e2 >= dy)
        {
            if (x0 == x1)
                break;
            error = error + dy;
            x0 = x0 + sx;
        }
        if (e2 <= dx)
        {
            if (y0 == y1)
                break;
            error = error + dx;
            y0 = y0 + sy;
        }
    }
}

void pixel_placement(t_params *params)
{
	int	x;
	int	y;
	int	*ptr;
	int	*ptr1;
	int	coord[3];
	int	coordi[3];

	y = 0;
	while (params->coord[y])
    {
        x = 0;
        while(params->coord[y][x])
        {
			coord[0] = params->coord[y][x][0] * 25;
			coord[1] = params->coord[y][x][1] * 25;
			coord[2] = params->coord[y][x][2];
            ptr = rotation_matrices(coord, params);
            if (x > 0)
            {
				coordi[0] = params->coord[y][x - 1][0] * 25;
				coordi[1] = params->coord[y][x - 1][1] * 25;
				coordi[2] = params->coord[y][x - 1][2];
				ptr1 = rotation_matrices(coordi, params);
                draw_line(ptr1[0], ptr1[1], ptr[0], ptr[1], params);
				free(ptr1);
            }
            if (y > 0)
            {
				coordi[0] = params->coord[y - 1][x][0] * 25;
				coordi[1] = params->coord[y - 1][x][1] * 25;
				coordi[2] = params->coord[y - 1][x][2];
				ptr1 = rotation_matrices(coordi, params);
                draw_line(ptr1[0], ptr1[1], ptr[0], ptr[1], params);
				free(ptr1);
            }
			free(ptr);
            x++;
        }
        y++;
    }
}

void redraw(int key, t_params *params)
{

}

/**
void pixel_placement(t_params *params)
{
	int	x;
	int	y;
	int *xyz;
	int	*ptr;
	int	*ptr1;
	y = 0;
	while (params->coord[y])
    {
        x = 0;
        while(params->coord[y][x])
        {
			params->coord[y][x][0] = params->coord[y][x][0] * 30;
			params->coord[y][x][1] = params->coord[y][x][1] * 30;
            ptr = rotation_matrices(params->coord[y][x], params);
            if (x > 0)
            {
				ptr1 = rotation_matrices(params->coord[y][x - 1], params);
                draw_line(params->coord[y][x - 1][0], params->coord[y][x - 1][1], params->coord[y][x][0], params->coord[y][x][1], params);
            }
            if (y > 0)
            {
				ptr1 = rotation_matrices(params->coord[y - 1][x], params);
                draw_line(params->coord[y - 1][x][0], params->coord[y - 1][x][1], params->coord[y][x][0], params->coord[y][x][1], params);
            }
            x++;
        }
        y++;
    }
} 
 */