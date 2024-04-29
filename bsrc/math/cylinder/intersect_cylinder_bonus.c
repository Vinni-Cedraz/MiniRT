/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 04:33:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/11/19 04:34:05 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

static double	cyl_discriminant(t_tuple obj_dist_ray, const t_ray *ray,
					t_bhaskara *bask);

t_intersections	intersect_cylinder(const t_shape *obj, const t_ray *trans_r,
		const t_tuple dist)
{
	t_intersections	result;
	t_bhaskara		bask;
	double			d;

	d = cyl_discriminant(dist, trans_r, &bask);
	if (d < 0)
		return ((t_intersections){0});
	result.head = ft_lstnew((-bask.b - sqrt(d)) / (2 * bask.a), obj);
	result.head->next = ft_lstnew((-bask.b + sqrt(d)) / (2 * bask.a), obj);
	result.count = 2;
	return (result);
}

static double	cyl_discriminant(t_tuple obj_dist_ray, const t_ray *ray,
		t_bhaskara *bask)
{
	bask->a = dot(ray->direction, ray->direction);
	bask->b = 2 * dot(ray->direction, obj_dist_ray);
	bask->c = dot(obj_dist_ray, obj_dist_ray) - 1;
	if (doubles_eq(bask->a, 0))
		return (-1);
	return (pow(bask->b, 2) - 4 * bask->a * bask->c);
}
