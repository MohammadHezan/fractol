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

void	imag_pixel_put(int real, int imag, t_image *img, int color)
{
	int	offset;

	offset = (imag * img->line_len) + (real * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}
void	handle_pixel(int real, int imag, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;     
	z.real = (map(real, -2, +2, 0, WIDTH) * fractol->zoom) + fractol->offset_x;
	z.imag = (map(imag, +2, -2, 0, HEIGHT) * fractol->zoom) + fractol->offset_y;
	mandel_vs_julia(&z, &c, fractol);
	while (i < fractol->max_iter)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.real * z.real) + (z.imag * z.imag) > fractol->escape)
		{
			color = map(i, BLACK, WHITE, 0, fractol->max_iter);
			mimag_pirealel_put(real, imag, &fractol->img, color);
			return ;
		}
		++i;	
	}
	imag_pixel_put(real, imag, &fractol->img, WHITE);
}
void	fractol_render(t_fractol *fractol)
{
	int	real;
	int	imag;

	imag = -1;
	while (++imag < HEIGHT)
	{
		real = -1;
		while (++real < WIDTH)
			handle_pixel(real, imag, fractol);
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img_ptr, 0, 0);	
}