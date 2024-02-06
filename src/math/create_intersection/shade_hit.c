/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 06:38:23 by johmatos          #+#    #+#             */
/*   Updated: 2023/11/07 07:56:04 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	init_light(t_world *world, t_lighting *lighting_object);
static void	init_position_and_vectors(t_prep_comps *comps, t_lighting *lght);

void	shade_hit(t_world *world, t_prep_comps *comps, t_tuple result)
{
	t_lighting		lighting_object;

	lighting_object.material = comps->object->material;
	init_light(world, &lighting_object);
	init_position_and_vectors(comps, &lighting_object);
	lighting_object.in_shadow = is_shadowed(world, comps->over_point);
	calculate_lighting(&lighting_object, result);
}

static void	init_light(t_world *world, t_lighting *lighting_object)
{
	init_tuple(world->light->intensity, lighting_object->light.intensity);
	init_tuple(world->light->position, lighting_object->light.position);
}

static void	init_position_and_vectors(t_prep_comps *comps, t_lighting *lght)
{
	init_tuple(comps->eyev, lght->eye_vec);
	init_tuple(comps->over_point, lght->position);
	init_tuple(comps->normalv, lght->normal_vec);
}
