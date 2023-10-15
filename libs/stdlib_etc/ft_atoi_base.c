/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 09:39:06 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/11 12:40:26 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convert_recursively(const char *a, unsigned int toi, int base);
static int	local_is_whitespace(const char c);
static int	digit_value(char c);
static int	is_digit(const char c);

int	ft_atoi_base(const char *str, int base)
{
	int	sign;

	while (local_is_whitespace(*str))
		str++;
	sign = 1;
	if (*str == '-')
		sign *= -1;
	if (sign == -1 || *str == '+')
		str++;
	return (convert_recursively(str, 0, base) * sign);
}

static int	local_is_whitespace(const char c)
{
	return (c == ' ' || ('\t' <= c && c <= '\r'));
}

static int	is_digit(const char c)
{
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A'
			&& c <= 'F'));
}

static int	convert_recursively(const char *a, unsigned int toi, int base)
{
	int	single_digit;

	if (!*a || local_is_whitespace(*a) || !is_digit(*a))
		return (toi);
	single_digit = digit_value(*a);
	if (single_digit >= base)
		return (0);
	toi = toi * base + single_digit;
	return (convert_recursively(a + 1, toi, base));
}

static int	digit_value(char c)
{
	int	index;

	index = -1;
	while ("0123456789abcdef"[++index])
		if (c == "0123456789abcdef"[index])
			return (index);
	index = -1;
	while ("0123456789ABCDEF"[++index])
		if (c == "0123456789ABCDEF"[index])
			break ;
	return (index);
}

// #include <assert.h>
// #include <stdio.h>
// #include <stdlib.h>
//
// int	main(void)
// {
// 	// Base 4 tests
// 	assert(ft_atoi_base("3", 4) == strtol("3", NULL, 4));
// 	assert(ft_atoi_base("12", 4) == strtol("12", NULL, 4));
// 	assert(ft_atoi_base("30", 4) == strtol("30", NULL, 4));
// 	assert(ft_atoi_base("-3", 4) == strtol("-3", NULL, 4));
// 	assert(ft_atoi_base("-12", 4) == strtol("-12", NULL, 4));
// 	assert(ft_atoi_base("  30", 4) == strtol("  30", NULL, 4));
// 	assert(ft_atoi_base("33", 4) == strtol("33", NULL, 4));
// 	assert(ft_atoi_base("433", 4) == strtol("433", NULL, 4));
// 	// Base 5 tests
// 	assert(ft_atoi_base("0", 5) == strtol("0", NULL, 5));
// 	assert(ft_atoi_base("4", 5) == strtol("4", NULL, 5));
// 	assert(ft_atoi_base("123", 5) == strtol("123", NULL, 5));
// 	assert(ft_atoi_base("4321", 5) == strtol("4321", NULL, 5));
// 	assert(ft_atoi_base("-4", 5) == strtol("-4", NULL, 5));
// 	assert(ft_atoi_base("-123", 5) == strtol("-123", NULL, 5));
// 	assert(ft_atoi_base("  4321", 5) == strtol("  4321", NULL, 5));
// 	assert(ft_atoi_base("543", 5) == strtol("543", NULL, 5));
// 	// Base 8 tests
// 	assert(ft_atoi_base("0", 8) == strtol("0", NULL, 8));
// 	assert(ft_atoi_base("7", 8) == strtol("7", NULL, 8));
// 	assert(ft_atoi_base("12", 8) == strtol("12", NULL, 8));
// 	assert(ft_atoi_base("777", 8) == strtol("777", NULL, 8));
// 	assert(ft_atoi_base("-7", 8) == strtol("-7", NULL, 8));
// 	assert(ft_atoi_base("-12", 8) == strtol("-12", NULL, 8));
// 	assert(ft_atoi_base("  777", 8) == strtol("  777", NULL, 8));
// 	assert(ft_atoi_base("88", 8) == strtol("88", NULL, 8));
// 	// Base 16 tests
// 	assert(ft_atoi_base("0", 16) == strtol("0", NULL, 16));
// 	assert(ft_atoi_base("a", 16) == strtol("a", NULL, 16));
// 	assert(ft_atoi_base("12", 16) == strtol("12", NULL, 16));
// 	assert(ft_atoi_base("ff", 16) == strtol("ff", NULL, 16));
// 	assert(ft_atoi_base("-f", 16) == strtol("-f", NULL, 16));
// 	assert(ft_atoi_base("-12", 16) == strtol("-12", NULL, 16));
// 	assert(ft_atoi_base("  ff", 16) == strtol("  ff", NULL, 16));
// 	assert(ft_atoi_base("gg", 16) == strtol("gg", NULL, 16));
// 	// Base 10 tests
// 	assert(ft_atoi_base("0", 10) == strtol("0", NULL, 10));
// 	assert(ft_atoi_base("1", 10) == strtol("1", NULL, 10));
// 	assert(ft_atoi_base("12", 10) == strtol("12", NULL, 10));
// 	assert(ft_atoi_base("123", 10) == strtol("123", NULL, 10));
// 	assert(ft_atoi_base("-1", 10) == strtol("-1", NULL, 10));
// 	assert(ft_atoi_base("-12", 10) == strtol("-12", NULL, 10));
// 	assert(ft_atoi_base("  123", 10) == strtol("  123", NULL, 10));
// 	printf("\033[1;92m""All tests passed.\n""\033[1;39m");
// }
