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

#include "minirt_bonus.h"

t_bool	is_shadowed(t_world *w, t_tuple p, t_point_light light)
{
	t_tuple			vec;
	t_ray			ray;
	double			distance;
	t_node			hit;

	vec = subtract_tuples(light.position, p);
	distance = magnitude(vec);
	ray = create_ray(p, ray.origin);
	ray.direction = normalize(vec);
	hit = _hit(intersect_world_with_ray(w, &ray));
	if (hit.shape && hit.t < distance)
		return (TRUE);
	else
		return (FALSE);
}
