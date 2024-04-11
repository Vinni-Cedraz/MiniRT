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

t_prep_comps	prepare_computations(t_node *hit, t_ray ray)
{
	t_prep_comps	prep;

	prep.t = hit->t;
	prep.object = hit->object;
	prep.point = _intersection_coordinates(ray, prep.t);
	prep.eyev = negate_tuple(ray.direction);
	prep.normalv = sphere_normal_at(prep.object, prep.point);
	if(dot(prep.normalv, prep.eyev) < 0)
	{
		prep.inside = true;
		prep.normalv = negate_tuple(prep.normalv);
	}
	else
		prep.inside = false;
	return (prep);
}
