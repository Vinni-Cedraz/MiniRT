/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:20:22 by vcedraz-          #+#    #+#             */
/*   Updated: 2024/04/17 12:20:27 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

static t_shape	init_sphere(const t_tuple c, const double s, const t_tuple cl);

int	parse_sphere(t_token token, t_world *w)
{
	const t_tuple	coordinates = parse_tuple(token.args[0], POINT);
	const double	diameter = parse_double(token.args[1], false);
	const t_tuple	color = parse_tuple(token.args[2], COLOR);

	if (coordinates.w == ERROR || diameter == -DBL_MAX || color.w == ERROR)
		return (ERROR);
	w->shapes[w->moving_idx--] = init_sphere(coordinates, diameter, color);
	return (0);
}

static t_shape	init_sphere(const t_tuple coordinates, const double diameter,
		const t_tuple color)
{
	t_shape			sphere;
	const double	scale = diameter / 2;

	sphere = create_sphere();
	set_transform(&sphere, mult_matrices(
			create_translation_matrix(coordinates),
			create_scaling_matrix(scale, scale, scale)));
	sphere.material.color = color;
	return (sphere);
}
