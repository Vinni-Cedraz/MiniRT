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

double	_3x3determinant(const t_matrix m)
{
	(void)m;
	return 0;
}

double	_4x4determinant(const t_matrix m)
{
	(void)m;
	return 0;
}

double	_3x3cofactor(const t_matrix m, int row, int col)
{
	double	_minor;
	double	_cofactor;

	_minor = _3x3minor(m, row, col);
	_cofactor = _minor;
	if ((row + col) % 2)
		_cofactor = _minor * -1;
	return (_cofactor);
}

double	_4x4cofactor(const t_matrix m, int row, int col)
{
	(void)m;
	(void)row;
	(void)col;
	return 0;
}
