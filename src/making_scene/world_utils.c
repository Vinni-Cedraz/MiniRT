/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:23:48 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/11/01 19:29:09 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_node	*lstnew_shape(t_sphere content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(*node));
	node->t = DEFAULT;
	node->shape = content;
	node->next = NULL;
	return (node);
}
