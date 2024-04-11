/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   building_world.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:26:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/30 17:31:30 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_sphere(t_sphere *obj, double scaling, int color);

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
	scene.objs = malloc(2 * sizeof(t_sphere));
	scene.objs[0] = create_sphere();
	scene.objs[1] = create_sphere();
	scene.count = 2;
	set_sphere(&scene.objs[0], 0, 1);
	set_sphere(&scene.objs[1], 0.5, 0);
	return (scene);
}

static void	set_sphere(t_sphere *obj, double scaling, int color)
{
	if (scaling)
	{
		obj->_t = create_scaling_matrix(scaling, scaling, scaling);
		obj->inverse_t = invert_matrix(obj->_t);
	}
	if (color)
	{
		obj->material.color = create_tuple(0.8, 1.0, 0.6, COLOR);
		obj->material.diffuse = 0.7;
		obj->material.specular = 0.2;
	}
}

void	add_object(t_world *w, t_sphere *new_obj,
		int total_nb_of_objects_in_the_world)
{
	(void)w;
	(void)new_obj;
	(void)total_nb_of_objects_in_the_world;
}
