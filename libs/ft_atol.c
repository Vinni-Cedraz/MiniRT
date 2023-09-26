/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:59:33 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/07/25 20:00:10 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	is_valid_number(const char *str);
static long	convert_recursively(char *a, unsigned long toi);

long	ft_atol(char *str)
{
	long	sign;

	sign = 1;
	while (is_whitespace(*str))
		str++;
	if (!is_valid_number(str))
		return (0);
	if (*str == '-')
		sign = -1;
	if (sign == -1 || *str == '+')
		str++;
	return (convert_recursively(str, 0) * sign);
}

static long	is_valid_number(const char *str)
{
	while (*str && !is_whitespace(*str))
	{
		if ((*str < '0' || *str > '9') && *str != '-' && *str != '+')
			return (0);
		str++;
	}
	return (1);
}

static long	convert_recursively(char *a, unsigned long toi)
{
	long	single_digit;

	if (!*a || is_whitespace(*a))
		return (toi);
	single_digit = *a - '0';
	toi = toi * 10 + single_digit;
	return (convert_recursively(a + 1, toi));
}
