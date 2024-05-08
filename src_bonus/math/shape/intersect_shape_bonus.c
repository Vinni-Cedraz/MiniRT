/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_shape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:02:03 by vcedraz-          #+#    #+#             */
/*   Updated: 2024/04/20 19:29:21 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_intersections	intersect_shape(t_shape *obj, const t_ray *r)
{
	const t_ray		transformed_ray = transform_ray(r, obj->inverse_t);
	t_intersections	this_obj_intersections;

	obj->dis_to_ray = subtract_tuples(transformed_ray.origin, obj->origin);
	this_obj_intersections = obj->intersect(obj, &transformed_ray);
	return (this_obj_intersections);
}
