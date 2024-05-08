/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:10:02 by igenial           #+#    #+#             */
/*   Updated: 2024/05/07 21:10:05 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_transform(t_shape *s, t_matrix t)
{
	s->_t = t;
	s->inverse_t = invert_matrix(t);
	s->trans_inv = transpose_matrix(s->inverse_t);
}
