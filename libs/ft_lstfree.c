/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:37:20 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/09 22:44:15 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_bonus.h"

void	ft_lstfree(t_node **list)
{
	t_node	*tmp;

	tmp = *list;
	if (list == NULL)
		return ;
	while (tmp)
	{
		*list = tmp->next;
		free(tmp);
		tmp = *list;
	}
	free(list);
}
