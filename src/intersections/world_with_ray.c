/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_with_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:39:02 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/11/03 15:51:58 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersection	intersect_world_with_ray(t_world *w, t_ray *r)
{
	t_intersection	obj1_intersects;
	t_intersection	obj2_intersects;

	obj1_intersects = create_intersection(&w->objs[0], *r);
	obj2_intersects = create_intersection(&w->objs[1], *r);
	link_intersection_nodes((t_node *[]){
		obj1_intersects.head,
		obj1_intersects.head->next,
		obj2_intersects.head,
		obj2_intersects.head->next, \
	});
	return (obj1_intersects);
}
