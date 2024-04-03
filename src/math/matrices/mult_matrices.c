/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_matrices.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:30:24 by johmatos          #+#    #+#             */
/*   Updated: 2023/10/03 11:48:35 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	mult_position_(t_matrix a, t_matrix b, int *i);
static double	multiply_row_col(double row[], double col[], int sz);

t_tuple	multiply_tuple_by_matrix(t_tuple a, t_matrix b)
{
	int				i;
	double			result[4];
	double			arr_tuple[4];

	i = -1;
	tuple_to_arr(a, arr_tuple);
	while (++i < 4)
		result[i] = multiply_row_col(b.grid[i], arr_tuple, b.size);
	return ((t_tuple){
		.x = result[X],
		.y = result[Y],
		.z = result[Z],
		.w = result[W]
	});
}

// Function to multiply a row and a column represented as arrays
static double	multiply_row_col(double row[], double col[], int sz)
{
	double	result;
	int		i;

	result = 0;
	i = -1;
	while (++i < sz)
	{
		result += row[i] * col[i];
	}
	return (result);
}

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
