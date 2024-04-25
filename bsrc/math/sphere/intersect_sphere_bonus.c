/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:39:57 by vcedraz-          #+#    #+#             */
/*   Updated: 2024/04/20 19:24:58 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_intersections	intersect_sphere(const t_shape *obj, const t_ray *trans_r)
{
	t_intersections	result;
	t_bhaskara		bask;
	double			d;

	d = _discriminant(obj->dis_to_ray, trans_r, &bask);
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
