/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaizan <mhaizan@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:32:09 by mhaizan           #+#    #+#             */
/*   Updated: 2026/01/23 18:28:16 by mhaizan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_valid_float(const char *str)
{
	int	i;
	int	has_dot;

	i = 0;
	has_dot = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '.' || !str[i])
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
	{
		has_dot = 1;
		i++;
	}
	if (has_dot && !(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (has_dot && !str[i]);
}

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

static void	run_fractol(t_fractol *fractol)
{
	init_fractol(fractol);
	events_init(fractol);
	fractol_render(fractol);
	mlx_loop(fractol->mlx);
	close_window(fractol, NULL, 0);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (2 == argc && (!ft_strncmp(argv[1], "mandelbrot\0", 11)
			|| !ft_strncmp(argv[1], "burning_ship\0", 13)))
	{
		fractol.name = argv[1];
		run_fractol(&fractol);
	}
	else if (4 == argc && !ft_strncmp(argv[1], "julia\0", 6)
		&& is_valid_float(argv[2]) && is_valid_float(argv[3]))
	{
		fractol.name = argv[1];
		init_julia_params(&fractol, argv);
		run_fractol(&fractol);
	}
	else
	{
		fractol.mlx = NULL;
		fractol.win = NULL;
		fractol.img.img_ptr = NULL;
		close_window(NULL, "Usage: mandelbrot | julia <r> <i> | ship", 1);
	}
	return (0);
}
