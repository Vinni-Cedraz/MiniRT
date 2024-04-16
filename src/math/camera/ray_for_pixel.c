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
	t_ray	ray;

	set_offset_yx(&camera, pixel_y, pixel_x);
	set_world_yx(&camera);
	ray = compute_ray_direction(&camera);
	return (ray);
}

static void	set_offset_yx(t_camera *c, int pixel_y, int pixel_x)
{
	c->xoffset = (pixel_x + 0.5) * c->pixel_size;
	c->yoffset = (pixel_y + 0.5) * c->pixel_size;
}

static void	set_world_yx(t_camera *c)
{
	c->world_x = c->half_width - c->xoffset;
	c->world_y = c->half_height - c->yoffset;
}

static t_ray	compute_ray_direction(t_camera *c)
{
	t_ray		r;
	t_tuple		pixel;
	t_tuple		point;
	t_matrix	invert_m;

	invert_m = invert_matrix(c->transform);
	point = create_point(c->world_x, c->world_y, -1);
	pixel = multiply_tuple_by_matrix(point, invert_m);
	r.origin = multiply_tuple_by_matrix(create_point(0, 0, 0), invert_m);
	r.direction = normalize(subtract_tuples(pixel, r.origin));
	return (r);
}
