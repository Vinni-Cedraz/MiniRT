/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphereay.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@studentay.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 04:30:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/11/19 04:31:09 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersection	intersect(t_sphere *obj, t_ray r)
{
	t_intersection result;
	t_baskara bask;
	double d;

	obj->dis_to_ray = subtract_tuples(r.origin, create_point(0, 0, 0));
	d = _discriminant(obj->dis_to_ray, r, &bask);
	if (d < 0)
	{
		result.count = 0;
		return (result);
	}
	result.this_obj_intersections[0].t = (-bask.b - sqrt(d)) / 2 * bask.a;
	result.this_obj_intersections[1].t = (-bask.b + sqrt(d)) / 2 * bask.a;
	result.count = 2;
	return (result);
}

double	_discriminant(t_tuple obj_dist_ray, t_ray ray, t_baskara *bask)
{
	bask->a = dot(ray.direction, ray.direction);
	bask->b = 2 * dot(ray.direction, obj_dist_ray);
	bask->c = dot(obj_dist_ray, obj_dist_ray) - 1;
	return (pow(bask->b, 2) - 4 * bask->a * bask->c);
}
