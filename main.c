/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:16:12 by vlaine            #+#    #+#             */
/*   Updated: 2022/03/16 15:04:17 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h" //remove

/*
static void draw_image(t_fdf *head)
{
    t_fdf *elem;
    void *mlx_ptr;
    void *win_ptr;
    int x;
    int y;
    int index; // replace with x / 5 or smt

    elem = head;
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "test");
    y = 0;
    while (elem && elem->line)
    {
        x = 0;
        index = 0;
        while (elem->line[index])
        {
            if (ft_isalnum(elem->line[index]))
            mlx_pixel_put(mlx_ptr, win_ptr, x + 150, y + 150, 0xffffff);
            x += 5;
            index++;
        }
        y += 5;
        elem = elem->next;
    }
    mlx_loop(mlx_ptr);
}
static void draw_image(t_fdf *head)
{
    t_fdf *elem;
    void *mlx_ptr;
    void *win_ptr;
    int x;
    int y;
    int index; // replace with x / 5 or smt
    double angle = 0;

    elem = head;
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "test");
    mlx_pixel_put(mlx_ptr, win_ptr, 113, 86, 0xffffff);
    mlx_pixel_put(mlx_ptr, win_ptr, 451, 327, 0xffffff);
    x = 113;
    y = 86;

    while (x < 450)
    {
        angle = atan(y/x);
        if (angle > atan(1))
        {
            x++;
        }
        else if(angle < atan(1))
        y++;
        else if (angle == atan(1))
        {
            y++;
            x++;
        }
        mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xffffff);
    }
    printf("tan is %f\n\n", atan(5/5));
    mlx_loop(mlx_ptr);
}
static void draw_image(t_fdf *head)
{
    t_fdf *elem;
    void *mlx_ptr;
    void *win_ptr;
    int x;
    int y;
    int index; // replace with x / 5 or smt
    double angle = 0;
    int endx;
    int startx;
    double temp; 
    double answer;

    elem = head;
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "test");
    mlx_pixel_put(mlx_ptr, win_ptr, 113, 86, 0xffffff);
    mlx_pixel_put(mlx_ptr, win_ptr, 451, 327, 0xffffff);
    x = 113;
    y = 86;

    answer = 338.0/241.0;
    printf("answer is %f\n\n", answer);
    while (x < 450)
    {
        temp = answer;
        if (temp > 1.0)
        {
            while (temp > 0.0)
            {
                x++;
                mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xffffff);
                temp -= 1.0;
            }
         //   x++;
          //      mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xffffff);
        }
        if (temp + 1 < 1.0 && temp + 1 > 0.0)
        {
            y++;
            mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xffffff);
        }
        x++;
        mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xffffff);
    }
    printf("tan is %f\n\n", atan(5/5));
    //mlx_key_hook(win_ptr, exit_key, (void *))
    mlx_loop(mlx_ptr);
}

static void draw_image(int x, int y, int x1, int y1, void *mlx_ptr, void *win_ptr)
{
    int dx, dy, p, swap;

    swap = -1;
    dx = x1 - x;
    dy = y1 - y;

    p = 2 * dy - dx;
    if (x == x1)
    {
        while (y < y1)
        {
            mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xffffff);
            y++;
        }
    }
    else
    {
        if (dx < dy)
        {
            swap = dx;
            dx = dy;
            dy = swap;
            swap = x;
            x = y;
            y = swap;
            swap = x1;
            x1 = y1;
            y1 = swap;
        }
        while (x < x1 )
        {
            if (p >= 0)
            {
                if (swap != -1)
                    mlx_pixel_put(mlx_ptr, win_ptr, y, x, 0xffffff);
                else
                    mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xffffff);
                y++;
                p = p + 2 * dy - 2 * dx;
            }
            else
            {
                if (swap != -1)
                    mlx_pixel_put(mlx_ptr, win_ptr, y, x, 0xffffff);
                else
                    mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xffffff);
                p = p + 2 * dy;
            }
            x = x + 1;
            if (x == x1)
            {
                printf("\n\nx is %d\n y is %d", x, y);
            }
        }
    }
}

while (coord[y])
    {
        x = 0;
        while(coord[y][x])
        {
            //mlx_pixel_put(mlx_ptr, win_ptr, coord[y][x][0] * x_win/20 + 50, coord[y][x][1] * y_win/20 + 50, 0xffffff);
            if (x > 0)
            {
                draw_image(coord[y][x - 1][0] * x_win/20 + 50 - coord[y][x - 1][2], coord[y][x - 1][1] * y_win/20 + 50 - coord[y][x - 1][2], coord[y][x][0] * x_win/20 + 50 - coord[y][x][2], coord[y][x][1] * y_win/20 + 50 - coord[y][x][2], mlx_ptr, win_ptr);
            }
            if (y > 0)
            {
                draw_image(coord[y - 1][x][0] * x_win/20 + 50 - coord[y - 1][x][2], coord[y - 1][x][1] * y_win/20 + 50 - coord[y - 1][x][2], coord[y][x][0] * x_win/20 + 50 - coord[y][x][2], coord[y][x][1] * y_win/20 + 50 - coord[y][x][2], mlx_ptr, win_ptr);
            }
            x++;
        }
        y++;
    }
	
*/
static t_fdf    *new_fdf_lst()
{
	t_fdf	*new;

	new = malloc(sizeof(t_fdf));
	if (new == NULL)
	{
		// free_list(head); 
        // should free the whole list;
		exit (3);
	}
	new->next = NULL;
	return (new);
}

static int open_fd(char *file)
{
    int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("error");
		exit (0);
	}
    return (fd);
}

static int gnl_copy_lines(t_fdf *head, int fd)
{
    t_fdf   *elem;
    int     gnl;
    int     index;

    gnl = 1;
    elem = head;
    index = 0;
    while (gnl > 0)
    {
        gnl = get_next_line(fd, &elem->line);
        if (gnl < 1)
			elem->line = NULL;
        if (gnl > 0)
        {
            index++;
            elem->next = new_fdf_lst();
            elem = elem->next;
        }
    }
    elem->next = NULL;
    return (index);
}

static void ft_box(t_params *params)
{
    int x, y, x0, y0, x1, y1;

    x = 1;
    x1 = 150;
    y = 500;
    y1 = 700;

    x0 = x;
    y0 = y;
    while (x < x1)
    {
        mlx_pixel_put(params->mlx_ptr, params->win_ptr, x, y0, 0xffffff);
        mlx_pixel_put(params->mlx_ptr, params->win_ptr, x, y1, 0xffffff);
        mlx_pixel_put(params->mlx_ptr, params->win_ptr, x, 300, 0xffffff);
        x++;
    }
    x = x0;
    y0 = 300;
    while (y < y1)
    {
        mlx_pixel_put(params->mlx_ptr, params->win_ptr, x, y, 0xffffff);
        mlx_pixel_put(params->mlx_ptr, params->win_ptr, x1, y, 0xffffff);
        mlx_pixel_put(params->mlx_ptr, params->win_ptr, x1, y0, 0xffffff);
        mlx_pixel_put(params->mlx_ptr, params->win_ptr, x, y0, 0xffffff);
        y++;
        y0++;
    }
}

int draw_extra_line(void *params)
{
	//params->alpha = 70;
	//params->beta = 70;
	pixel_placement((t_params *)params);
	return (0);
}

int exit_window(int key, void *params)
{
	((t_params *)params)->alpha += 5;
	//exit(0);
	//mlx_expose_hook(params->win_ptr, draw_extra_line, params);
	return (0);
}

int main(int argc, char **argv)
{
    int			fd;
    int			x;
    int			y;
    int			index;
    t_fdf		*elem;
    t_fdf		*head;
	t_params	*params;

	params = malloc(sizeof(t_params));
	params->alpha = 35;
	params->beta = 45;
    if (argc != 2)
    {
        ft_putendl("usage ./fdf matrix_file");
        return (0);
    }
    fd = open_fd(argv[1]);
    elem = new_fdf_lst();
    head = elem;
    index = gnl_copy_lines(elem, fd); // have this return how many lines we need to malloc
    printf("\nindex is %d", index);
    params->coord = (int ***)malloc(sizeof(int **) * index + 1);
    params->coord[index] = NULL;
    index = 0;
    y = 0;
    while (elem && elem->line)
    {
        ft_putendl(elem->line);
        index = 0;
        x = 0;
        while (elem->line[index])
        {
            if (index > 0)
                if ((elem->line[index - 1] != ' ' && elem->line[index] == ' ') || elem->line[index + 1] == '\0')
                    x++;
            index++;
        }
        //printf("\nx is now %d\n", x);
        params->coord[y] = (int **)malloc(sizeof(int *) * x + 1);
        params->coord[y][x] = NULL;
        y++;
        elem = elem->next;
    }
    elem = head;
    y = 0;
    while (elem && elem->line)
    {
        index = 0;
        x = 0;
        while (elem->line[index])
        {
           if (index > 0)
            {
                if ((elem->line[index - 1] != ' ' && elem->line[index] == ' ') || elem->line[index + 1] == '\0')
                {
                    params->coord[y][x] = (int *)malloc(sizeof(int) * 3);
                    params->coord[y][x][0] = x;
                    params->coord[y][x][1] = y;
                    params->coord[y][x][2] = 1;
                    if (index > 1)
                    {
                        if (elem->line[index - 2] == '1')
						{
							params->coord[y][x][2] = 50;
						}
                    }
                    x++;
                }
            }
            if (index > 0)
            {
                //printf("\nx is %d\ny is %d\nz is %d\n//////", coord[y][x][0], coord[y][x][1], coord[y][x][2]);
                printf("\nz is %d\n//////", params->coord[y][x - 1][2]);
            }
            index++;
        }
        y++;
        elem = elem->next;
    }
    elem = head;
    int x_win;
    int y_win;

    x_win = 1001;
    y_win = 1001;
    params->mlx_ptr = mlx_init();
    params->win_ptr = mlx_new_window(params->mlx_ptr, x_win, y_win, "test");
	//pixel_placement(params);
	//pixel_placement(params);
	mlx_loop_hook(params->win_ptr, draw_extra_line, params);
	mlx_key_hook(params->win_ptr, exit_window, params);
    mlx_loop(params->mlx_ptr);
}

/*
    //ft_box(mlx_ptr, win_ptr);
    //draw_image(50, 500, 500, 400, mlx_ptr, win_ptr);
    //draw_image(1, 500, 150, 500, mlx_ptr, win_ptr);
    //draw_image(1, 500, 150, 300, mlx_ptr, win_ptr);
    //draw_image(1, 500, 150, 600, mlx_ptr, win_ptr);
    //draw_image(150, 500, 150, 700, mlx_ptr, win_ptr);
    //draw_image(1, 500, 150, 700, mlx_ptr, win_ptr);
    //raw_image(1, 500, 1, 700, mlx_ptr, win_ptr);
    //draw_image(1, 700, 150, 700, mlx_ptr, win_ptr);
	//draw_image(100, 400, 150, 900, mlx_ptr, win_ptr);
    
	
double xc, yc, lx, ly;
    while (coord[y])
    {
        x = 0;
        while(coord[y][x])
        {
			xc = coord[y][x][0] - coord[y][x][1];
			yc = coord[y][x][0] + coord[y][x][1];
			xc = xc * 30;
			yc = yc * 30;
            //mlx_pixel_put(mlx_ptr, win_ptr, coord[y][x][0] * x_win/20 + 50, coord[y][x][1] * y_win/20 + 50, 0xffffff);
            if (x > 0)
            {
				lx = coord[y][x - 1][0] - coord[y][x - 1][1];
				ly = coord[y][x - 1][0] + coord[y][x - 1][1];
				lx = lx * 30;
				ly = ly * 30;
                draw_image(lx + 500, ly + 50 - coord[y][x - 1][2], xc + 500, yc + 50 - coord[y][x][2], params);
            }
            if (y > 0)
            {
				lx = coord[y - 1][x][0] - coord[y - 1][x][1];
				ly = coord[y - 1][x][0] + coord[y - 1][x][1];
				lx = lx * 30;
				ly = ly * 30;
                draw_image(lx + 500, ly + 50 - coord[y - 1][x][2], xc + 500, yc + 50 - coord[y][x][2], params);
            }
            x++;
        }
        y++;
    }
	mlx_key_hook(params->win_ptr, exit_window, (void *)BUTTON_ESC);
	mlx_loop_hook(params->win_ptr, draw_extra_line(params), (void *)7);
    mlx_loop(params->mlx_ptr);
  while (coord[y])
    {
        x = 0;
        while(coord[y][x])
        {
            //mlx_pixel_put(mlx_ptr, win_ptr, coord[y][x][0] * x_win/20 + 50, coord[y][x][1] * y_win/20 + 50, 0xffffff);
            if (x > 0)
            {
                draw_image(coord[y][x - 1][0] * x_win/20 + 50, coord[y][x - 1][1] * y_win/20 + 50, coord[y][x][0] * x_win/20 + 50, coord[y][x][1] * y_win/20 + 50, mlx_ptr, win_ptr);
            }
            if (y > 0)
            {
                draw_image(coord[y - 1][x][0] * x_win/20 + 50, coord[y - 1][x][1] * y_win/20 + 50, coord[y][x][0] * x_win/20 + 50, coord[y][x][1] * y_win/20 + 50, mlx_ptr, win_ptr);
            }
            x++;
        }
        y++;
    }
	*/