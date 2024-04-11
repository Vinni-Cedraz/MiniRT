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

static void insertionSort(t_node **head_ref);
static void sortedInsert(t_node **head_ref, t_node *new_node);

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
		//printf("%f\n", tmp.head->next->t);
		idx++;
	}
	result.count = w->count * 2;
	insertionSort(&result.head);
	return (result);
}
static void insertionSort(t_node **head_ref) {
	t_node *sorted = NULL;
	t_node *current = *head_ref;
	while (current != NULL) {
		t_node *next = current->next;
		sortedInsert(&sorted, current);
		current = next;
	}
	*head_ref = sorted;
}

static void sortedInsert(t_node **head_ref, t_node *new_node) {
	t_node *current;
	if (*head_ref == NULL || (*head_ref)->t >= new_node->t) {
		new_node->next = *head_ref;
		*head_ref = new_node;
	} else {
		current = *head_ref;
		while (current->next != NULL && current->next->t < new_node->t) {
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}
}
