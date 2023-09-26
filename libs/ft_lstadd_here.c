/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_here.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:23:27 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/09 17:09:39 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

t_node	*ft_lstadd_here(t_node **lst, t_node *new, uint index)
{
	t_node	*old;

	old = *lst;
	if (!index)
		return (NULL);
	while (old)
	{
		if (!--index)
			break ;
		old = old->next;
	}
	if (!old)
		return (NULL);
	new->next = old->next;
	old->next = new;
	return (new);
}
