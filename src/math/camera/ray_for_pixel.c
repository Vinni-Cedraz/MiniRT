/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_for_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:00:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/11/09 14:29:57 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		set_offset_yx(t_camera *c, int pixel_y, int pixel_x);
static void		set_world_yx(t_camera *c);
static t_ray	compute_ray_direction(t_camera *c);

t_ray	ray_for_pixel(t_camera camera, int pixel_y, int pixel_x)
{
	set_offset_yx(&camera, pixel_y, pixel_x);
	set_world_yx(&camera);
	return (compute_ray_direction(&camera));
}

static void	set_offset_yx(t_camera *c, int pixel_y, int pixel_x)
{
	c->yoffset = (pixel_y + 0.5) * c->pixel_size;
	c->xoffset = (pixel_x + 0.5) * c->pixel_size;
}

static void	set_world_yx(t_camera *c)
{
	c->world_y = c->half_height - c->yoffset;
	c->world_x = c->half_width - c->xoffset;
}

static t_ray	compute_ray_direction(t_camera *c)
{
	t_tuple			pixel;
	t_tuple			tmp;
	t_ray			ray;
	const t_matrix	t = invert_matrix(c->transform);

	multiply_tuple_by_matrix((t_tuple){
		c->world_x,
		c->world_y,
		-1, POINT}, t, pixel);
	multiply_tuple_by_matrix((t_tuple){0, 0, 0, POINT}, t, ray.origin);
	subtract_tuples(pixel, ray.origin, tmp);
	normalize(tmp, ray.direction);
	return (ray);
}
