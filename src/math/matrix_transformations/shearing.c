/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:11:43 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/11 16:18:53 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	create_shearing_matrix(t_shearer s)
{
	return (create_4x4_matrix(&(t_matrix){
			.row_1 = {1, s.x_to_y, s.x_to_z, 0},
			.row_2 = {s.y_to_x, 1, s.y_to_z, 0},
			.row_3 = {s.z_to_x, s.z_to_y, 1, 0},
			.row_4 = {0, 0, 0, 1},
		}));
}
