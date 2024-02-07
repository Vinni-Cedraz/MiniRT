/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:15:33 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/12/12 20:30:30 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	is_shadowed(t_world *w, t_tuple p)
{
	t_tuple			vec;
	t_ray			ray;
	double			distance;
	t_node			hit;

	subtract_tuples(w->light->position, p, vec);
	distance = magnitude(vec);
	init_tuple(p, ray.origin);
	normalize(vec, ray.direction);
	hit = get_hit(intersect_world_with_ray(w, &ray));
	if (hit.object && hit.t < distance)
		return (TRUE);
	else
		return (FALSE);
}
