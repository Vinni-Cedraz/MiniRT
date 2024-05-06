/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_transform_ray.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:15:08 by johmatos          #+#    #+#             */
/*   Updated: 2024/04/28 11:07:50 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"

t_ray	create_ray(t_tuple origin, t_tuple direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	ray.origin.w = POINT;
	ray.direction.w = VECTOR;
	return (ray);
}

t_ray	transform_ray(const t_ray *ray, t_matrix matrix)
{
	return ((t_ray){
		.origin = multiply_tuple_by_matrix(ray->origin, matrix),
		.direction = multiply_tuple_by_matrix(ray->direction, matrix)
	});
}

t_tuple	_intersection_coordinates(t_ray ray, double t)
{
	return ((t_tuple){
		.x = ray.origin.x + ray.direction.x * t,
		.y = ray.origin.y + ray.direction.y * t,
		.z = ray.origin.z + ray.direction.z * t,
		.w = POINT
	});
}
