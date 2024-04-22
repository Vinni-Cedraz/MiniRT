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

#include "minirt.h"

static t_shape	init_sphere(const t_tuple c, const double s, const t_tuple cl);

int	parse_sphere(t_token token, t_world *w)
{
	const t_tuple	coordinates = parse_tuple(token.args[0], POINT);
	const double	scale = parse_double(token.args[1], false);
	const t_tuple	color = parse_tuple(token.args[2], COLOR);

	if (coordinates.w == ERROR || scale == -DBL_MAX || color.w == ERROR)
		return (ERROR);
	w->shapes[w->moving_idx--] = init_sphere(coordinates, scale, color);
	return (false);
}

static t_shape	init_sphere(const t_tuple coordinates, const double scale,
		const t_tuple color)
{
	t_shape	sphere;

	sphere = create_sphere();
	set_transform(&sphere, mult_matrices(
			create_translation_matrix(coordinates),
			create_scaling_matrix(scale, scale, scale)));
	sphere.material.color = color;
	return (sphere);
}
