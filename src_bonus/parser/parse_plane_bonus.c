/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:03:52 by johmatos          #+#    #+#             */
/*   Updated: 2024/04/17 12:20:30 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_shape	init_plane(const t_tuple c, const t_tuple up, const t_tuple cl);
_Bool	is_standard_orientation(t_tuple up);

int	parse_plane(t_token token, t_world *w)
{
	const t_tuple	origin = parse_tuple(token.args[0], POINT);
	const t_tuple	forward = parse_tuple(token.args[1], VECTOR);
	const t_tuple	color = parse_tuple(token.args[2], COLOR);

	if (origin.w == ERROR || forward.w == ERROR || color.w == ERROR)
		return (ERROR);
	w->shapes[w->moving_idx--] = init_plane(origin, forward, color);
	return (0);
}

t_shape	init_plane(const t_tuple from, const t_tuple up, const t_tuple cl)
{
	t_shape	plane;

	plane = create_plane();
	plane.material.color = cl;
	if (is_standard_orientation(up))
		return (plane);
	set_transform(&plane, shape_view_transform(from, up));
	return (plane);
}

_Bool	is_standard_orientation(t_tuple up)
{
	const t_tuple	standard_up = create_vector(0, 1, 0);

	return (tuples_eq(up, standard_up));
}
