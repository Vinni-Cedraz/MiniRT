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

double	ft_atof(const char *str)
{
	int		sign;
	double	result;
	double	power;
	int		i;

	sign = 1;
	result = 0;
	power = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (ft_isdigit(str[i]))
		result = result * 10 + str[i++] - '0';
	if (str[i] == '.')
		i++;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i++] - '0';
		power *= 10;
	}
	return (sign * result / power);
}
