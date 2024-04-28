/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:23:22 by johmatos          #+#    #+#             */
/*   Updated: 2023/11/28 12:16:49 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

#define MULTI 255

uint32_t	normalized_color_to_int(const t_tuple color)
{
	t_tuple	col;

	col = color;
	if (col.x > 1)
		col.x = 1;
	if (col.y > 1)
		col.y = 1;
	if (col.z > 1)
		col.z = 1;
	return (((uint32_t)(col.x * MULTI) << 24) | ((uint32_t)(col.y
				* MULTI) << 16) | ((uint32_t)(col.z * MULTI) << 8) | 0xff);
}

mlx_image_t	*create_image(mlx_t *mlx)
{
	return (mlx_new_image(mlx, SIZEW, SIZEH));
}

void	ft_mlx_draw_pixel(uint8_t *pixel, uint32_t color)
{
	*(pixel++) = (uint8_t)(color >> 24);
	*(pixel++) = (uint8_t)(color >> 16);
	*(pixel++) = (uint8_t)(color >> 8);
	*(pixel++) = (uint8_t)(color & 0xFF);
}
