/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_canvas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:26:18 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/09/25 17:26:19 by vcedraz-         ###   ########.fr       */
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
		pixels[width - 1][R] = 0;
		pixels[width - 1][G] = 0;
		pixels[width - 1][B] = 0;
		pixels[width - 1][W] = COLOR;
		width--;
	}
	return (pixels);
}

void	destroy_canvas(t_canvas *canvas)
{
	unsigned short	height;

	height = canvas->height;
	while (height)
	{
		free(canvas->pixels[height - 1]);
		height--;
	}
	free(canvas->pixels);
}
