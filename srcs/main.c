/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaizan <mhaizan@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:32:09 by mhaizan           #+#    #+#             */
/*   Updated: 2026/01/11 20:37:28 by mhaizan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;


	if ((2 == argc && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (4 == argc && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractol.name = argv[1];
		if (!ft_strncmp(fractol.name, "julia", 5))
		{
			fractol.offset_x = atoi(argv[2]);
			fractol.offset_y = atoi(argv[3]);
		}
		init_fractol(&fractol);
		//fractal_render(&fractol);
		//mlx_loop(fractol.mlx);
	}
}