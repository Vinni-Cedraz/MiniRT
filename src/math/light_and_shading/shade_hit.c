/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:37:44 by igenial           #+#    #+#             */
/*   Updated: 2024/05/07 21:37:46 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	shade_hit(t_world *world, t_prep_comps *comps)
{
	return (calculate_lighting(&(t_lighting){
			comps->shape->material,
			world->light,
			comps->point,
			comps->eyev,
			comps->normalv,
			world->parser_ambient,
			is_shadowed(world, comps->over_point),
		}));
}
