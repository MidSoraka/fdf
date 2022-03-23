/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:40:32 by vlaine            #+#    #+#             */
/*   Updated: 2022/03/23 02:50:31 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int draw_extra_line(void *params)
{
	int test1, test2, test3;
	t_params *local;
	t_mlx *mlx;

	local = ((t_params *)params);
	mlx = local->mlx;
	mlx->image_ptr = mlx_new_image(mlx->mlx_ptr, local->win_x, local->win_y);
	mlx->image_add = mlx_get_data_addr(mlx->image_ptr, &test1, &test2, &test3);
	pixel_placement(local);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image_ptr, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, mlx->image_ptr);
	return (0);
}

int exit_window(int key, void *params)
{
	int index;
	if (key == 31)
		((t_params *)params)->alpha += 5;
	if (key == 34)
		((t_params *)params)->alpha -= 5;
	if (key == 38)
		((t_params *)params)->beta -= 5;
	if (key == 40)
		((t_params *)params)->beta += 5;
	if (key == 7)
		((t_params *)params)->loc_x += 50;
	if (key == 8)
		((t_params *)params)->loc_x -= 50;
	if (key == 16)
		((t_params *)params)->loc_y += 50;
	if (key == 32)
		((t_params *)params)->loc_y -= 50;
	if (key == 15)
	{
		((t_params *)params)->loc_x = 0;
		((t_params *)params)->loc_y = 0;
		((t_params *)params)->alpha = 0;
		((t_params *)params)->beta = 0;
	}
	if (key == 53)
		exit(0);
	printf("\nalpha is %f\nbeta is %f\n", ((t_params *)params)->alpha, ((t_params *)params)->beta);
	return (0);
}