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

// static double			cyl_discriminant(t_ray ray, t_baskara *bask);
// static double			_y0(t_ray *r, t_baskara *b);
// static double			_y1(t_ray *r, t_baskara *b);
// static t_intersection	create_cylinder_intersections(t_shape **obj, \
// 							t_baskara *bask, t_ray *r, const t_cylinder *cyl);

t_intersection	intersect_cylinder(t_shape **obj, t_tuple obj_dist_to_ray)
{
	(void)obj;
	(void)obj_dist_to_ray;
	return (t_intersection){0};
}

// static t_intersection	create_cylinder_intersections(t_shape **obj,
// 		t_baskara *bask, t_ray *r, const t_cylinder *cyl)
// {
// }
//
// static double	_y0(t_ray *r, t_baskara *b)
// {
// }
//
// static double	_y1(t_ray *r, t_baskara *b)
// {
// }
//
// static double	cyl_discriminant(t_ray ray, t_baskara *bask)
// {
// }
