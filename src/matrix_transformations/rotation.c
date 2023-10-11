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

t_matrix	create_x_rotation_matrix(float r)
{
	const t_matrix	res = (t_matrix){
		.row_1 = {1, 0, 0, 0},
		.row_2 = {0, cos(r), -sin(r), 0},
		.row_3 = {0, sin(r), cos(r), 0},
		.row_4 = {0, 0, 0, 1},
		.rows = {res.row_1, res.row_2, res.row_3, res.row_4
	}};

	return (res);
}
