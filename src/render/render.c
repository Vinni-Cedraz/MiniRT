/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:49:49 by johmatos          #+#    #+#             */
/*   Updated: 2023/11/09 20:11:55 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render(mlx_image_t *image, t_world world)
{
	int		x;
	int		y;
	t_ray	ray;
	t_tuple	color;

	y = 0;
	while (y < world.camera.vsize)
	{
		x = 0;
		while (x < world.camera.hsize)
		{
			ray = ray_for_pixel(world.camera, y, x);
			color = color_at(&world, &ray);
			mlx_put_pixel(image, x, y, normalized_color_to_int(color));
			x++;
		}
		y++;
	}
	printf("y = %i | vsize = %i	", y, world.camera.vsize);
	printf("x = %i | hsize = %i\n", x, world.camera.hsize);
}
