/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_lighting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:26:38 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/24 11:30:48 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static inline void	multiply_tuples(t_tuple one, t_tuple two, t_tuple res)
{
	res[X] = dot(one, two);
	res[Y] = dot(one, two);
	res[Z] = dot(one, two);
	res[W] = COLOR;
}

static inline void	combine_surface_color_with_light_intensity(t_lighting *obj,
		t_tuple true_colr, t_tuple lightv)
{
	multiply_tuples(obj->material.color, obj->light.intensity, true_colr);
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

static inline void	add_three_tuples(t_tuple ambient, t_tuple diffuse,
		t_tuple specular, t_tuple result)
{
	t_tuple	tmp_tuple;

	add_tuples(ambient, diffuse, tmp_tuple);
	add_tuples(tmp_tuple, specular, result);
}

void	calculate_lighting(t_lighting *obj, t_tuple result)
{
	t_colors	c;
	float		tmp;
	float		light_dot_normal;
	double		reflect_dot_eye;

	combine_surface_color_with_light_intensity(obj, c.true_colr, c.lightv);
	multiply_tuple_by_scalar(c.true_colr, obj->material.ambient, c.ambient);
	light_dot_normal = dot(c.lightv, obj->normal_vec);
	if (light_dot_normal < 0)
		set_colors_to_black((&c)->diffuse, (&c)->specular);
	else
	{
		tmp = light_dot_normal * obj->material.diffuse;
		multiply_tuple_by_scalar(c.true_colr, tmp, c.diffuse);
		negate_tuple(c.lightv, c.lightv);
		reflect(c.lightv, obj->normal_vec, c.reflectv);
		reflect_dot_eye = dot(c.reflectv, obj->eye_vec);
		if (reflect_dot_eye <= 0)
			set_colors_to_black(c.specular, NULL);
		else
		{
			tmp = obj->material.specular * pow(reflect_dot_eye,
					obj->material.shininess);
			multiply_tuple_by_scalar(obj->light.intensity, tmp, c.specular);
		}
	}
	add_three_tuples(c.ambient, c.diffuse, c.specular, result);
}
