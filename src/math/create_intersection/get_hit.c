/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:23:50 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/11/19 17:23:53 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static _Bool	this_t_is_the_smallest_positive(double this_t, double smallest);

t_node	_hit(t_intersections lst)
{
	t_node	smallest;

	smallest.t = __INT_MAX__;
	smallest.object = NULL;
	while (lst.head)
	{
		if (this_t_is_the_smallest_positive(lst.head->t, smallest.t))
			smallest = *lst.head;
		lst.head = lst.head->next;
	}
	return (smallest);
}

static _Bool	this_t_is_the_smallest_positive(double this_t,
		double smallest_t)
{
	return (this_t < smallest_t && this_t > 0);
}
