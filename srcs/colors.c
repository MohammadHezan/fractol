/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaizan <mhaizan@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 20:53:00 by mhaizan           #+#    #+#             */
/*   Updated: 2026/01/20 15:13:49 by mhaizan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	scheme_rainbow(int i, int max_iter)
{
	double	r;
	double	g;
	double	b;
	double	frequency;

	(void)max_iter;
	frequency = 0.1;
	r = sin(frequency * i + 0) * 127 + 128;
	g = sin(frequency * i + 2) * 127 + 128;
	b = sin(frequency * i + 4) * 127 + 128;
	return (((int)r << 16) | ((int)g << 8) | (int)b);
}

int	scheme_fire(int i, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)i / max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

int	scheme_ice(int i, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)i / max_iter;
	r = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(9 * (1 - t) * t * t * t * 255);
	return ((r << 16) | (g << 8) | b);
}

int	scheme_purple(int i, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)i / max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	b = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	return ((r << 16) | (g << 8) | b);
}

int	scheme_green(int i, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)i / max_iter;
	r = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	g = (int)(9 * (1 - t) * t * t * t * 255);
	b = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	return ((r << 16) | (g << 8) | b);
}
