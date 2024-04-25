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

#include "minirt_bonus.h"

t_tuple	shade_hit(t_world *world, t_prep_comps *comps)
{
	t_tuple	result;
	int		idx;

	idx = -1;
	result = (t_tuple){0};
	while (++idx < world->nb_of_lights)
	{
		result = add_tuples(result,
				calculate_lighting(&(t_lighting){
					comps->shape->material,
					world->lights[idx],
					comps->point,
					comps->eyev,
					comps->normalv,
					world->parser_ambient,
					is_shadowed(world, comps->over_point),
				}));
	}
	return (result);
}
