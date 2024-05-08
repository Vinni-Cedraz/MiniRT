/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:08:21 by igenial           #+#    #+#             */
/*   Updated: 2024/05/07 21:08:27 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersections	intersect_sphere(const t_shape *obj, const t_ray *trans_r,
		const t_tuple dist_to_ray)
{
	t_intersections	result;
	t_bhaskara		bask;
	double			d;

	d = _discriminant(dist_to_ray, trans_r, &bask);
	if (d < 0)
		return ((t_intersections){0});
	result.head = ft_lstnew((-bask.b - sqrt(d)) / (2 * bask.a), obj);
	result.head->next = ft_lstnew((-bask.b + sqrt(d)) / (2 * bask.a), obj);
	result.count = 2;
	return (result);
}

double	_discriminant(t_tuple obj_dist_ray, const t_ray *ray, t_bhaskara *bask)
{
	bask->a = dot(ray->direction, ray->direction);
	bask->b = 2 * dot(ray->direction, obj_dist_ray);
	bask->c = dot(obj_dist_ray, obj_dist_ray) - 1;
	return (pow(bask->b, 2) - 4 * bask->a * bask->c);
}
