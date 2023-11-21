/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 04:31:41 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/11/19 04:33:44 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersection	intersect_plane(void **obj, t_tuple obj_dist_to_ray, t_ray r)
{
	t_intersection	xs;

	(void)obj_dist_to_ray;
	ft_bzero((void *)&xs, sizeof(t_intersection));
	if (fabsf(r.direction[Y]) < EPSILON)
	{
		printf("alou titio\n");
		return (xs);
	}
	xs.head = intersection((-r.origin[Y] / r.direction[Y]), obj);
	xs.count = 1;
	return (xs);
}
