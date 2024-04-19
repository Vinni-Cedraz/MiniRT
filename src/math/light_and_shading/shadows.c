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

t_bool	is_shadowed(t_world *w, t_tuple point)
{
	const t_tuple	vec = subtract_tuples(w->light.position, point);
	const double	distance = magnitude(vec);
	const t_tuple	direction = normalize(vec);
	const t_ray		r = create_ray(point, direction);
	const t_node	hit = _hit(intersect_world_with_ray(w, (t_ray *)&r));

	if (hit.object && hit.t < distance)
		return (TRUE);
	return (FALSE);
}
