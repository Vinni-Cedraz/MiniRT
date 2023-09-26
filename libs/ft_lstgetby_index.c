/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetby_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:14:22 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/09 21:17:58 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

t_node	*ft_lstgetby_index(t_node *lst, uint index)
{
	if (!index)
		return (NULL);
	while (lst)
	{
		if (!index--)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
