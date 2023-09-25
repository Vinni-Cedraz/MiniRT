/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:22:18 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/09/24 17:22:40 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static t_tuple	*create_row_of_pixels(unsigned short width);

t_canvas	create_canvas(unsigned short width, unsigned short height)
{
	t_canvas	canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.pixels = malloc(sizeof(t_tuple *) * height);
	while (height)
	{
		canvas.pixels[height - 1] = create_row_of_pixels(width);
		height--;
	}
	return (canvas);
}

static t_tuple	*create_row_of_pixels(unsigned short width)
{
	t_tuple	*pixels;

	pixels = malloc(sizeof(t_tuple) * width);
	while (width)
	{
		pixels[width - 1][R] = BLACK;
		pixels[width - 1][G] = BLACK;
		pixels[width - 1][B] = BLACK;
		pixels[width - 1][W] = COLOR;
		width--;
	}
	return (pixels);
}
