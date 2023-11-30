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

float	_3x3determinant(const t_3x3matrix m)
{
	return (m.row_1[COL1] * _3x3cofactor(m, ROW1, COL1)
		+ m.row_2[COL1] * _3x3cofactor(m, ROW2, COL1)
		+ m.row_3[COL1] * _3x3cofactor(m, ROW3, COL1));
}

float	_4x4determinant(const t_matrix m)
{
	return (m.row_1[COL1] * _4x4cofactor(m, ROW1, COL1)
		+ m.row_2[COL1] * _4x4cofactor(m, ROW2, COL1)
		+ m.row_3[COL1] * _4x4cofactor(m, ROW3, COL1)
		+ m.row_4[COL1] * _4x4cofactor(m, ROW4, COL1));
}

float	_3x3cofactor(const t_3x3matrix m, int row, int col)
{
	float	_minor;
	float	_cofactor;

	_minor = _3x3minor(m, row, col);
	_cofactor = _minor;
	if ((row + col) % 2)
		_cofactor = _minor * -1;
	return (_cofactor);
}

float	_4x4cofactor(const t_matrix m, int row, int col)
{
	float	_minor;
	float	_cofactor;

	_minor = _4x4minor(m, row, col);
	_cofactor = _minor;
	if ((row + col) % 2)
		_cofactor = _minor * -1;
	return (_cofactor);
}
