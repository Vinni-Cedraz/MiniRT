/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_normals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:12:49 by igenial           #+#    #+#             */
/*   Updated: 2024/05/07 21:12:57 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	sphere_normal_at(const t_shape *sphere, const t_tuple world_point)
{
	t_tuple	object_normal;
	t_tuple	world_normal;
	t_tuple	object_point;

	object_point = multiply_tuple_by_matrix(world_point, sphere->inverse_t);
	object_normal = subtract_tuples(object_point, sphere->origin);
	world_normal = multiply_tuple_by_matrix(object_normal, sphere->trans_inv);
	world_normal.w = VECTOR;
	return (normalize(world_normal));
}

t_tuple	plane_normal_at( \
		const t_shape *plane, const t_tuple world_point)
{
	const t_tuple	up = create_vector(0, 1, 0);
	const t_tuple	new_nrmal = multiply_tuple_by_matrix(up, plane->trans_inv);

	(void)world_point;
	return (normalize(new_nrmal));
}

t_tuple	cylinder_normal_at(const t_shape *cyl, const t_tuple world_point)
{
	t_tuple	object_normal;
	t_tuple	world_normal;
	t_tuple	object_point;
	double	dis;

	object_point = multiply_tuple_by_matrix(world_point, cyl->inverse_t);
	dis = object_point.x * object_point.x + object_point.z * object_point.z;
	if (dis < 1 && doubles_eq(object_point.y, cyl->max))
		object_normal = create_vector(0, 1, 0);
	else if (dis < 1 && doubles_eq(object_point.y, cyl->min))
		object_normal = create_vector(0, -1, 0);
	else
		object_normal = create_vector(object_point.x, 0, object_point.z);
	world_normal = multiply_tuple_by_matrix(object_normal, cyl->trans_inv);
	world_normal.w = VECTOR;
	return (normalize(world_normal));
}
