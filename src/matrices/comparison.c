/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:42:53 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/01 16:54:09 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	matrices_eq(t_matrix a, t_matrix b)
{
	int	res;

	res = tuples_neq(a.row_1, b.row_1);
	res = tuples_neq(a.row_2, b.row_2);
	res = tuples_neq(a.row_3, b.row_3);
	res = tuples_neq(a.row_4, b.row_4);
	return (!res);
}

t_bool	tuples_neq(const t_tuple result, const t_tuple expected)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (!floats_eq(result[i], expected[i]))
			return (TRUE);
	}
	return (FALSE);
}

t_matrix	mult_by_identity(t_matrix a)
{
	const t_matrix	identity = {
		.row_1 = {1, 0, 0, 0},
		.row_2 = {0, 1, 0, 0},
		.row_3 = {0, 0, 1, 0},
		.row_4 = {0, 0, 0, 1},
	};

	return (mult_matrices(a, identity));
}
