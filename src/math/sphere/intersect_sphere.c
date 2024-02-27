/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 04:30:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/11/19 04:31:09 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersection	intersect_sphere(t_shape **obj, t_tuple obj_dist_ray)
{
	double			dis;
	t_baskara		bask;
	t_intersection	i;

	dis = discriminant(obj_dist_ray, (*obj)->r, &bask);
	if (dis < 0)
	{
		i.count = 0;
		i.head = NULL;
		return (i);
	}
	i = link_intersection_nodes((t_node *[]){
			intersection(\
				((bask.b * -1 - sqrt(dis)) / (2 * bask.a)), obj),
			intersection(\
				((bask.b * -1 + sqrt(dis)) / (2 * bask.a)), obj),
			NULL \
	});
	if (doubles_eq(0, dis))
		i.count = 1;
	return (i);
}

double	discriminant(t_tuple obj_dist_ray, t_ray ray, t_baskara *bask)
{
	bask->a = dot(ray.direction, ray.direction);
	bask->b = 2 * dot(ray.direction, obj_dist_ray);
	bask->c = dot(obj_dist_ray, obj_dist_ray) - 1;
	return (pow(bask->b, 2) - 4 * bask->a * bask->c);
}
