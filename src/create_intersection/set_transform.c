/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:30:45 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/11/19 17:29:55 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_transform(t_shape *s, t_matrix t)
{
	s->_t = t;
	s->inverse_t = invert_matrix(t);
	s->transposed_inverse_t = transpose_matrix(s->inverse_t);
}
