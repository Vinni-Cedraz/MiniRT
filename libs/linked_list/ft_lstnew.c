/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 00:24:02 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/16 16:14:57 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

t_node	*ft_lstnew(double content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(*node));
	node->t = content;
	node->next = NULL;
	return (node);
}
