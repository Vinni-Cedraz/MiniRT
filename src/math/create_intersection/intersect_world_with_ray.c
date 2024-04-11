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

static void	insertion_sort(t_node **head_ref);
static void	sorted_insert(t_node **head_ref, t_node *new_node);

t_intersections	intersect_world_with_ray(t_world *w, t_ray *r)
{
	t_intersections	result;
	t_intersections	tmp;
	int				idx;

	idx = 0;
	result.head = NULL;
	tmp = intersect_sphere(&w->objs[0], *r);
	while (idx < w->count)
	{
		tmp = intersect_sphere(&w->objs[idx], *r);
		ft_lstadd_back(&result.head, tmp.head);
		idx++;
	}
	result.count = w->count * 2;
	insertion_sort(&result.head);
	return (result);
}

static void	insertion_sort(t_node **head_ref)
{
	t_node	*sorted;
	t_node	*current;
	t_node	*next;

	sorted = NULL;
	current = *head_ref;
	while (current != NULL)
	{
		next = current->next;
		sorted_insert(&sorted, current);
		current = next;
	}
	*head_ref = sorted;
}

static void	sorted_insert(t_node **head_ref, t_node *new_node)
{
	t_node	*current;

	if (*head_ref == NULL || (*head_ref)->t >= new_node->t)
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else
	{
		current = *head_ref;
		while (current->next != NULL && current->next->t < new_node->t)
		{
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}
}
