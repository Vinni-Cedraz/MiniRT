/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetby_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:22:44 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/12 15:02:29 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_bonus.h"

int	ft_lstgetby_content(t_node *lst, void *content)
{
	uint	index;

	index = 0;
	if (!lst || !content)
		return (-1);
	while (lst)
	{
		if (!ft_memcmp(lst->content, content, sizeof(content)))
			return (index);
		lst = lst->next;
		index++;
	}
	return (-1);
}
