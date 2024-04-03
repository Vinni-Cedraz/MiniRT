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
	(void)obj;
	(void)obj_dist_ray;
	return ((t_intersection){0});
}

double	discriminant(t_tuple obj_dist_ray, t_ray ray, t_baskara *bask)
{
	(void)obj_dist_ray;
	(void)ray;
	(void)bask;
	return (0);
}
