/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:01:47 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/11 09:03:12 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	create_x_rotation_matrix(double r)
{
	t_matrix	identity;

	identity = create_identity_matrix();
	identity.grid[1][1] = cos(r);
	identity.grid[1][2] = -sin(r);
	identity.grid[2][1] = sin(r);
	identity.grid[2][2] = cos(r);
	return (identity);
}

t_matrix	create_y_rotation_matrix(double r)
{
	t_matrix	identity;

	identity = create_identity_matrix();
	identity.grid[0][0] = cos(r);
	identity.grid[0][2] = sin(r);
	identity.grid[2][0] = -sin(r);
	identity.grid[2][2] = cos(r);
	return (identity);
}

t_matrix	create_z_rotation_matrix(double r)
{
	t_matrix	identity;

	identity = create_identity_matrix();
	identity.grid[0][0] = cos(r);
	identity.grid[0][1] = -sin(r);
	identity.grid[1][0] = sin(r);
	identity.grid[1][1] = cos(r);
	return (identity);
}
