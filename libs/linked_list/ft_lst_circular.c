/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_circular.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:08:11 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/08/18 15:08:12 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	ft_lst_circular(t_node **head)
{
	t_node	*tail;

	if (!head || !*head)
		return ;
	tail = *head;
	tail = ft_lstlast(*head);
	tail->next = *head;
}
