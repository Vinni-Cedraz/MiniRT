/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 00:22:00 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/16 16:55:32 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_bonus.h"
#include <stdio.h>

void	ft_lstadd_back(t_node **lst, t_node *nw)
{
	t_node	*temp;

	if (!lst || !nw)
		return ;
	if (!*lst)
	{
		*lst = nw;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = nw;
	nw->next = NULL;
}
