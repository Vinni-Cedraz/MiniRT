/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:06:25 by johmatos          #+#    #+#             */
/*   Updated: 2023/10/16 16:55:58 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"
#include "minirt.h"

t_node *intersection(float point, void *obj)
{
	t_node *lst;

	lst = ft_lstnew(point);
	lst->object = obj;
	return (lst);
}

t_intersection	create_intersections(t_node *x, t_node *y)
{
	t_intersection	i;

	i.head = intersection(x->t, x->object);
	ft_lstadd_back(&i.head, intersection(y->t, y->object));
	i.count = 2;
	return (i);
}

t_intersection	create_intersection(t_sphere s, t_ray r)
{
	t_intersection	i;

	ft_bzero((void *)&i, sizeof(t_intersection));
	if (r.origin[Y] == 0)
	{
		i.count = 2;
		if (r.origin[X] == 0 && r.origin[Z] == 0)
			i.head = intersection(-s.radius, &s);
		else if (r.origin[Z] < 0)
			i.head = intersection(ft_abs(r.origin[Z] + r.direction[Z]), &s);
		else if (r.origin[Z] > 0)
			i.head = intersection(-1 * (r.origin[Z] + r.direction[Z]), &s);
		ft_lstadd_back(&i.head, intersection(i.head->t + s.radius * 2, &s));
	}
	else if (r.origin[Y] == 1 || r.origin[Y] == -1)
	{
		i.head = intersection(ft_abs(r.origin[Z] + r.direction[Z]) + s.radius, &s);
		i.count = 1;
	}
	else
		i.count = 0;
	return (i);
}

float discriminant(t_tuple sphere_to_ray, t_ray ray)
{
	const float a = dot(ray.direction, ray.direction);
	const float b = 2 * dot(ray.direction, sphere_to_ray);
	const float c = dot(sphere_to_ray, sphere_to_ray) - 1;
	const float discriminant = pow(b, 2) - 4 * a * c;

	return (discriminant);
}
