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

static t_node	calculate_hit(t_world *w, t_tuple p);

t_bool	is_shadowed(t_world *w, t_tuple p)
{
	t_node	hit;
	double	distance;

	hit = calculate_hit(w, p);
	distance = magnitude(w->light.position);
	if (hit && hit.t < distance)
		return (TRUE);
	return (FALSE);
}

static t_node	calculate_hit(t_world *w, t_tuple p)
{
	double			distance;
	t_node			hit;
	t_tuple			vec;
	t_tuple			direction;
	t_intersections	intersections;

	vec = w->light.position;
	distance = magnitude(vec);
	direction = normalize(vec);
	r = create_ray(p, direction);
	intersections = intersect_world_with_ray(w, r);

	return (_hit(intersections));
}
