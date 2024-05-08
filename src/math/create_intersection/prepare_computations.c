/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_computations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:10:52 by igenial           #+#    #+#             */
/*   Updated: 2024/05/07 21:10:55 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_prep_comps	prepare_computations(const t_node *hit, t_ray ray)
{
	t_prep_comps	prep;

	prep.t = hit->t;
	prep.shape = hit->shape;
	prep.point = _intersection_coordinates(ray, prep.t);
	prep.eyev = negate_tuple(ray.direction);
	prep.normalv = hit->shape->normal_at(prep.shape, prep.point);
	if (dot(prep.normalv, prep.eyev) < 0)
	{
		prep.inside = true;
		prep.normalv = negate_tuple(prep.normalv);
	}
	else
		prep.inside = false;
	prep.over_point = add_tuples(prep.point,
			multiply_tuple_by_scalar(prep.normalv, EPSILON));
	return (prep);
}
