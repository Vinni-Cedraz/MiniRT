/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:07:22 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/08 11:13:48 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	create_translation_matrix(t_tuple point)
{
	t_matrix	identity;

	identity = create_identity_matrix();
	identity.grid[0][3] = point.x;
	identity.grid[1][3] = point.y;
	identity.grid[2][3] = point.z;
	return (identity);
}
