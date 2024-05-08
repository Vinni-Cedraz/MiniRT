/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_world_with_ray.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:39:02 by vcedraz-          #+#    #+#             */
/*   Updated: 2024/04/11 03:57:14 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersections	intersect_world_with_ray(t_world *w, t_ray *r)
{
	t_intersections	result;
	t_intersections	tmp;
	int				idx;

	idx = 0;
	result.head = NULL;
	while (idx < w->fixed_count)
	{
		tmp = intersect_shape(&w->shapes[idx], r);
		ft_lstadd_back(&result.head, tmp.head);
		idx++;
	}
	result.count = w->fixed_count * 2;
	return (result);
}

// static void	insertion_sort(t_node **head_ref)
// {
// 	t_node	*sorted;
// 	t_node	*current;
// 	t_node	*next;
//
// 	sorted = NULL;
// 	current = *head_ref;
// 	while (current != NULL)
// 	{
// 		next = current->next;
// 		sorted_insert(&sorted, current);
// 		current = next;
// 	}
// 	*head_ref = sorted;
// }
//
// static void	sorted_insert(t_node **head_ref, t_node *new_node)
// {
// 	t_node	*current;
//
// 	if (*head_ref == NULL || (*head_ref)->t >= new_node->t)
// 	{
// 		new_node->next = *head_ref;
// 		*head_ref = new_node;
// 	}
// 	else
// 	{
// 		current = *head_ref;
// 		while (current->next != NULL && current->next->t < new_node->t)
// 		{
// 			current = current->next;
// 		}
// 		new_node->next = current->next;
// 		current->next = new_node;
// 	}
// }
