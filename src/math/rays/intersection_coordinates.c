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

static void	set_sphere(t_shape *obj, double scaling, int color);

t_world	create_world(void)
{
	return ((t_world){0});
}

t_world	default_world(void)
{
	t_world	scene;

	scene = create_world();
	scene.light.position = create_tuple(-10, 10, -10, POINT);
	scene.light.intensity = create_tuple(1, 1, 1, COLOR);
	scene.shapes = malloc(2 * sizeof(t_shape));
	scene.shapes[0] = create_sphere();
	scene.shapes[1] = create_sphere();
	scene.fixed_count = 2;
	set_sphere(&scene.shapes[0], 0, 1);
	set_sphere(&scene.shapes[1], 0.5, 0);
	return (scene);
}

static void	set_sphere(t_shape *obj, double scaling, int color)
{
	if (scaling)
	{
		obj->_t = create_scaling_matrix(scaling, scaling, scaling);
		obj->inverse_t = invert_matrix(obj->_t);
	}
	if (color)
	{
		obj->material.color = create_tuple(0.8, 1.0, 0.6, COLOR);
		obj->material.dffse = 0.7;
		obj->material.specular = 0.2;
	}
}
