/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:46:15 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/04 17:46:20 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	_3x3minor(const t_matrix m, int row, int col)
{
	return (_2x2determinant(_submatrix(m, row, col)));
}

double	_4x4minor(const t_matrix m, int row, int col)
{
	(void)m;
	(void)row;
	(void)col;
	return 0;
}
