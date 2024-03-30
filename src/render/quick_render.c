/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:21:27 by vcedraz-          #+#    #+#             */
/*   Updated: 2024/03/24 20:22:50 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdarg.h>

void quick_render(t_world *w, const t_tuple from) {
    t_camera camera = create_camera(800, 600, M_PI / 4);
    t_tuple to = (t_tuple){0, 0, 0, POINT};
    t_tuple up = (t_tuple){0, 1, 0, VECTOR};
    const t_tuple forward = subtract_tuples(to, from);
    const t_tuple normalized_forward= normalize(forward);

    camera.transform = view_transform(from, normalized_forward, up);
	mlx_t	*mlx;

	if (!(mlx = mlx_init(SIZEW, SIZEH, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}

	load_objs_into_world(*get_image_to_render(mlx), camera, w);
	mlx_image_to_window(mlx, *get_image_to_render(mlx), 0, 0);
	mlx_loop(mlx);
    free(w->objs);
}

void create_test_world(t_world *world, const t_tuple from, int num_shapes, ...)
{
    va_list shapes;
    va_start(shapes, num_shapes);

    world->objs = malloc(sizeof(t_shape) * num_shapes);
    world->count = num_shapes;
    for (int i = 0; i < num_shapes; i++) {
        t_shape shape = va_arg(shapes, t_shape);
        world->objs[i] = *(t_shape *)&shape;
    }
    quick_render(world, from);
    va_end(shapes);
}
