/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yofouzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 22:59:27 by yofouzi           #+#    #+#             */
/*   Updated: 2025/04/14 17:31:32 by yofouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	parse_integer_part(const char **str, int *check)
{
	double	result;

	result = 0.0;
	while (**str >= '0' && **str <= '9')
	{
		*check = 1;
		result = result * 10.0 + (**str - '0');
		(*str)++;
	}
	return (result);
}

static double	parse_fractional_part(const char **str, t_fractal *fractol)
{
	double	result;
	double	divisor;

	result = 0.0;
	divisor = 10.0;
	if (**str == '.')
	{
		(*str)++;
		if (**str == '\0')
			failed(fractol);
		while (**str >= '0' && **str <= '9')
		{
			result += (**str - '0') / divisor;
			divisor *= 10.0;
			(*str)++;
		}
	}
	return (result);
}

double	ft_atof(const char *str, t_fractal *fractol)
{
	double	sign;
	double	result;
	int		check;

	if (*str == '\0')
		failed(fractol);
	sign = 1.0;
	result = 0.0;
	check = 0;
	while (*str <= 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1.0;
		str++;
	}
	result += parse_integer_part(&str, &check);
	result += parse_fractional_part(&str, fractol);
	if (*str || !check)
		failed(fractol);
	return (result * sign);
}
