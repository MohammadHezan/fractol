/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaizan <mhaizan@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:32:09 by mhaizan           #+#    #+#             */
/*   Updated: 2026/01/19 20:27:39 by mhaizan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_julia_params(t_fractol *fractol, char **argv)
{
	fractol->julia_real = ft_atof(argv[2]);
	fractol->julia_imag = ft_atof(argv[3]);
	if (fractol->julia_real < -2.0)
		fractol->julia_real = -2.0;
	if (fractol->julia_real > 2.0)
		fractol->julia_real = 2.0;
	if (fractol->julia_imag < -2.0)
		fractol->julia_imag = -2.0;
	if (fractol->julia_imag > 2.0)
		fractol->julia_imag = 2.0;
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if ((2 == argc && !ft_strncmp(argv[1], "mandelbrot\0", 11))
		|| (4 == argc && !ft_strncmp(argv[1], "julia\0", 6)))
	{
		fractol.name = argv[1];
		if (!ft_strncmp(fractol.name, "julia", 5))
			init_julia_params(&fractol, argv);
		init_fractol(&fractol);
		events_init(&fractol);
		fractol_render(&fractol);
		mlx_loop(fractol.mlx);
	}
	else
	{
		if (!write(2, "Usage: ./fractol mandelbrot | julia real imag\n", 47))
			return (1);
		return (1);
	}
	return (0);
}
