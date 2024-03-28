/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_world.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:35:37 by johmatos          #+#    #+#             */
/*   Updated: 2023/11/30 09:42:51 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_world init_world(t_shape *floor, t_sphere *balls[], t_plane *walls[6]) {
	t_world world;

    world.objs = malloc(sizeof(t_sphere) * (walls?10:4));
    world.count = (walls?10:4);
    world.objs[0] = *floor;
    world.objs[1] = *(t_shape *)balls[0];
    world.objs[2] = *(t_shape *)balls[1];
    world.objs[3] = *(t_shape *)balls[2];
	if (walls) {
		world.objs[4] = *(t_shape *)walls[0];
		world.objs[5] = *(t_shape *)walls[1];
		world.objs[6] = *(t_shape *)walls[2];
		world.objs[7] = *(t_shape *)walls[3];
		world.objs[8] = *(t_shape *)walls[4];
		world.objs[9] = *(t_shape *)walls[5];
	}
	world.light = malloc(sizeof(t_point_light));
    world.light[0] = (t_point_light){
        {10, 100, 30, POINT},
        {1, 1, 1, COLOR},
    };
	return (world);
}

void init_floor(t_shape *floor) {
    set_material(
			(t_tuple){DEFAULT, DEFAULT, 0, DEFAULT},
			(t_tuple){1, 0.9, 0.9, COLOR},
			&floor->material
	);
}

void	render_a_default_world(mlx_t *mlx)
{
    t_camera camera = create_camera(SIZEH, SIZEW, M_PI / 3);
    t_tuple from = (t_tuple){0, 40, 10, POINT};
    t_tuple to = (t_tuple){0, 0, 1, POINT};
    t_tuple up = (t_tuple){1, 0, 0, VECTOR};
    t_tuple forward = (t_tuple){0};

	t_world world = create_world();
    forward = subtract_tuples(to, from);
    normalize(forward, forward);
    camera.transform = view_transform(from, forward, up);
	load_objs_into_world(*get_image_to_render(mlx), camera, &world);
}
