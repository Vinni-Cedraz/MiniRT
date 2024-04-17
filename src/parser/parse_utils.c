/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tuple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:47:52 by vcedraz-          #+#    #+#             */
/*   Updated: 2024/04/17 14:47:53 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	parse_tuple(char *str, short type)
{
	t_tuple	result;
	int		i;

	i = 0;
	result.x = ft_atof(str);
	while (str[i] && str[i] != ',')
		i++;
	result.y = ft_atof(str + ++i);
	while (str[i] && str[i] != ',')
		i++;
	result.z = ft_atof(str + i + 1);
	result.w = type;
	return (result);
}
