/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_normals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:33:40 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/20 11:37:07 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	sphere_normal_at( \
		const t_shape *sphere, const t_tuple wrld_p, t_tuple normal)
{
	t_tuple	obj_point;
	t_tuple	obj_nrml;
	t_tuple	wlrd_nrml;

	multiply_tuple_by_matrix(wrld_p, sphere->inverse_t, obj_point);
	subtract_tuples(obj_point, (t_tuple){0, 0, 0, POINT}, obj_nrml);
	multiply_tuple_by_matrix(obj_nrml, sphere->transposed_inverse_t, wlrd_nrml);
	wlrd_nrml[W] = VECTOR;
	normalize(wlrd_nrml, normal);
}

void	plane_normal_at( \
		const t_shape *plane, const t_tuple wrld_p, t_tuple normal)
{
	(void)wrld_p;
	(void)plane;
	init_tuple((t_tuple){0, 1, 0, VECTOR}, normal);
}

void	cylinder_normal_at( \
		const t_shape *cylinder, const t_tuple wrld_p, t_tuple normal)
{
	const float	dist = pow(wrld_p[X], 2) + pow(wrld_p[Z], 2);

	if (dist < 1 && wrld_p[Y] >= cylinder->max - EPSILON)
		init_tuple((t_tuple){0, 1, 0, VECTOR}, normal);
	else if (dist < 1 && wrld_p[Y] <= cylinder->min + EPSILON)
		init_tuple((t_tuple){0, -1, 0, VECTOR}, normal);
	else
		init_tuple((t_tuple){wrld_p[X], 0, wrld_p[Z], VECTOR}, normal);
}
