/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:58:37 by vlaine            #+#    #+#             */
/*   Updated: 2022/03/16 14:28:39 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# define BUTTON_ESC 53
# include <math.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"


typedef struct  s_fdf
{
    char            *line;
    int             x;
    int             y;
    struct s_fdf    *next;
}               t_fdf;

typedef struct  s_params
{
	void		*mlx_ptr;
    void		*win_ptr;
	double		alpha;
	double		beta;
	int			***coord;
}               t_params;

int		*rotation_matrices(int *vector3, t_params *params);
void	pixel_placement(t_params *params);

#endif
