/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_matrices.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:20:44 by igenial           #+#    #+#             */
/*   Updated: 2024/05/07 21:20:46 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	mult_position_(t_matrix a, t_matrix b, int *i);

t_matrix	mult_matrices(t_matrix a, t_matrix b)
{
	t_matrix	result;
	int			row;
	int			col;

	row = -1;
	while (++row < a.size)
	{
		col = -1;
		while (++col < b.size)
			result.grid[row][col] = mult_position_(a, b, (int []){row, col});
	}
	result.size = a.size;
	return (result);
}

static double	mult_position_(t_matrix a, t_matrix b, int *i)
{
	double	result;
	int		index;

	result = 0;
	index = -1;
	while (++index < a.size)
		result += a.grid[i[ROW]][index] * b.grid[index][i[COL]];
	return (result);
}
