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
#include <stdio.h>

t_node	get_hit(t_intersection intersections)
{
	t_node	smallest;
	t_node	*node;

	smallest.object = NULL;
	node = intersections.head;
	if (node == NULL)
	{
		ft_lstfree(&intersections.head);
		return (smallest);
	}
	while (node != NULL)
	{
		if (node->t >= 0 && (smallest.object == NULL || node->t < smallest.t))
			smallest = *node;
		node = node->next;
	}
	if (smallest.object == NULL || smallest.t < 0)
	{
		ft_lstfree(&intersections.head);
		return (smallest);
	}
	ft_lstfree(&intersections.head);
	return (smallest);
}
