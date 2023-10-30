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
	t_world	w;

	w.light = malloc(sizeof(t_point_light));
	*(w.light) = (t_point_light){.position = {-10, 10, -10, POINT},
		.intensity = {1, 1, 1, COLOR}};
	w.objs = malloc(sizeof(t_sphere) * 2);
	w.objs[0] = create_sphere();
	set_material(
		(t_tuple){-1, 0.7, 0.2, -1},
		(t_tuple){0.8, 1, 0.6, COLOR},
		&w.objs[0].material \
	);
    w.objs[1] = create_sphere();
	set_transform(&w.objs[1], create_scaling_matrix(0.5, 0.5, 0.5));
	return (w);
}
