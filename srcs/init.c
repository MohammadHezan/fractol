/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaizan <mhaizan@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:00:00 by mhaizan           #+#    #+#             */
/*   Updated: 2026/01/20 16:28:43 by mhaizan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	image_data(t_fractol *fractol)
{
	fractol->img.img_ptr = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->img.img_ptr)
		close_window(fractol, "Error", 3);
	fractol->img.pixels_ptr = mlx_get_data_addr(fractol->img.img_ptr,
			&fractol->img.bpp, &fractol->img.line_len, &fractol->img.endian);
	if (!fractol->img.pixels_ptr)
		close_window(fractol, "Error", 4);
}

void	init_fractol(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		close_window(fractol, "Error", 1);
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, fractol->name);
	if (!fractol->win)
		close_window(fractol, "Error", 2);
	image_data(fractol);
	fractol->zoom = 1.0;
	fractol->offset_x = 0.0;
	fractol->offset_y = 0.0;
	fractol->max_iter = 100;
	fractol->escape = 4;
	fractol->color_scheme = 0;
}

void	events_init(t_fractol *fractol)
{
	mlx_hook(fractol->win, 2, 1L << 0, handle_keypress, fractol);
	mlx_hook(fractol->win, 4, 1L << 2, handle_mouse, fractol);
	mlx_hook(fractol->win, 17, 0, &mlx_loop_end, fractol->mlx);
}

int	get_color(int i, int max_iter, int color_scheme)
{
	if (color_scheme == 0)
		return (scheme_rainbow(i, max_iter));
	else if (color_scheme == 1)
		return (scheme_fire(i, max_iter));
	else if (color_scheme == 2)
		return (scheme_ice(i, max_iter));
	else if (color_scheme == 3)
		return (scheme_purple(i, max_iter));
	else
		return (scheme_green(i, max_iter));
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
