/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaizan <mhaizan@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:59:35 by mhaizan           #+#    #+#             */
/*   Updated: 2026/01/14 00:30:16 by mhaizan          ###   ########.fr       */
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
        fractol->max_iter -= 10;
    fractol_render(fractol);
    return (0);
}

int handle_mouse(int mouse_button, int mouse_x, int mouse_y, t_fractol *fractol)
{
	double	zoom_factor;
	double	complex_real;
	double	complex_imag;

	if (mouse_button == Button4)
		zoom_factor = 1.2;
	else if (mouse_button == Button5)
		zoom_factor = 0.8;
	else
		return (0);

	complex_real = (mouse_x - WIDTH / 2.0)
		/ (0.5 * fractol->zoom * WIDTH) + fractol->offset_x;
	complex_imag = (mouse_y - HEIGHT / 2.0)
		/ (0.5 * fractol->zoom * HEIGHT) + fractol->offset_y;

	fractol->zoom *= zoom_factor;
	fractol->offset_x = complex_real
		- (mouse_x - WIDTH / 2.0)
		/ (0.5 * fractol->zoom * WIDTH);
	fractol->offset_y = complex_imag
		- (mouse_y - HEIGHT / 2.0)
		/ (0.5 * fractol->zoom * HEIGHT);
	fractol_render(fractol);
	return (0);
}

int close_window(t_fractol *fractol)
{
    mlx_destroy_image(fractol->mlx, fractol->img.img_ptr);
    mlx_destroy_window(fractol->mlx, fractol->win);
    mlx_destroy_display(fractol->mlx);
    free(fractol->mlx);
    exit(0);
}
