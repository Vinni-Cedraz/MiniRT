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
}

static void	set_offset_yx(t_camera *c, int pixel_y, int pixel_x)
{
}

static void	set_world_yx(t_camera *c)
{
}

static t_ray	compute_ray_direction(t_camera *c)
{
}
