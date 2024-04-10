/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:22:57 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/11/19 17:23:16 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"
#include "minirt.h"

void link_intersection_nodes(t_node *head1, t_node *head2)
{
	ft_lstadd_back(&head1, head2);
}
