/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:55:35 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/17 19:13:14 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

t_node	*get_hit(t_intersection intersection)
{
	t_node	*smallest;
	t_node	*node;

	smallest = NULL;
	node = intersection.head;
	if (node == NULL)
		return (NULL);
	while (node != NULL)
	{
		if (node->t >= 0 && (smallest == NULL || node->t < smallest->t))
			smallest = node;
		node = node->next;
	}
	if (smallest == NULL || smallest->t < 0)
		return (NULL);
	return (smallest);
}
