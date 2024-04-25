/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_coordinates.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:14:08 by vcedraz-          #+#    #+#             */
/*   Updated: 2024/04/20 19:14:09 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_tuple	_intersection_coordinates(t_ray ray, double t)
{
	return ((t_tuple){
		.x = ray.origin.x + ray.direction.x * t,
		.y = ray.origin.y + ray.direction.y * t,
		.z = ray.origin.z + ray.direction.z * t,
		.w = POINT
	});
}
