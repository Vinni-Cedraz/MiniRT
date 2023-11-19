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

t_prep_comps	prepare_computations(t_node *intersection, t_ray ray)
{
	t_prep_comps	computations;

	computations = (t_prep_comps){
		.t = intersection->t,
		.object = (t_shape*)intersection->object,
	};
	get_position(ray, computations.t, computations.point);
	if (computations.object->type == SPHERE)
		sphere_normal_at(
			(t_sphere *)intersection->object,
			computations.point,
			computations.normalv \
	);
	negate_tuple(ray.direction, computations.eyev);
	if (dot(computations.normalv, computations.eyev) < 0)
	{
		computations.inside = TRUE;
		negate_tuple(computations.normalv, computations.normalv);
	}
	else
		computations.inside = FALSE;
	return (computations);
}
