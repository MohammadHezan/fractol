/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaizan <mhaizan@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 20:43:10 by mhaizan           #+#    #+#             */
/*   Updated: 2026/01/20 16:19:33 by mhaizan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	imag_pixel_put(int real, int imag, t_image *img, int color)
{
	int	offset;

	offset = (imag * img->line_len) + (real * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	init_coords(int x, int y, t_fractol *f, double coords[4])
{
	double	scale;
	double	px;
	double	py;

	if (WIDTH < HEIGHT)
		scale = 4.0 / WIDTH;
	else
		scale = 4.0 / HEIGHT;
	px = (x - WIDTH / 2.0) * (scale * f->zoom) + f->offset_x;
	py = (y - HEIGHT / 2.0) * (scale * f->zoom) + f->offset_y;
	if (!ft_strncmp(f->name, "julia", 5))
	{
		coords[0] = px;
		coords[1] = py;
		coords[2] = f->julia_real;
		coords[3] = f->julia_imag;
	}
	else
	{
		coords[0] = 0;
		coords[1] = 0;
		coords[2] = px;
		coords[3] = py;
	}
}

static void	iterate(double *coords, t_fractol *fractol)
{
	double	tmp;
	double	abs_zr;
	double	abs_zi;

	if (!ft_strncmp(fractol->name, "burning_ship", 12))
	{
		abs_zr = ft_fabs(coords[0]);
		abs_zi = ft_fabs(coords[1]);
		tmp = abs_zr * abs_zr - abs_zi * abs_zi + coords[2];
		coords[1] = 2 * abs_zr * abs_zi + coords[3];
		coords[0] = tmp;
	}
	else
	{
		tmp = coords[0] * coords[0] - coords[1] * coords[1] + coords[2];
		coords[1] = 2 * coords[0] * coords[1] + coords[3];
		coords[0] = tmp;
	}
}

void	handle_pixel(int real, int imag, t_fractol *fractol)
{
	double	coords[4];
	int		i;
	int		color;

	init_coords(real, imag, fractol, coords);
	i = 0;
	while (i < fractol->max_iter)
	{
		if ((coords[0] * coords[0] + coords[1] * coords[1]) > fractol->escape)
		{
			color = get_color(i, fractol->max_iter, fractol->color_scheme);
			imag_pixel_put(real, imag, &fractol->img, color);
			return ;
		}
		iterate(coords, fractol);
		i++;
	}
	imag_pixel_put(real, imag, &fractol->img, BLACK);
}

int	fractol_render(t_fractol *fractol)
{
	int	real;
	int	imag;

	imag = 0;
	while (imag < HEIGHT)
	{
		real = 0;
		while (real < WIDTH)
		{
			handle_pixel(real, imag, fractol);
			real++;
		}
		imag++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win,
		fractol->img.img_ptr, 0, 0);
	return (0);
}
