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

#include "minirt_bonus.h"

double	_minor(const t_matrix m, int row, int col)
{
	return (_determinant(_submatrix(m, row, col)));
}
