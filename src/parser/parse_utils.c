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

static int	validate_tuple(t_tuple tuple, int commas, short type);
static int	validate_color(t_tuple tuple);

t_tuple	parse_tuple(char *str, short type)
{
	t_tuple	result;
	int		i;
	int		commas;

	i = 0;
	commas = 0;
	result.x = ft_atof(str);
	while (str[i] && str[i] != ',')
	{
		i++;
		if (str[i] == ',')
			commas++;
	}
	result.y = ft_atof(str + ++i);
	while (str[i] && str[i] != ',')
	{
		i++;
		if (str[i] == ',')
			commas++;
	}
	result.z = ft_atof(str + i + 1);
	result.w = type;
	if (ERROR == validate_tuple(result, commas, type))
		result.w = ERROR;
	return (result);
}

double	parse_double(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
		{
			printf(RED "Error: Invalid character in double, \
				this should not be a tuple.\n" RESET);
			return (-DBL_MAX);
		}
		i++;
	}
	if (ft_atof(str) < 0 || ft_atof(str) > 180)
	{
		printf(RED "Error, fov should be between 0 and 180.\n" RESET);
		return (-DBL_MAX);
	}
	return (ft_atof(str));
}

static int	validate_tuple(t_tuple tuple, int commas, short type)
{
	if (commas != 2)
	{
		printf(RED "Error: Invalid number of commas in tuple.\n" RESET);
		return (ERROR);
	}
	if (type == VECTOR && !is_a_normalized_vector(tuple))
	{
		printf(RED "Error: Vector is not normalized.\n" RESET);
		return (ERROR);
	}
	if (type == COLOR && !validate_color(tuple))
	{
		printf(RED "Error: Color is not between 0 and 255.\n" RESET);
		return (ERROR);
	}
	return (0);
}

static int	validate_color(t_tuple tuple)
{
	if (tuple.x < 0 || tuple.x > 255)
		return (0);
	if (tuple.y < 0 || tuple.y > 255)
		return (0);
	if (tuple.z < 0 || tuple.z > 255)
		return (0);
	return (1);
}
