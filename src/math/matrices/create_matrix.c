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

#include "minirt.h"

static short	size_of_matrix(arr_mat arr_m);

t_matrix	create_identity_matrix(void)
{
	const t_matrix	mat = {
		.grid = {
	{1, 0, 0, 0},
	{0, 1, 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1},
	},
		.size = 4
	};

	return (mat);
}

t_matrix create_matrix (arr_mat arr_m)
{
	t_matrix new_matrix;
	new_matrix.size = size_of_matrix(arr_m);
	 if(!new_matrix.size)
		 exit(EXIT_FAILURE);
	return(new_matrix);
}

static short	size_of_matrix(arr_mat arr_m)
{
	const short size = sizeof(arr_m) / sizeof(int);
	if ((size / 4) == 4)
		return (4);
	if ((size / 3) == 3)
		return (3);
	if ((size / 2) == 2)
		return (2);
	else
		printf(RED"ERROR: incorrect matrix size\n"RESET)
		return (0);
}