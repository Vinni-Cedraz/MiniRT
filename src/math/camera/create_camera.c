/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:10:15 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/11/09 14:14:47 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_pixel_size(t_camera *c);

t_camera	create_camera(int hsize, int vsize, float field_of_view)
{
	t_camera	c;

	c = (t_camera){
		.hsize = hsize,
		.vsize = vsize,
		.field_of_view = field_of_view,
		.transform = create_identity_matrix(),
		.pixel_size = 0,
	};
	set_pixel_size(&c);
	return (c);
}

static void	set_pixel_size(t_camera *c)
{
	float	half_view;
	float	aspect;

	half_view = tan(c->field_of_view / 2);
	aspect = (float)c->hsize / c->vsize;
	if (aspect >= 1)
	{
		c->half_width = half_view;
		c->half_height = half_view / aspect;
	}
	else
	{
		c->half_width = half_view * aspect;
		c->half_height = half_view;
	}
	c->pixel_size = (c->half_width * 2) / c->hsize;
}
