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
	(void)obj;
	(void)obj_dist_to_ray;
	(void)r;
	t_intersection	intersection;

	intersection.count = 0;
	printf("ALOU MAMAE\n");
	intersection.head = NULL;
	return (intersection);
}
