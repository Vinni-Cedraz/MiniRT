/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_lighting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:54:09 by igenial           #+#    #+#             */
/*   Updated: 2024/04/23 16:54:11 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

static void	compute_the_specular(t_type_light *c, t_lighting *l);
static void	init_of_compute(t_type_light *c, t_lighting *l);
static void	compute_the_diffuse(t_type_light *c, t_lighting *l);

t_tuple	calculate_lighting(t_lighting l)
{
	t_tuple			result;
	t_type_light	c;

	init_of_compute(&c, &l);
	if (l.in_shadow)
		return (c.a);
	if (c.light_dot_normal < 0)
	{
		c.d = create_tuple(0, 0, 0, COLOR);
		c.s = create_tuple(0, 0, 0, COLOR);
	}
	else
	{
		compute_the_diffuse(&c, &l);
		c.lightv = negate_tuple(c.lightv);
		c.reflectv = reflect(c.lightv, l.normal_vec);
		c.reflect_dot_eye = dot(c.reflectv, l.eye_vec);
		compute_the_specular(&c, &l);
	}
	result = add_three_tuples(c.a, c.d, c.s);
	return (result);
}

static void	init_of_compute(t_type_light *c, t_lighting *l)
{
	c->effective_color = multiply_colors(l->material.color, l->light.intensity);
	c->lightv = subtract_tuples(l->light.position, l->point);
	c->lightv = normalize(c->lightv);
	c->a = multiply_tuple_by_scalar(c->effective_color, l->material.ambi);
	c->a = add_tuples(c->a, multiply_colors(l->material.color, l->wrld_ambien));
	c->light_dot_normal = dot(c->lightv, l->normal_vec);
}

static void	compute_the_specular(t_type_light *c, t_lighting *l)
{
	c->factor = pow(c->reflect_dot_eye, l->material.shiny);
	c->s = multiply_tuple_by_scalar(l->light.intensity, l->material.specular);
	c->s = multiply_tuple_by_scalar(c->s, c->factor);
}

static void	compute_the_diffuse(t_type_light *c, t_lighting *l)
{
	c->d = multiply_tuple_by_scalar(c->effective_color, l->material.dffse);
	c->d = multiply_tuple_by_scalar(c->d, c->light_dot_normal);
}
