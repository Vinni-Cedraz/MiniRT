/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:24:49 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/03 16:27:15 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_matrix	transpose_matrix(t_matrix m)
{
	const t_matrix	ma = create_matrix((double []){
			m.grid[0][0], m.grid[1][0], m.grid[2][0], m.grid[3][0],
			m.grid[0][1], m.grid[1][1], m.grid[2][1], m.grid[3][1],
			m.grid[0][2], m.grid[1][2], m.grid[2][2], m.grid[3][2],
			m.grid[0][3], m.grid[1][3], m.grid[2][3], m.grid[3][3],
			END_MATRIX
		});

	return (ma);
}
