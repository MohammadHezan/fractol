/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaizan <mhaizan@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:59:35 by mhaizan           #+#    #+#             */
/*   Updated: 2026/01/11 20:27:32 by mhaizan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int handle_keypress(int keycode, t_fractol *fractol)
{
    if (keycode == XK_Escape)
        close_window(fractol);
    if (keycode == XK_Up)
        fractol->offset_y -= (0.5 *fractol->zoom);
    else if (keycode == XK_Down)
        fractol->offset_y += (0.5 *fractol->zoom);
    else if (keycode == XK_Left)
        fractol->offset_x -= (0.5 *fractol->zoom);
    else if (keycode == XK_Right)
        fractol->offset_x += (0.5 *fractol->zoom);
    else if (keycode == XK_plus || keycode == XK_equal)
        fractol->max_iter += 10;
    else if (keycode == XK_minus || keycode == XK_underscore)
        fractol->zoom -= 10;
    fractal_render(fractol);
    return (0);
}
int handle_mouse(int button, int x, int y, t_fractol *fractol)
{
    if (button == Button5)
		fractol->zoom *= 0.95;
	else if (button == Button4)
		fractol->zoom *= 1.05;
	fractal_render(fractol);
	return 0;
}
int close_window(t_fractol *fractol)
{
    mlx_destroy_image(fractol->mlx, fractol->img.img_ptr);
    mlx_destroy_window(fractol->mlx, fractol->win);
    mlx_destroy_display(fractol->mlx);
    free(fractol->mlx);
    exit(EXIT_SUCCESS);
    return (0);
}
