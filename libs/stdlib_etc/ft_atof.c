/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:17:52 by vcedraz-          #+#    #+#             */
/*   Updated: 2024/04/17 14:20:30 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_process_integer_part(const char *str, int *index, int sign);
static double	ft_process_fractional_part(const char *str, int *index);

double	ft_atof(const char *str)
{
	int		i;
	int		sign;
	double	integer_part;
	double	fractional_part;

	i = 0;
	sign = 1;
	while (is_whitespace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	integer_part = ft_process_integer_part(str, &i, sign);
	if (str[i] == '.')
	{
		i++;
		fractional_part = ft_process_fractional_part(str, &i);
		return (integer_part + fractional_part);
	}
	else
		return (integer_part);
}

int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
		return (1);
	else
		return (0);
}

static double	ft_process_integer_part(const char *str, int *index, int sign)
{
	double	result;

	result = 0.0;
	while (ft_isdigit(str[*index]))
	{
		result = result * 10.0 + (str[*index] - '0');
		(*index)++;
	}
	return (sign * result);
}

static double	ft_process_fractional_part(const char *str, int *index)
{
	double	result;
	double	power;

	result = 0.0;
	power = 10.0;
	while (ft_isdigit(str[*index]))
	{
		result = result * 10.0 + (str[*index] - '0');
		power *= 10.0;
		(*index)++;
	}
	return (result / power);
}
