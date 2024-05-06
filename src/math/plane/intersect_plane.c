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

t_intersections	intersect_plane(const t_shape *obj, const t_ray *trans_ray,
		const t_tuple dist)
{
	t_intersections	intersections;
	double			t;

	(void)dist;
	intersections = (t_intersections){0};
	if (fabs(trans_ray->direction.y) < EPSILON)
		return (intersections);
	t = -trans_ray->origin.y / trans_ray->direction.y;
	intersections.head = ft_lstnew(t, obj);
	intersections.count = 1;
	return (intersections);
}
