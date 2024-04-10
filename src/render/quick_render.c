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

void	quick_render(t_world *w, const t_tuple from, t_camera camera)
{
	const t_tuple	to = (t_tuple){0, 0, 0, POINT};
	const t_tuple	up = (t_tuple){0, 1, 0, VECTOR};
	const t_tuple	forward = subtract_tuples(to, from);
	const t_tuple	normalized_forward = normalize(forward);
	mlx_t			*mlx;

	camera = create_camera(800, 600, M_PI / 4);
	camera.transform = view_transform(from, normalized_forward, up);
	mlx = mlx_init(SIZEW, SIZEH, "MLX42", true);
	if (!mlx)
	{
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	load_objs_into_world(*get_image_to_render(mlx), camera, w);
	mlx_image_to_window(mlx, *get_image_to_render(mlx), 0, 0);
	mlx_loop(mlx);
	free(w->objs);
}

void	create_test_world(t_world *world, const t_tuple from, int num_shapes,
		...)
{
	va_list		shapes;
	t_sphere		shape;
	t_camera	camera;
	int			i;

	i = 0;
	camera = (t_camera){0};
	va_start(shapes, num_shapes);
	world->objs = malloc(sizeof(t_sphere) * num_shapes);
	world->count = num_shapes;
	while (i < num_shapes)
	{
		shape = va_arg(shapes, t_sphere);
		world->objs[i] = *(t_sphere *)&shape;
		i++;
	}
	quick_render(world, from, camera);
	va_end(shapes);
}
