/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_computations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:21:18 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/11/05 15:21:52 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_prep_comps	prepare_computations(t_node *intersection, t_ray ray)
{
	t_prep_comps 	comp;

	comp = (t_prep_comps){
		.t = intersection->t,
		.object = (t_sphere*)intersection->object,
	};
	get_position(ray, comp.t, comp.point);
	normal_at(comp.object, comp.point, comp.normalv);
	negate_tuple(ray.direction, comp.eyev);
	return (comp);
}
