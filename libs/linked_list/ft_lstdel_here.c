/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_here.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:41:15 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/09 17:11:26 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

// if not at the top of the list unlinks and frees a node at a given index
void	ft_lstdel_here(t_node **lst, uint index)
{
	t_node	*prev;
	t_node	*here;

	prev = NULL;
	here = *lst;
	while (here)
	{
		if (!index--)
			break ;
		prev = here;
		here = here->next;
	}
	if (!here || !prev)
		return ;
	prev->next = here->next;
	free(here);
}
