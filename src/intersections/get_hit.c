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

t_node	*get_hit(t_intersection i)
{
	t_node	*smallest;

	smallest = i.head;
	while (i.head)
	{
		if (smallest->t < i.head->t)
			smallest = i.head;
		i.head = i.head->next;
	}
	if (smallest < 0)
		return (NULL);
	return (smallest);
}
