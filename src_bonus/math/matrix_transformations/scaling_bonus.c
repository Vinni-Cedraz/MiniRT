/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:25:48 by johmatos          #+#    #+#             */
/*   Updated: 2023/10/11 19:27:29 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_matrix	create_scaling_matrix(double x, double y, double z)
{
	t_matrix	identity;

	identity = create_identity_matrix();
	identity.grid[0][0] = x;
	identity.grid[1][1] = y;
	identity.grid[2][2] = z;
	return (identity);
}
