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
	if (r.origin[Y] == 0)
	{
		i.count = 2;
		if (r.origin[X] == 0 && r.origin[Z] == 0)
			i.head = ft_lstnew(-s.radius);
		else if (r.origin[Z] < 0)
			i.head = ft_lstnew(ft_abs(r.origin[Z] + r.direction[Z]));
		else if (r.origin[Z] > 0)
			i.head = ft_lstnew(-1 * (r.origin[Z] + r.direction[Z]));
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

t_bool	discriminant(t_sphere s, t_ray r)
{
	const double a = dot(r.direction, r.direction);
	const double b = 2 * dot(r.direction, s.origin);
	const double c = dot(s.origin, s.origin) - 1;
	const double discriminant = pow(b, 2) - 4 * a * c;

	return (discriminant);
}
