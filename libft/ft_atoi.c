/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaizan <mhaizan@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:45:14 by mhaizan           #+#    #+#             */
/*   Updated: 2026/01/11 20:42:35 by mhaizan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	integer;
	double	fractional;
	double	pow;

	sign = 1;
	integer = 0;
	fractional = 0;
	pow = 1.0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -sign;
	while (*str != '.' && *str)
		integer = (integer * 10) + (*str++ - 48);
	if ('.' == *str)
		++str;
	while (*str)
	{
		pow /= 10;
		fractional = fractional + (*str++ - 48) * pow;
	}
	return ((integer + fractional) * sign);
}
