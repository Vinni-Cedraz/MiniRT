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

#include "minirt_bonus.h"

static int		validate_cyl_args(t_token token, t_parse_cylinder *cyl);
static t_shape	init_cylinder(const t_parse_cylinder cyl);

int	parse_cylinder(t_token token, t_world *w)
{
	t_parse_cylinder	cyl;

	if (ERROR == validate_cyl_args(token, &cyl))
		return (ERROR);
	w->shapes[w->moving_idx--] = init_cylinder(cyl);
	return (0);
}

static int	validate_cyl_args(t_token token, t_parse_cylinder *cyl)
{
	cyl->from = parse_tuple(token.args[0], POINT);
	if (cyl->from.w == ERROR)
		return (ERROR);
	cyl->up = parse_tuple(token.args[1], VECTOR);
	if (cyl->up.w == ERROR)
		return (ERROR);
	cyl->diameter = parse_double(token.args[2], false);
	if (cyl->diameter == -DBL_MAX)
		return (ERROR);
	cyl->scale = cyl->diameter / 2;
	cyl->height = parse_double(token.args[3], false);
	if (cyl->height == -DBL_MAX)
		return (ERROR);
	cyl->color = parse_tuple(token.args[4], COLOR);
	if (cyl->color.w == ERROR)
		return (ERROR);
	return (0);
}

static t_shape	init_cylinder(const t_parse_cylinder cyl)
{
	t_shape	cy;

	cy = create_cylinder();
	cy.material.color = cyl.color;
	set_cyl_min_max(&cy, -cyl.height / 2, cyl.height / 2, CLOSED);
	if (is_standard_orientation(cyl.up))
	{
		set_transform(&cy,
			mult_matrices(
				create_translation_matrix(cyl.from),
				create_scaling_matrix(cyl.scale, cyl.scale, cyl.scale))
			);
	}
	else
	{
		set_transform(&cy,
			mult_matrices(
				shape_view_transform(cyl.from, cyl.up),
				create_scaling_matrix(cyl.scale, cyl.scale, cyl.scale))
			);
	}
	return (cy);
}
