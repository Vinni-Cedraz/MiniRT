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

#include "minirt.h"

static t_tuple *create_row_of_pixels(unsigned short width);

t_canvas create_canvas(unsigned short height, unsigned short width) {
    t_canvas canvas;

    canvas.width = width;
    canvas.height = height;
    canvas.pixels = malloc(sizeof(t_tuple *) * height);
    while (height) {
        canvas.pixels[height - 1] = create_row_of_pixels(width);
        height--;
    }
    return (canvas);
}

static t_tuple *create_row_of_pixels(unsigned short width) {
    t_tuple *pixels;

    pixels = malloc(sizeof(t_tuple) * width);
    while (width) {
        pixels[width - 1][R] = 0;
        pixels[width - 1][G] = 0;
        pixels[width - 1][B] = 0;
        pixels[width - 1][W] = COLOR;
        width--;
    }
    return (pixels);
}

void destroy_canvas(const t_canvas *canvas) {
    unsigned short height;

    height = canvas->height;
    while (height) {
        free(canvas->pixels[height - 1]);
        height--;
    }
    free(canvas->pixels);
}

// #include "../../tests/tester.h"
//
// Test(create_canvas, test_create_row_of_pixels,
//      .description = CYAN
//      "\n"
//      "Given a t_canvas with width of 550 a row of 550 t_tuples{0,0,0,COLOR}\n"
//      "Then create_row_of_pixels(550) returns a pointer to an array of 550 t_tuples "
//      "initialized to {0,0,0,COLOR} each\n" RESET) {
//
//     t_tuple *pixels;
// 	int		idx = -1;
//
//     pixels = create_row_of_pixels(550);
//     while (++idx < 550) {
//         cr_expect_tuple_eq(pixels[idx], (t_tuple){0, 0, 0, COLOR});
//     }
// }
