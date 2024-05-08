/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:40:34 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/11/19 17:28:12 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_tuple	color_at(t_world *w, const t_ray *r)
{
	t_prep_comps			prep;
	const t_intersections	lst = intersect_world_with_ray(w, r);
	const t_node			hit = _hit(lst);

	if (hit.shape == NULL)
		return (create_tuple(0, 0, 0, COLOR));
	prep = prepare_computations(&hit, *r);
	ft_lstfree((void *)&lst.head);
	return (shade_hit(w, &prep));
}
