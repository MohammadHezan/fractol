/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaizan <mhaizan@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:32:09 by mhaizan           #+#    #+#             */
/*   Updated: 2026/01/20 16:24:44 by mhaizan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_valid_float(const char *str)
{
	int	has_digit;
	int	has_dot;

	has_digit = 0;
	has_dot = 0;
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '.')
		return (0);
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			has_digit = 1;
		else if (*str == '.' && !has_dot)
			has_dot = 1;
		else
			return (0);
		str++;
	}
	return (has_digit);
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
		close_window(&fractol, "Usage: mandelbrot | julia <r> <i> | ship", 1);
	return (0);
}
