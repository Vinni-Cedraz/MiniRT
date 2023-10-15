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
	t_intersection	inter;
	int				value;

	value = 0;
	if (tuples_eq(s.origin, (t_tuple){0, 0, 0, POINT}))
	{
		if (r.origin[Y] == 0)
		{
			value = ft_abs(r.origin[Z] + r.direction[Z]);
			inter.head = ft_lstnew(value);
			inter.count = 2;
			value += (s.radius * 2);
			ft_lstadd_back(&inter.head, ft_lstnew(value));
		}
		else if (r.origin[Y] == 1 || r.origin[Y] == -1)
		{
			value = ft_abs(r.origin[Z] + r.direction[Z]) + s.radius;
			inter.head = ft_lstnew(value);
			inter.count = 1;
		}
		else
			inter.count = 0;
		return (inter);
	}
	return ((t_intersection){0});
}
