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

t_intersection	link_intersection_nodes(t_node *arr[])
{
	t_intersection	i;
	int idx;

	idx = 0;
	while (arr[idx] != NULL)
	{
		if (idx == 0)
			i.head = arr[idx];
		else
			ft_lstadd_back(&i.head, arr[idx]);
		idx++;
	}
	i.count = idx;
	return (i);
}

t_intersection	create_intersection(t_sphere s, t_ray r)
{
	t_intersection	i;
	float 			dis;
	t_tuple			sphere_to_ray;
	t_baskara		bask;

	r = transform_ray(r, s.inverse_t);
	subtract_tuples(r.origin, s.origin, sphere_to_ray);
	dis = discriminant(sphere_to_ray, r, &bask);
	if (dis < 0)
	{
		i.count = 0;
		i.head = NULL;
		return i;
	}
	i.head = intersection((((bask.b * -1) - sqrt(dis)) / (2 * bask.a)), &s);
	i.head->next = intersection((((bask.b * -1) + sqrt(dis)) / (2 * bask.a)), &s);
	return (i);
}

float discriminant(t_tuple sphere_to_ray, t_ray ray, t_baskara *bask)
{
	bask->a = dot(ray.direction, ray.direction);
	bask->b = 2 * dot(ray.direction, sphere_to_ray);
	bask->c = dot(sphere_to_ray, sphere_to_ray) - 1;
	const float discriminant = pow(bask->b, 2) - 4 * bask->a * bask->c;

	return (discriminant);
}
