/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_identity_matrix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:38:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2024/03/30 17:43:08 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

static void		init_grid(t_matrix *matrix, double *src_arr);
static short	count_mat_size(double *arr);

t_matrix	create_matrix(double arr[])
{
	t_matrix	res;

	res.size = count_mat_size(arr);
	init_grid(&res, arr);
	return (res);
}

short	count_mat_size(double *arr)
{
	short	size;
	int		sqrt_size;

	size = 0;
	while (*arr != END_MATRIX)
	{
		arr++;
		size++;
	}
	sqrt_size = sqrt(size);
	if (sqrt_size * sqrt_size == size && sqrt_size < 5)
		return (sqrt_size);
	else
	{
		printf(RED "Error: incorrect matrix size\n" RESET);
		exit(EXIT_FAILURE);
	}
}

int	_idx(int i, int j, int matrix_size)
{
	return (i * matrix_size + j);
}

void	init_grid(t_matrix *matrix, double *src_arr)
{
	int			i;
	int			j;
	const int	size = matrix->size;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			matrix->grid[i][j] = src_arr[_idx(i, j, size)];
	}
}

t_matrix	create_identity_matrix(void)
{
	const t_matrix	mat = create_matrix((double []){
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1,
			END_MATRIX
		});

	return (mat);
}
