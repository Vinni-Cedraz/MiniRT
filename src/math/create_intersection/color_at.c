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

#include "minirt.h"

void	color_at(t_world *w, t_ray *r, t_tuple color)
{
	t_node					hit;
	t_prep_comps			computations;

	hit = get_hit(intersect_world_with_ray(w, r));
	if (!hit.object)
	{
		init_tuple((t_tuple){0, 0, 0, COLOR}, color);
		return ;
	}
	computations = prepare_computations(&hit, *r);
	shade_hit(w, &computations, color);
}
