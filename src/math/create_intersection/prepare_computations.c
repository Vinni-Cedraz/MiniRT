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
	t_prep_comps				cmp;
	const t_normal_at_function	normal_at[3] = {
		sphere_normal_at, plane_normal_at, cylinder_normal_at
	};

	cmp = (t_prep_comps){
		.t = intersection->t,
		.object = (t_shape *)intersection->object,
	};
	get_position(ray, cmp.t, cmp.point);
	normal_at[cmp.object->type](intersection->object, cmp.point, cmp.normalv);
	negate_tuple(ray.direction, cmp.eyev);
	if (dot(cmp.normalv, cmp.eyev) < 0)
	{
		cmp.inside = TRUE;
		negate_tuple(cmp.normalv, cmp.normalv);
	}
	else
		cmp.inside = FALSE;
	return (cmp);
}
