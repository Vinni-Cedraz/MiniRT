/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_lighting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:26:38 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/11/30 09:43:07 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	combine_surface_and_light(t_lighting *o, t_tuple c, t_tuple l);
static void	set_colors_to_black(t_tuple colr1, t_tuple colr2);
static void	set_reflect_v(t_colors *c, t_lighting *obj);
static void	point_in_shadow(t_tuple ambient, t_tuple res);

void	calculate_lighting(t_lighting *obj, t_tuple result)
{
	t_colors	c;
	double		light_dot_normal;
	double		reflectv_dot_eye;

	combine_surface_and_light(obj, c.true_colr, c.lightv);
	multiply_tuple_by_scalar(c.true_colr, obj->material.ambient, c.ambient);
	if (obj->in_shadow)
		return (point_in_shadow(c.ambient, result));
	light_dot_normal = dot(c.lightv, obj->normal_vec);
	if (light_dot_normal < 0)
		set_colors_to_black((&c)->diffuse, (&c)->specular);
	else
	{
		multiply_tuple_by_scalar(c.true_colr, \
		light_dot_normal * obj->material.diffuse, c.diffuse);
		set_reflect_v(&c, obj);
		reflectv_dot_eye = dot(c.reflectv, obj->eye_vec);
		if (reflectv_dot_eye <= 0)
			set_colors_to_black(c.specular, NULL);
		else
			multiply_tuple_by_scalar(obj->light.intensity, \
			obj->material.specular * pow(reflectv_dot_eye, \
			obj->material.shininess), c.specular);
	}
	add_three_tuples(c.ambient, c.diffuse, c.specular, result);
}

static inline void	point_in_shadow(t_tuple ambient, t_tuple res)
{
	init_tuple(ambient, res);
}

static inline void	combine_surface_and_light(t_lighting *obj,
		t_tuple true_colr, t_tuple lightv)
{
	multiply_colors(obj->material.color, obj->light.intensity, true_colr);
	subtract_tuples(obj->light.position, obj->position, lightv);
	normalize(lightv, lightv);
}

static inline void	set_colors_to_black(t_tuple colr1, t_tuple colr2)
{
	colr1[R] = 0;
	colr1[G] = 0;
	colr1[B] = 0;
	colr1[W] = COLOR;
	if (colr2)
	{
		colr2[R] = 0;
		colr2[G] = 0;
		colr2[B] = 0;
		colr2[W] = COLOR;
	}
}

static void	set_reflect_v(t_colors *c, t_lighting *obj)
{
	negate_tuple(c->lightv, c->lightv);
	reflect(c->lightv, obj->normal_vec, c->reflectv);
}
