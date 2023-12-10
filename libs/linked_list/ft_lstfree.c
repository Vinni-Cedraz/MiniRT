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

#include "../libft_bonus.h"

void	ft_lstfree(t_node **list)
{
	if (!list || !*list)
		return ;
	ft_lstfree(&((*list)->next));
	free(*list);
	*list = NULL;
}
