/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2x2determinant.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:39:54 by vcedraz-          #+#    #+#             */
/*   Updated: 2024/03/30 17:39:50 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	_2x2determinant(t_matrix m)
{
	double ad;
	double bc;

	ad = m.grid[0][0] * m.grid[1][1];
	bc = m.grid[1][0] * m.grid[0][1];
	return (ad - bc);
}
