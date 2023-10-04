/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:39:54 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/03 18:51:07 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	_2x2determinant(t_2x2matrix m)
{
	return (m.row_1[X] * m.row_2[Y] - m.row_2[X] * m.row_1[Y]);
}