/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:22:57 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/11/19 17:23:16 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"
#include "minirt.h"

t_intersection	create_intersection(void *obj, t_ray r)
{
	t_tuple						obj_dist_to_ray;
	const t_shape				*shape = obj;
	const t_intersect_function	intersect_shape[3] = {
		intersect_sphere, intersect_plane, intersect_cylinder
	};

	r = transform_ray(r, shape->inverse_t);
	subtract_tuples(r.origin, shape->origin, obj_dist_to_ray);
	return (intersect_shape[shape->type]((void **)&shape, obj_dist_to_ray, r));
}

t_intersection	link_intersection_nodes(t_node *arr[])
{
	t_intersection	i;
	int				idx;

	idx = 0;
	ft_bzero((void *)&i, sizeof(t_intersection));
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

t_node	*intersection(float point, void **obj)
{
	t_node	*lst;

	lst = ft_lstnew(point);
	lst->object = *obj;
	return (lst);
}
