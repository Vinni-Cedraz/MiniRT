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

int	parse_sphere(t_token token, t_world *w)
{
	const t_tuple	coordinates = parse_tuple(token.args[0], POINT);
	const double	scale = parse_double(token.args[1], false);
	const t_tuple	color = parse_tuple(token.args[2], COLOR);
	t_sphere		sphere;

	sphere = create_sphere();
	if (coordinates.w == ERROR || scale == -DBL_MAX || color.w == ERROR)
		return (ERROR);
	sphere._t = mult_matrices(
			create_translation_matrix(coordinates),
			create_scaling_matrix(scale, scale, scale));
	sphere.inverse_t = invert_matrix(sphere._t);
	sphere.trans_inv = transpose_matrix(sphere.inverse_t);
	sphere.material.color = color;
	w->objs[sphere.id] = sphere;
	return (false);
}
