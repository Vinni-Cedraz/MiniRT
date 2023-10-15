/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:48:44 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/05/07 12:18:55 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_bonus.h"

static inline size_t	aux_putchar(char c);
static inline size_t	aux_putstr(char *s);

void	ft_lstprint(t_node **lst)
{
	t_node	*tmp;

	if (!lst || !*lst)
	{
		if (!lst)
			aux_putstr("\n\n all nodes and list itself were already freed \n");
		else
			aux_putstr("\n\n empty list");
		return ;
	}
	tmp = *lst;
	while (tmp)
	{
		aux_putchar('-');
		aux_putchar('>');
		aux_putchar(' ');
		aux_putstr((char *)tmp->content);
		aux_putchar('\n');
		tmp = tmp->next;
	}
}

static inline size_t	aux_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (*(s + i))
		aux_putchar(*(s + i++));
	return (i);
}

static inline size_t	aux_putchar(char c)
{
	return (write(1, &c, 1));
}
