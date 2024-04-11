/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:43:37 by johmatos          #+#    #+#             */
/*   Updated: 2023/10/13 19:06:22 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	_intersection_coordinates(t_ray ray, double t)
{
	return ((t_tuple){
		.x = ray.origin.x + ray.direction.x * t,
		.y = ray.origin.y + ray.direction.y * t,
		.z = ray.origin.z + ray.direction.z * t,
		.w = POINT
	});
}
