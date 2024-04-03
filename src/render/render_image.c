/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:23:22 by johmatos          #+#    #+#             */
/*   Updated: 2023/11/28 12:16:49 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define MULTI 255

uint32_t	normalized_color_to_int(t_four_doubles col)
{
	if (col[X] > 1)
		col[X] = 1;
	if (col[Y] > 1)
		col[Y] = 1;
	if (col[Z] > 1)
		col[Z] = 1;
	return (((uint32_t)(col[X] * MULTI) << 24) | ((uint32_t)(col[Y]
				* MULTI) << 16) | ((uint32_t)(col[Z] * MULTI) << 8) | 0xff);
}

void	load_objs_into_world(mlx_image_t *image, t_camera camera,
		t_world *world)
{
	t_ray			ray;
	t_four_doubles	col;
	int				x;
	int				y;

	x = 0;
	y = 0;
	while (y < camera.vsize)
	{
		while (x < camera.hsize)
		{
			ray = ray_for_pixel(camera, y, x);
			color_at(world, &ray, (t_tuple){col[X], col[Y], col[Z], col[W]});
			mlx_put_pixel(image, x, y, normalized_color_to_int(col));
			x++;
		}
		x = 0;
		y++;
	}
}

mlx_image_t	**get_image_to_render(mlx_t *mlx)
{
	static mlx_image_t	*image = NULL;

	if (image == NULL)
		image = mlx_new_image(mlx, SIZEH, SIZEW);
	return (&image);
}
