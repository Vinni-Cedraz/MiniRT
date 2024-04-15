/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_transformations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 06:58:03 by vcedraz-          #+#    #+#             */
/*   Updated: 2024/04/03 06:58:19 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			size_array(t_matrix m[]);

t_matrix	chain_transformations(t_matrix matrices[])
{
	t_matrix	result;
	int			size;

	size = size_array(matrices);
	if (size == 1)
		return (matrices[size - 1]);
	result = mult_matrices(chain_transformations(matrices + 1), matrices[0]);
	return (result);
}

int	size_array(t_matrix m[])
{
	int				i;
	const t_matrix	end = create_identity_matrix();

	i = 0;
	while (!matrices_eq(m[i], end))
		i++;
	return (i);
}
