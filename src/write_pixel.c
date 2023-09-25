/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:26:32 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/09/25 17:30:44 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	write_pixel(t_canvas *canvas, int x, int y, t_tuple pixel)
{
	canvas->pixels[x][y][R] = pixel[R];
	canvas->pixels[x][y][G] = pixel[G];
	canvas->pixels[x][y][B] = pixel[B];
}
