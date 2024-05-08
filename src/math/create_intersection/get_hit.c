/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:11:17 by igenial           #+#    #+#             */
/*   Updated: 2024/05/07 21:11:19 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static _Bool	this_t_is_the_smallest_positive(double this_t, double smallest);

t_node	_hit(t_intersections lst)
{
	t_node	smallest;

	smallest.t = __INT_MAX__;
	smallest.shape = NULL;
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
