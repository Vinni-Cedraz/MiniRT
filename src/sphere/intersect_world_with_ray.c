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

t_intersection	intersect_world_with_ray(t_world *w, t_ray *r)
{
	int 			count;
	t_intersection 	obj_intersec;
	t_intersection 	res;
	void			*obj;

	count = 0;
	res = (t_intersection){0};
	while (count != w->count)
	{
		obj_intersec = create_intersection(&w->objs[count], *r);
		if (obj_intersec.head)
		{
			obj = &w->objs[count];
			ft_lstadd_back(&res.head, intersection(obj_intersec.head->t, (void **)&obj));
			ft_lstadd_back(&res.head, intersection(obj_intersec.head->next->t, (void **)&obj));
		}
		count++;
	}
	return (res);
}
