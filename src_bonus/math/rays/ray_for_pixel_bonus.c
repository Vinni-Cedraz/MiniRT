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

#include "minirt_bonus.h"

static void		set_offset_yx(t_camera *c, int pixel_y, int pixel_x);
static void		set_world_yx(t_camera *c);
static t_ray	compute_ray_direction(t_camera *c);

t_ray	ray_for_pixel(t_camera camera, int idx)
{
	t_ray	ray;

	set_offset_yx(&camera, (idx / camera.hsize), (idx % camera.hsize));
	set_world_yx(&camera);
	ray = compute_ray_direction(&camera);
	return (ray);
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
	t_ray			r;
	t_tuple			pixel;
	t_tuple			point;
	const t_tuple	up = create_point(0, 0, 0);

	point = create_point(c->world_x, c->world_y, -1);
	pixel = multiply_tuple_by_matrix(point, c->cam_inv_trans);
	r.origin = multiply_tuple_by_matrix(up, c->cam_inv_trans);
	r.direction = normalize(subtract_tuples(pixel, r.origin));
	return (r);
}
