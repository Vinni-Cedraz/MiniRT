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

static	void	set_tuple(t_tuple tuple, t_tuple setter)
{
	setter[X] = tuple[X];
	setter[Y] = tuple[Y];
	setter[Z] = tuple[Z];
	setter[W] = tuple[W];
}

void	shade_hit(t_world *world, t_prep_comps *comps, t_tuple result)
{
	t_lighting	light;

	light.material = world->objs->material;
	set_tuple(comps->eyev, light.eye_vec);
	set_tuple(comps->point, light.position);
	set_tuple(world->light->intensity, light.light.intensity);
	set_tuple(world->light->position, light.light.position);
	set_tuple(comps->normalv, light.normal_vec);
	calculate_lighting(&light, result);
}
