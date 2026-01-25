/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaizan <mhaizan@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:59:35 by mhaizan           #+#    #+#             */
/*   Updated: 2026/01/23 18:14:22 by mhaizan          ###   ########.fr       */
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
		mlx_loop_end(fractol->mlx);
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

int	handle_mouse(int button, int x, int y, t_fractol *fractol)
{
	double	zoom_factor;

	if (button == BUTTON5)
		zoom_factor = 1.1;
	else if (button == BUTTON4)
		zoom_factor = 0.9;
	else
		return (0);
	apply_zoom(x, y, fractol, zoom_factor);
	fractol_render(fractol);
	return (0);
}

int	close_window(t_fractol *fractol, char *msg, int code)
{
	if (fractol)
	{
		if (fractol->img.img_ptr)
			mlx_destroy_image(fractol->mlx, fractol->img.img_ptr);
		if (fractol->win)
			mlx_destroy_window(fractol->mlx, fractol->win);
		if (fractol->mlx)
		{
			mlx_loop_end(fractol->mlx);
			free(fractol->mlx);
		}
	}
	if (msg)
		write(2, msg, ft_strlen(msg));
	exit(code);
}
