/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:23:50 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/11/19 17:23:53 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_node	_hit(t_intersections intersections)
{
	t_node			smallest;

	smallest.t = __INT_MAX__;
	smallest.object = NULL;
	while (intersections.head != NULL)
	{
		if(smallest.t > intersections.head->t && intersections.head->t > 0)
			smallest = *intersections.head;
		intersections.head = intersections.head->next;
	}
	return (smallest);
}
