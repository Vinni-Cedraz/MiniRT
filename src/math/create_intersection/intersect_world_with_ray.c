/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_world_with_ray.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:39:02 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/11/03 15:51:58 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersections	intersect_world_with_ray(t_world *w, t_ray *r)
{
	t_intersections	result;
	t_intersections	tmp;
	int				idx;

	idx = 0;
	result.head = NULL;
	tmp = intersect_sphere(&w->objs[0], *r);
	while (idx < w->count - 1)
	{
		tmp = intersect_sphere(&w->objs[idx], *r);
		printf("%f\n", tmp.head->next->t);
		ft_lstadd_back(&result.head, tmp.head);
		idx++;
	}
	result.count = w->count * 2;
	return (result);
}
