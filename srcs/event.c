/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaizan <mhaizan@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:59:35 by mhaizan           #+#    #+#             */
/*   Updated: 2026/01/19 20:25:15 by mhaizan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	update_julia(int keycode, t_fractol *fractol)
{
	if (!ft_strncmp(fractol->name, "julia", 5))
	{
		if (keycode == XK_L && fractol->julia_real < 2.0)
			fractol->julia_real += 0.02;
		else if (keycode == XK_J && fractol->julia_real > -2.0)
			fractol->julia_real -= 0.02;
		else if (keycode == XK_I && fractol->julia_imag < 2.0)
			fractol->julia_imag += 0.02;
		else if (keycode == XK_M && fractol->julia_imag > -2.0)
			fractol->julia_imag -= 0.02;
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

static void	apply_zoom(int mouse_x, int mouse_y, t_fractol *f, double zf)
{
	double	scale;
	double	cr;
	double	ci;

	if (WIDTH < HEIGHT)
		scale = 4.0 / WIDTH;
	else
		scale = 4.0 / HEIGHT;
	cr = (mouse_x - WIDTH / 2.0) * (scale * f->zoom) + f->offset_x;
	ci = (mouse_y - HEIGHT / 2.0) * (scale * f->zoom) + f->offset_y;
	f->zoom *= zf;
	f->offset_x = cr - (mouse_x - WIDTH / 2.0) * (scale * f->zoom);
	f->offset_y = ci - (mouse_y - HEIGHT / 2.0) * (scale * f->zoom);
}

int	handle_mouse(int mouse_button, int mouse_x, int mouse_y, t_fractol *fractol)
{
	double	zoom_factor;

	if (mouse_button == BUTTON5)
		zoom_factor = 1.1;
	else if (mouse_button == BUTTON4)
		zoom_factor = 0.9;
	else
		return (0);
	apply_zoom(mouse_x, mouse_y, fractol, zoom_factor);
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
