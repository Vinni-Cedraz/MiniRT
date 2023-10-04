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

float	_2x2determinant(t_2x2matrix m)
{
	return (m.row_1[X] * m.row_2[Y] - m.row_2[X] * m.row_1[Y]);
}

float	_3x3determinant(t_3x3matrix m)
{
	return (m.row_1[X] * cofactor(m, 0, X)
		+ m.row_2[X] * cofactor(m, 1, X)
		+ m.row_3[X] * cofactor(m, 2, X));
}

float	minor(t_3x3matrix m, int row, int col)
{
	return (_2x2determinant(_3x3submatrix(m, row, col)));
}

float	cofactor(t_3x3matrix m, int row, int col)
{
	float	_minor;
	float	_cofactor;

	_minor = minor(m, row, col);
	_cofactor = _minor;
	if ((row + col) % 2)
		_cofactor = _minor * -1;
	return (_cofactor);
}
