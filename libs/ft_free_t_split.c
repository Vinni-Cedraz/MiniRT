/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_t_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:32:53 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/10 12:33:02 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	aux_free_arr(char **arr, void **aux);

void	ft_free_t_split(t_split *split)
{
	aux_free_arr(split->str_arr, (void **)split->str_arr);
	free(split);
}

static inline void	aux_free_arr(char **arr, void **aux)
{
	while (*arr)
		free(*arr++);
	free(aux);
}
