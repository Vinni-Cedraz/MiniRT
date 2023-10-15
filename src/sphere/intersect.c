/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:33:55 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/14 17:48:49 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersection	create_intersection(t_sphere s, t_ray r)
{
	t_intersection	i;

	ft_bzero((void *)&i, sizeof(t_intersection));
	if (tuples_eq(s.origin, (t_tuple){0, 0, 0, POINT}))
	{
		if (r.origin[Y] == 0)
		{
			i.count = 2;
			if (r.origin[X] == 0 && r.origin[Z] == 0)
				i.head = ft_lstnew(-s.radius);
			else
				i.head = ft_lstnew(ft_abs(r.origin[Z] + r.direction[Z]));
			ft_lstadd_back(&i.head, ft_lstnew(i.head->t + s.radius * 2));
		}
		else if (r.origin[Y] == 1 || r.origin[Y] == -1)
		{
			i.head = ft_lstnew(ft_abs(r.origin[Z] + r.direction[Z]) + s.radius);
			i.count = 1;
		}
		else
			i.count = 0;
		return (i);
	}
	return ((t_intersection){0});
}
