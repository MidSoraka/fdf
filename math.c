/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:29:21 by vlaine            #+#    #+#             */
/*   Updated: 2022/03/16 14:52:11 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	*rotation_matrices(int *vector3, t_params *params)
 {
	int temp_vector3[3];
	int	*result_vector3;
	double	alpha;
	double	beta;

	result_vector3 = malloc(sizeof(int) * 4);
	alpha = 0.615472907;
	beta = 0.785398163;
	alpha = (params->alpha * M_PI) / 180;
	beta = (params->beta * M_PI) / 180;
	//alpha = 0.35264;
	//beta = 0.45;
	temp_vector3[0] = vector3[0];
	temp_vector3[1] = vector3[1];
	temp_vector3[2] = vector3[2];

	result_vector3[0] = (temp_vector3[0] * 1) + (temp_vector3[1] * 0) + (temp_vector3[2] * 0);
	result_vector3[1] = (temp_vector3[0] * 0) + (temp_vector3[1] * cos(alpha)) + (temp_vector3[2] * sin(alpha));
	result_vector3[2] = (temp_vector3[0] * 0) + (temp_vector3[1] * -sin(alpha)) + (temp_vector3[2] * cos(alpha));

	temp_vector3[0] = result_vector3[0];
	temp_vector3[1] = result_vector3[1];
	temp_vector3[2] = result_vector3[2];

	result_vector3[0] = (temp_vector3[0] * cos(beta)) + (temp_vector3[1] * 0) + (temp_vector3[2] * -sin(beta));
	result_vector3[1] = (temp_vector3[0] * 0) + (temp_vector3[1] * 1) + (temp_vector3[2] * 0);
	result_vector3[2] = (temp_vector3[0] * sin(beta)) + (temp_vector3[1] * 0) + (temp_vector3[2] * cos(beta));
	return (result_vector3);
}
