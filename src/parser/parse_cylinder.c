/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:04:32 by johmatos          #+#    #+#             */
/*   Updated: 2024/04/17 11:27:18 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_cylinder(t_token token, t_world *w)
{
	const t_tuple	from = parse_tuple(token.args[0], POINT);
	const t_tuple	up = parse_tuple(token.args[1], VECTOR);
	const double	diamet = parse_double(token.args[2], false);
	const double	height = parse_double(token.args[3], false);
	const t_tuple	color = parse_tuple(token.args[4], COLOR);

	if (from.w == ERROR || diamet == -DBL_MAX || color.w == ERROR
		|| up.w == ERROR || height == -DBL_MAX)
		return (ERROR);
	set_cyl_min_max(&w->shapes[w->moving_idx], -height / 2, height / 2);
	w->shapes[w->moving_idx--] = create_cylinder();
	w->shapes[w->moving_idx].material.color = color;
	if (is_standard_orientation(up, from))
	{
		set_transform(&w->shapes[w->moving_idx],
			create_scaling_matrix(diamet / 2, diamet / 2, diamet / 2));
		return (0);
	}
	set_transform(&w->shapes[w->moving_idx],
		mult_matrices(
			shape_view_transform(from, up),
			create_scaling_matrix(diamet / 2, diamet / 2, diamet / 2))
		);
	return (0);
}
