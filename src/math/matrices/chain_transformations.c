/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_transformations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:15:01 by igenial           #+#    #+#             */
/*   Updated: 2024/05/07 21:15:04 by igenial          ###   ########.fr       */
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
