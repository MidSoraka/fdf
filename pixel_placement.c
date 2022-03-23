/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_placement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:45:29 by vlaine            #+#    #+#             */
/*   Updated: 2022/03/23 03:00:26 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void draw_line(int x0, int y0, int x1, int y1, t_params *params)
{
    int		dx, dy, p, x, y, sx, sy, e2, error;
	char	*image_add;
	int		test, test1, test2, test3;

	image_add = mlx_get_data_addr(params->mlx->image_ptr, &test, &test1, &test2);
	test3 =  2147483647;
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
	//	if (((int *)image_add)[x0 + (test1/2) * y0] == '\0')
			((int *)image_add)[x0 + (test1/4) * y0] = test3;
	//	else
	//		((int *)image_add)[x0 + (test1/2) * y0] = '\0';
        //mlx_pixel_put(params->mlx_ptr, params->win_ptr, x0, y0, 0xffffff);
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
	int	ptr[3];
	int	ptr1[3];
	int	coord[3];
	int	coordi[3];

	y = 0;
	while (params->coord[y])
    {
        x = 0;
        while(params->coord[y][x])
        {
			//params->coord[y][x][2] = 0;
			coord[0] = params->coord[y][x][0] * 25;
			coord[1] = params->coord[y][x][1] * 25;
			coord[2] = params->coord[y][x][2] * 10;
            rotation_matrices(coord, params, ptr);
            if (x > 0)
            {
				coordi[0] = params->coord[y][x - 1][0] * 25;
				coordi[1] = params->coord[y][x - 1][1] * 25;
				coordi[2] = params->coord[y][x - 1][2] * 10;
				rotation_matrices(coordi, params, ptr1);
                draw_line(ptr1[0] + params->loc_x, ptr1[1] + params->loc_y, ptr[0] + params->loc_x, ptr[1] + params->loc_y, params);
            }
            if (y > 0)
            {
				coordi[0] = params->coord[y - 1][x][0] * 25;
				coordi[1] = params->coord[y - 1][x][1] * 25;
				coordi[2] = params->coord[y - 1][x][2] * 10;
				rotation_matrices(coordi, params, ptr1);
                draw_line(ptr1[0] + params->loc_x, ptr1[1] + params->loc_y, ptr[0] + params->loc_x, ptr[1] + params->loc_y, params);
            }
            x++;
        }
        y++;
    }
}
