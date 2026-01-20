/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaizan <mhaizan@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:56:38 by mhaizan           #+#    #+#             */
/*   Updated: 2026/01/20 16:28:20 by mhaizan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	sum_c(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.real = z1.real + z2.real;
	result.imag = z1.imag + z2.imag;
	return (result);
}

t_complex	square_c(t_complex z)
{
	t_complex	result;

	result.real = (z.real * z.real) - (z.imag * z.imag);
	result.imag = 2 * z.real * z.imag;
	return (result);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

double	ft_atof(const char *str)
{
	double	res[2];
	int		sign;

	res[0] = 0.0;
	res[1] = 1.0;
	sign = 1;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
		res[0] = res[0] * 10.0 + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			res[1] *= 10.0;
			res[0] += (*str++ - '0') / res[1];
		}
	}
	return (sign * res[0]);
}

double	ft_fabs(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}
