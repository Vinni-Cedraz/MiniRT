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

// the offset from the edge of the canvas to the pixel's center
static void set_offset_yx(t_camera *c, int pixel_x, int pixel_y);
// the untransformed coordinates of the pixel in world space.
static void set_world_yx(t_camera *c);
// using the camera matrix, transform the canvas point and the origin, and then
// compute the ray's direction vector.
static void compute_ray_direction(t_camera *c, t_ray *ray);

t_ray ray_for_pixel(t_camera camera, int pixel_x, int pixel_y) {
    t_ray ray;

    set_offset_yx(&camera, pixel_x, pixel_y);
    set_world_yx(&camera);
    compute_ray_direction(&camera, &ray);
    return (ray);
}

static void set_offset_yx(t_camera *c, int pixel_x, int pixel_y) {
    c->xoffset = (pixel_x + 0.5) * c->pixel_size;
    c->yoffset = (pixel_y + 0.5) * c->pixel_size;
}

static void set_world_yx(t_camera *c) {
    c->world_x = c->half_width - c->xoffset;
    c->world_y = c->half_height - c->yoffset;
}

#include "assert.h"

static void compute_ray_direction(t_camera *c, t_ray *ray) {
    t_tuple pixel;
    t_tuple tmp;
    const t_matrix t = invert_matrix(c->transform);

	init_tuple((t_tuple){0, 0, 0, POINT}, ray->origin);
	init_tuple((t_tuple){0, 0, 0, VECTOR}, ray->direction);
    multiply_tuple_by_matrix((t_tuple){c->world_x, c->world_y, -1, POINT}, t, pixel);
    multiply_tuple_by_matrix((t_tuple){0, 0, 0, POINT}, t, ray->origin);
    subtract_tuples(pixel, ray->origin, tmp);
    normalize(tmp, ray->direction);
}
