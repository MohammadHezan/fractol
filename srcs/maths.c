/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaizan <mhaizan@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:56:38 by mhaizan           #+#    #+#             */
/*   Updated: 2026/01/11 16:59:10 by mhaizan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double map(double num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (num - old_min) / (old_max - old_min) + new_min;
}
t_complex   sum(t_complex z1, t_complex z2)
{
    t_complex   result;

    result.real = z1.real + z2.real;
    result.imag = z1.imag + z2.imag;
    return result;
}
t_complex   square(t_complex z)
{
    t_complex   result;
    
    result.real = (z.real * z.real) - (z.imag * z.imag);
    result.imag = 2 * z.real* z.imag;
    return result;
}
