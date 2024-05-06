/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:04:11 by johmatos          #+#    #+#             */
/*   Updated: 2024/04/17 12:20:34 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	parse_intensity(char *str);

int	parse_ambient(t_token token, t_world *w)
{
	const double	amb_intensity = parse_intensity(token.args[0]);
	const t_tuple	amb_color = parse_tuple(token.args[1], COLOR);

	if (amb_intensity == -DBL_MAX || amb_color.w == ERROR)
		return (ERROR);
	w->parser_ambient = multiply_tuple_by_scalar(amb_color, amb_intensity);
	return (0);
}

int	parse_light(t_token token, t_world *w)
{
	const t_tuple	coordinates = parse_tuple(token.args[0], POINT);
	const double	in = parse_intensity(token.args[1]);

	if (coordinates.w == ERROR || in == -DBL_MAX)
		return (ERROR);
	w->light = (t_point_light){coordinates, create_tuple(in, in, in, COLOR)};
	return (false);
}

static double	parse_intensity(char *str)
{
	const double	in = ft_atof(str);

	if (in < 0 || in > 1)
	{
		printf(RED "Error: intensity must be between 0 and 1\n");
		return (-DBL_MAX);
	}
	return (in);
}
