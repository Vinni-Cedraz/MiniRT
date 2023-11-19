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

static void	lst_add_intrscs(t_intersection *r, t_intersection *i, void **o);

t_intersection	intersect_world_with_ray(t_world *w, t_ray *r)
{
	int				count;
	t_intersection	intrsct;
	t_intersection	lst;
	void			*obj;
	void			**obj_ptr;

	count = 0;
	lst = (t_intersection){0};
	while (count != w->count)
	{
		intrsct = create_intersection(&w->objs[count], *r);
		if (intrsct.head)
		{
			obj = &w->objs[count];
			obj_ptr = (void **)&obj;
			lst_add_intrscs(&lst, &intrsct, obj_ptr);
		}
		count++;
	}
	return (lst);
}

static inline void	lst_add_intrscs( \
		t_intersection *lst, t_intersection *intrsct, void **obj_ptr)
{
	ft_lstadd_back(&lst->head, intersection(intrsct->head->t, obj_ptr));
	ft_lstadd_back(&lst->head, intersection(intrsct->head->next->t, obj_ptr));
}
