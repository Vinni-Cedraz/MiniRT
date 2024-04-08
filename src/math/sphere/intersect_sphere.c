/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:39:57 by vcedraz-          #+#    #+#             */
/*   Updated: 2024/04/05 14:40:01 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersections	intersect_sphere(t_sphere *obj, t_ray r)
{
	t_intersections	result;
	t_baskara		bask;
	double			d;

	r = transform_ray(r, obj->inverse_t);
	obj->dis_to_ray = subtract_tuples(r.origin, obj->origin);
	d = _discriminant(obj->dis_to_ray, r, &bask);
	if (d < 0)
	{
		result.count = 0;
		return (result);
	}
	result.head = ft_lstnew((-bask.b - sqrt(d)) / (2 * bask.a), obj);
	result.head->next = ft_lstnew((-bask.b + sqrt(d)) / (2 * bask.a), obj);
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
