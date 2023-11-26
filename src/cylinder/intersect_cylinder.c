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

#include "minirt.h"
#include <assert.h>

static float	discriminant(t_ray ray, t_baskara *bask);

t_intersection	intersect_cylinder(void **obj, t_tuple obj_dist_to_ray, t_ray r)
{
	t_intersection	xs;
	float			dis;
	t_baskara		bask;

	(void)obj_dist_to_ray;
	ft_bzero((void *)&xs, sizeof(t_intersection));
	bask.a = (pow(r.direction[X], 2) + pow(r.direction[Z], 2));
	if (floats_eq(0, bask.a))
		return (xs);
	dis = discriminant(r, &bask);
	if (dis < 0)
		return (xs);
	xs = link_intersection_nodes((t_node *[]){
			intersection(\
				((-bask.b - sqrt(dis)) / (2 * bask.a)), obj),
			intersection(\
				((-bask.b + sqrt(dis)) / (2 * bask.a)), obj),
			NULL \
	});
	return (xs);
}

static float	discriminant(t_ray ray, t_baskara *bask)
{
	float	dis;

	bask->b = 2 * ray.origin[X] * ray.direction[X] + 2 * ray.origin[Z] \
	* ray.direction[Z];
	bask->c = pow(ray.origin[X], 2) + pow(ray.origin[Z], 2) - 1;
	dis = pow(bask->b, 2) - 4 * bask->a * bask->c;
	return (dis);
}
