/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:39:56 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/05/07 15:38:17 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

t_node	*ft_lstpop(t_node **head)
{
	t_node	*new_head;

	if (!head || !*head || !(*head)->next)
		return (*head);
	new_head = (*head)->next;
	free(*head);
	*head = new_head;
	return (new_head);
}
