/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_transform_rays.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:15:08 by johmatos          #+#    #+#             */
/*   Updated: 2024/04/20 19:28:42 by vcedraz-         ###   ########.fr       */
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
