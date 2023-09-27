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

void	write_pixel(t_canvas *canvas, int y, int x, const t_tuple pixel)
{
	canvas->pixels[y][x][R] = pixel[R];
	canvas->pixels[y][x][G] = pixel[G];
	canvas->pixels[y][x][B] = pixel[B];
}
