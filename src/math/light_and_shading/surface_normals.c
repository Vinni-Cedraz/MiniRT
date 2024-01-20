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
		const t_shape *plane, const t_tuple wrld_p, t_tuple res)
{
	t_tuple	obj_nrml;
	t_tuple	wlrd_nrml;

	(void)wrld_p;
	init_tuple((t_tuple){0, 1, 0, VECTOR}, obj_nrml);
	multiply_tuple_by_matrix(obj_nrml, plane->transposed_inverse_t, wlrd_nrml);
	wlrd_nrml[W] = VECTOR;
	normalize(wlrd_nrml, res);
}

void	cylinder_normal_at( \
		const t_shape *cyl, const t_tuple wrld_p, t_tuple res)
{
	t_tuple		obj_point;
	t_tuple		obj_nrml;
	t_tuple		wlrd_nrml;
	float		dist;

	multiply_tuple_by_matrix(wrld_p, cyl->inverse_t, obj_point);
	dist = pow(obj_point[X], 2) + pow(obj_point[Z], 2);
	if (dist < 1 && obj_point[Y] >= cyl->max - EPSILON)
		init_tuple((t_tuple){0, 1, 0, VECTOR}, obj_nrml);
	else if (dist < 1 && obj_point[Y] <= cyl->min + EPSILON)
		init_tuple((t_tuple){0, -1, 0, VECTOR}, obj_nrml);
	else
		init_tuple((t_tuple){obj_point[X], 0, obj_point[Z], VECTOR}, obj_nrml);
	multiply_tuple_by_matrix(obj_nrml, cyl->transposed_inverse_t, wlrd_nrml);
	wlrd_nrml[W] = VECTOR;
	normalize(wlrd_nrml, res);
}
