/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcircular_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 00:12:11 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/26 00:39:21 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_bonus.h"

void	ft_lstcircular_free(t_node **head)
{
	t_node	*current;
	t_node	*temp;

	if (!head || !*head)
		return ;
	current = *head;
	temp = current->next;
	while (temp != *head)
	{
		free(current);
		current = temp;
		temp = temp->next;
	}
	free(current);
	*head = NULL;
}
