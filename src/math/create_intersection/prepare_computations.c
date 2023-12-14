/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_computations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:24:54 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/11/19 17:24:57 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		calculate_over_point(t_prep_comps *comps);

t_prep_comps	prepare_computations(t_node *hit, t_ray ray)
{
	t_prep_comps				cmp;
	const t_normal_at_function	normal_at[3] = {
		sphere_normal_at, plane_normal_at, cylinder_normal_at
	};

	cmp = (t_prep_comps){
		.t = hit->t,
		.object = (t_shape *)hit->object,
	};
	get_position(ray, cmp.t, cmp.point);
	normal_at[cmp.object->type](hit->object, cmp.point, cmp.normalv);
	negate_tuple(ray.direction, cmp.eyev);
	if (dot(cmp.normalv, cmp.eyev) < 0)
	{
		cmp.inside = TRUE;
		negate_tuple(cmp.normalv, cmp.normalv);
	}
	else
		cmp.inside = FALSE;
	calculate_over_point(&cmp);
	return (cmp);
}

static void	calculate_over_point(t_prep_comps *comps)
{
	t_tuple		normalv;

	multiply_tuple_by_scalar(comps->normalv, EPSILON, normalv);
	add_tuples(comps->point, normalv, comps->over_point);
}
