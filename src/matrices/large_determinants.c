/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_determinants.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:45:12 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/04 17:52:57 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	_3x3determinant(t_3x3matrix m)
{
	return (m.row_1[X] * _3x3cofactor(m, 0, X)
		+ m.row_2[X] * _3x3cofactor(m, 1, X)
		+ m.row_3[X] * _3x3cofactor(m, 2, X));
}

float	_4x4determinant(t_matrix m)
{
	return (m.row_1[X] * _4x4cofactor(m, 0, X)
		+ m.row_2[X] * _4x4cofactor(m, 1, X)
		+ m.row_3[X] * _4x4cofactor(m, 2, X)
		+ m.row_4[X] * _4x4cofactor(m, 3, X));
}

float	_3x3cofactor(t_3x3matrix m, int row, int col)
{
	float	_minor;
	float	_cofactor;

	_minor = _3x3minor(m, row, col);
	_cofactor = _minor;
	if ((row + col) % 2)
		_cofactor = _minor * -1;
	return (_cofactor);
}

float	_4x4cofactor(t_matrix m, int row, int col)
{
	float	_minor;
	float	_cofactor;

	_minor = _4x4minor(m, row, col);
	_cofactor = _minor;
	if ((row + col) % 2)
		_cofactor = _minor * -1;
	return (_cofactor);
}
