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

float	_3x3minor(t_3x3matrix m, int row, int col)
{
	return (_2x2determinant(_3x3submatrix(m, row, col)));
}

float	_4x4minor(t_matrix m, int row, int col)
{
	return (_3x3determinant(_4x4submatrix(m, row, col)));
}
