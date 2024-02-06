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

t_world	create_world(void)
{
	t_world	w;

	w.objs = NULL;
	w.light = NULL;
	return (w);
}

t_world	default_world(void)
{
	t_world			w;
	t_shape			*default_shape;
	const t_sphere	default_sphere = create_sphere();

	w.count = 2;
	default_shape = (t_shape *)&default_sphere;
	w.light = malloc(sizeof(t_point_light));
	*(w.light) = (t_point_light){.position = {-10, 10, -10, POINT},
		.intensity = {1, 1, 1, COLOR}};
	w.objs = malloc(sizeof(t_shape) * 2);
	w.objs[0] = *default_shape;
	set_material((t_tuple){DEFAULT, 0.7, 0.2, DEFAULT}, (t_tuple){0.8, 1, 0.6,
		COLOR}, &w.objs[0].material);
	w.objs[1] = *default_shape;
	set_transform(&w.objs[1], create_scaling_matrix(0.5, 0.5, 0.5));
	return (w);
}

void	add_object(t_world *w, t_shape *new_obj,
		int total_nb_of_objects_in_the_world)
{
	t_shape	*new_objs;
	int		i;

	i = -1;
	new_objs = malloc(sizeof(t_shape) * (total_nb_of_objects_in_the_world + 1));
	while (++i < total_nb_of_objects_in_the_world)
		new_objs[i] = w->objs[i];
	new_objs[i] = *new_obj;
	free(w->objs);
	w->objs = new_objs;
	w->count = total_nb_of_objects_in_the_world;
}
