/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaizan <mhaizan@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:59:35 by mhaizan           #+#    #+#             */
/*   Updated: 2026/01/16 20:59:26 by mhaizan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	morph_julia(t_fractol *fractol, int direction)
{
	const double	step = 0.02;

	if (!ft_strncmp(fractol->name, "julia", 5))
	{
		if (direction == 1)
			fractol->julia_real += step;
		else if (direction == 2)
			fractol->julia_real -= step;
		else if (direction == 3)
			fractol->julia_imag += step;
		else if (direction == 4)
			fractol->julia_imag -= step;
	}
}

static void	update_julia(int keycode, t_fractol *fractol)
{
	if (keycode == XK_J || keycode == XK_L)
	{
		if (keycode == XK_L)
			morph_julia(fractol, 1);
		else
			morph_julia(fractol, 2);
	}
	else
	{
		if (keycode == XK_I)
			morph_julia(fractol, 3);
		else
			morph_julia(fractol, 4);
	}
}

int	handle_keypress(int keycode, t_fractol *fractol)
{
	if (keycode == XK_ESCAPE)
		close_window(fractol);
	else if (keycode == XK_LEFT)
		fractol->offset_x -= (0.5 * fractol->zoom);
	else if (keycode == XK_RIGHT)
		fractol->offset_x += (0.5 * fractol->zoom);
	else if (keycode == XK_UP)
		fractol->offset_y -= (0.5 * fractol->zoom);
	else if (keycode == XK_DOWN)
		fractol->offset_y += (0.5 * fractol->zoom);
	else if (keycode == XK_PLUS || keycode == XK_EQUAL)
		fractol->max_iter += 10;
	else if (keycode == XK_MINUS || keycode == XK_UNDERSCORE)
		fractol->max_iter -= 10;
	else if (keycode == XK_J || keycode == XK_L
		|| keycode == XK_I || keycode == XK_M)
		update_julia(keycode, fractol);
	else if (keycode == XK_C)
		fractol->color_scheme = (fractol->color_scheme + 1) % 5;
	fractol_render(fractol);
	return (0);
}

int	handle_mouse(int mouse_button, int mouse_x, int mouse_y, t_fractol *fractol)
{
	double	zoom_factor;
	double	complex_real;
	double	complex_imag;

	if (mouse_button == BUTTON4)
		zoom_factor = 1.1;
	else if (mouse_button == BUTTON5)
		zoom_factor = 0.9;
	else
		return (0);
	complex_real = (mouse_x - WIDTH / 2.0) * (4.0 / WIDTH * fractol->zoom)
		+ fractol->offset_x;
	complex_imag = (mouse_y - HEIGHT / 2.0) * (4.0 / HEIGHT * fractol->zoom)
		+ fractol->offset_y;
	fractol->zoom *= zoom_factor;
	fractol->offset_x = complex_real
		- (mouse_x - WIDTH / 2.0) * (4.0 / WIDTH * fractol->zoom);
	fractol->offset_y = complex_imag
		- (mouse_y - HEIGHT / 2.0) * (4.0 / HEIGHT * fractol->zoom);
	fractol_render(fractol);
	return (0);
}

int	close_window(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx, fractol->win);
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
	exit(0);
}
