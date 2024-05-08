/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:13:32 by igenial           #+#    #+#             */
/*   Updated: 2024/05/07 21:41:30 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	is_shadowed(t_world *w, t_tuple p)
{
	t_tuple			vec;
	t_ray			ray;
	double			distance;
	t_node			hit;
	t_intersections	xs;

	vec = subtract_tuples(w->light.position, p);
	distance = magnitude(vec);
	ray = create_ray(p, ray.origin);
	ray.direction = normalize(vec);
	xs = intersect_world_with_ray(w, &ray);
	hit = _hit(xs);
	ft_lstfree((void *)&xs.head);
	if (hit.shape && hit.t < distance)
		return (TRUE);
	else
		return (FALSE);
}
