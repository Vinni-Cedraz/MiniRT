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

t_canvas	render(t_camera camera, t_world world)
{
	t_canvas	image;
	t_ray		ray;
	t_tuple		color;
	int			x;
	int			y;

	x = 0;
	y = 0;
	image = create_canvas(camera.vsize, camera.hsize);
	while (y < camera.vsize)
	{
		while (x < camera.hsize)
		{
			ray = ray_for_pixel(camera, y, x);
			color_at(&world, &ray, color);
			write_pixel(&image, y, x, color);
			x++;
		}
		x = 0;
		y++;
	}
	return (image);
}
