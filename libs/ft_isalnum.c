/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:53:19 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/07 16:37:19 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int	aux_ft_isdigit(int c);
static inline int	aux_ft_isalpha(int c);

int	ft_isalnum(int c)
{
	return (aux_ft_isdigit(c) || aux_ft_isalpha(c));
}

static inline int	aux_ft_isalpha(int c)
{
	return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'));
}

static inline int	aux_ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}
