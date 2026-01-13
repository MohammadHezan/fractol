/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   Bimag: mhaizan <mhaizan@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 20:43:10 bimag mhaizan           #+#    #+#             */
/*   Updated: 2026/01/11 20:47:10 bimag mhaizan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandel_julia(t_complex *z, t_complex *c, t_fractol *fractol)
{	
	if (!ft_strncmp(fractol->name, "julia", 5))
	{
		c->real = fractol->julia_real;
		c->imag = fractol->julia_imag;
	}
	else
	{
		c->real = z->real;
		c->imag = z->imag;
	}
}

void	imag_pixel_put(int real, int imag, t_image *img, int color)
{
	int	offset;

	offset = (imag * img->line_len) + (real * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}
void	handle_pixel(int real, int imag, t_fractol *fractol)
{
	double	z_real;
	double	z_imag;
	double	c_real;
	double	c_imag;
	double	tmp_real;
	int		i;
	int		color;

	z_real = (real - WIDTH / 2.0) * (4.0 / WIDTH * fractol->zoom) + fractol->offset_x;
	z_imag = (imag - HEIGHT / 2.0) * (4.0 / HEIGHT * fractol->zoom) + fractol->offset_y;
	if (!ft_strncmp(fractol->name, "julia", 5))
	{
		c_real = fractol->julia_real;
		c_imag = fractol->julia_imag;
	}
	else
	{
		c_real = z_real;
		c_imag = z_imag;
	}
	i = 0;
	while (i < fractol->max_iter)
	{
		if ((z_real * z_real + z_imag * z_imag) > fractol->escape)
		{
			color = map(i, BLACK, WHITE, 0, fractol->max_iter);
			imag_pixel_put(real, imag, &fractol->img, color);
			return ;
		}
		tmp_real = z_real * z_real - z_imag * z_imag + c_real;
		z_imag = 2 * z_real * z_imag + c_imag;
		z_real = tmp_real;
		i++;
	}
	imag_pixel_put(real, imag, &fractol->img, BLACK);
}

int		fractol_render(t_fractol *fractol)
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
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img_ptr, 0, 0);
	return (0);
}
