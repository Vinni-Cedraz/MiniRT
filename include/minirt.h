/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:09:38 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/09/25 18:26:25 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft_gnl/libft.h"
# include <math.h>

# define EPSILON 1e-6
# define X 0
# define Y 1
# define Z 2
# define R 0
# define G 1
# define B 2
# define W 3
# define VECTOR 0
# define POINT 1
# define COLOR 2
# define FALSE 0
# define TRUE 1


typedef float			t_tuple[4];
typedef unsigned short	t_bool;

typedef struct s_canvas {
	unsigned short	width;
	unsigned short	height;
	t_tuple			**pixels;
}				t_canvas;

void		create_point(t_tuple tuple);
void		create_vector(t_tuple tuple);
t_bool		compare_floats(float a, float b);
void		add_tuples(const t_tuple a, const t_tuple b, t_tuple result);
void		subtract_tuples(const t_tuple a, const t_tuple b, t_tuple result);
void		negate_tuple(const t_tuple a, t_tuple result);
void		multiply_tuple_by_scalar(const t_tuple a, const float s, t_tuple r);
void		multiply_colors(const t_tuple c1, const t_tuple c2, t_tuple result);
t_bool		compare_floats(float a, float b);
float		magnitude(const t_tuple vec);
short		normalize(const t_tuple vec, t_tuple result);
short		dot(const t_tuple a, const t_tuple b, float dot_product);
short		cross(const t_tuple a, const t_tuple b, t_tuple cross_product);
t_canvas	create_canvas(unsigned short width, unsigned short height);
void		write_pixel(t_canvas *canvas, int x, int y, t_tuple pixel);
char		*canvas_to_ppm(const t_canvas *canvas);
void		destroy_canvas(const t_canvas *canvas);

#endif
