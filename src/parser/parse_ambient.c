/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:04:52 by johmatos          #+#    #+#             */
/*   Updated: 2024/04/17 11:27:04 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	parse_intensity(char *str);

int	parse_ambient_light(t_token token, t_world *w)
{
	const double	amb_intensity = parse_intensity(token.args[0]);
	const t_tuple	amb_color = parse_tuple(token.args[1], COLOR);

	if (amb_intensity == -DBL_MAX || amb_color.w == ERROR)
		return (ERROR);
	w->ambient = multiply_tuple_by_scalar(amb_color, amb_intensity);
	return (0);
}

static double	parse_intensity(char *str)
{
	const double	intensity = ft_atof(str);

	if (intensity < 0 || intensity > 1)
	{
		printf(RED "Error: ambient intensity must be between 0 and 1\n");
		return (-DBL_MAX);
	}
	return (intensity);
}
