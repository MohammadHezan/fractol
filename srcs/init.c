/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaizan <mhaizan@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:41:05 by mhaizan           #+#    #+#             */
/*   Updated: 2026/01/11 20:50:54 by mhaizan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    error(void)
{
    write(2, "Memory allocation failed\n", 26);
    exit(EXIT_FAILURE);
}
void    image_data(t_fractol *fractol)
{
    fractol->img.pixels_ptr = mlx_get_data_addr(fractol->img.img_ptr,
            &fractol->img.bpp, &fractol->img.line_len, &fractol->img.endian);
    fractol->max_iter = 100;
    fractol->zoom = 1.0;
    fractol->offset_x = 0.0;
    fractol->offset_y = 0.0;
}

void	init_fractol(t_fractol *fractol)
{
    fractol->mlx = mlx_init();
    if (NULL == fractol->mlx)
		error();
    fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "Fractol");
    if (NULL == fractol->win)
	{
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
		error();
	}
    fractol->img.img_ptr = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
    if (NULL == fractol->img.img_ptr)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
		error();
	}
    image_data(fractol);
    fractol->c.real = -0.7;
    fractol->c.imag = 0.27015;
    fractol->escape = 4;
}
void    events_init(t_fractol *fractol)
{
    mlx_key_hook(fractol->win, handle_keypress, fractol);
    mlx_mouse_hook(fractol->win, handle_mouse, fractol);
}
