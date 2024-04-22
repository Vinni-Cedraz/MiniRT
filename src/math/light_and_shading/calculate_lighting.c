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

static void	init_of_compute_the_diffuse(t_type_light *c, t_lighting *l);

t_tuple	calculate_lighting(t_lighting *l)
{
	t_tuple			result;
	t_type_light	c;

	init_of_compute_the_diffuse(&c, l);
	if (c.light_dot_normal >= 0)
	{
		c.d = multiply_tuple_by_scalar(c.effective_color, l->material.diffuse);
		c.d = multiply_tuple_by_scalar(c.d, c.light_dot_normal);
		c.reflectv = reflect(negate_tuple(c.lightv), l->normal_vec);
		c.reflect_dot_eye = dot(c.reflectv, l->eye_vec);
		if (c.reflect_dot_eye <= 0)
			c.s = create_tuple(0, 0, 0, COLOR);
		else
		{
			c.factor = pow(c.reflect_dot_eye, l->material.shininess);
			c.s = multiply_tuple_by_scalar(l->light.intensity, \
			l->material.specular);
			c.s = multiply_tuple_by_scalar(c.s, c.factor);
		}
	}
	result = add_three_tuples(c.a, c.d, c.s);
	return (result);
}

static void	init_of_compute_the_diffuse(t_type_light *c, t_lighting *l)
{
	c->effective_color = multiply_colors(l->material.color, l->light.intensity);
	c->lightv = normalize(subtract_tuples(l->light.position, l->point));
	c->a = multiply_tuple_by_scalar(c->effective_color, l->material.ambient);
	c->a = add_tuples(c->a, l->parser_ambient);
	c->light_dot_normal = dot(c->lightv, l->normal_vec);
	if (c->light_dot_normal < 0)
	{
		c->d = create_tuple(0, 0, 0, COLOR);
		c->s = create_tuple(0, 0, 0, COLOR);
	}
}
