/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:09:38 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/10/16 16:41:51 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "libft.h"
# include "libft_bonus.h"
# include <math.h>
# include <stdio.h>

# define EPSILON 1e-3
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
# define COL1 0
# define COL2 1
# define COL3 2
# define COL4 3
# define ROW1 0
# define ROW2 1
# define ROW3 2
# define ROW4 3

typedef float			t_tuple[4];
typedef float			t_3x3_row[3];
typedef float			t_2x2_row[2];
typedef _Bool			t_bool;
typedef unsigned short	t_short;

typedef enum e_num {
	SPHERE,
} t_enum;

typedef struct s_canvas
{
	unsigned short		width;
	unsigned short		height;
	t_tuple				**pixels;
}						t_canvas;

typedef struct s_matrix
{
	t_tuple				row_1;
	t_tuple				row_2;
	t_tuple				row_3;
	t_tuple				row_4;
	const float			*rows[4];
}						t_matrix;

typedef struct s_2x2matrix
{
	t_2x2_row			row_1;
	t_2x2_row			row_2;
	const float			*rows[2];
}						t_2x2matrix;

typedef struct s_3x3matrix
{
	t_3x3_row			row_1;
	t_3x3_row			row_2;
	t_3x3_row			row_3;
	const float			*rows[3];
}						t_3x3matrix;

typedef struct s_hearer
{
	float				x_to_y;
	float				x_to_z;
	float				y_to_x;
	float				y_to_z;
	float				z_to_x;
	float				z_to_y;
}						t_shearer;

typedef struct s_ray
{
	t_tuple				direction;
	t_tuple				origin;
}						t_ray;

typedef struct s_phere
{
	unsigned short		id;
	int					type;
	t_tuple				origin;
	t_short				radius;
}						t_sphere;

typedef struct s_intersect
{
	t_node				*head;
	t_short				count;
}						t_intersection;

void					create_point(t_tuple tuple);
void					create_vector(t_tuple tuple);
t_bool					floats_eq(float a, float b);
void					add_tuples(const t_tuple a, const t_tuple b,
							t_tuple result);
void					subtract_tuples(const t_tuple a, const t_tuple b,
							t_tuple result);
void					negate_tuple(const t_tuple a, t_tuple result);
void					multiply_tuple_by_scalar(const t_tuple a, const float s,
							t_tuple r);
void					multiply_tuple_by_matrix(t_tuple row, t_matrix m,
							t_tuple res);
void					multiply_colors(const t_tuple c1, const t_tuple c2,
							t_tuple result);
t_bool					floats_eq(float a, float b);
float					magnitude(const t_tuple vec);
short					normalize(const t_tuple vec, t_tuple result);
short					cross(const t_tuple a, const t_tuple b,
							t_tuple cross_product);
t_canvas				create_canvas(unsigned short height,
							unsigned short width);
void					write_pixel(t_canvas *canvas, int y, int x,
							const t_tuple pixel);
char					*canvas_to_ppm(const t_canvas *canvas);
void					destroy_canvas(const t_canvas *canvas);
t_matrix				mult_matrices(t_matrix a, t_matrix b);
t_bool					matrices_eq(t_matrix a, t_matrix b);
float					dot(const t_tuple a, const t_tuple b);
t_matrix				mult_by_identity(t_matrix a);
t_matrix				transpose_matrix(t_matrix a);
float					_2x2determinant(const t_2x2matrix m);
t_2x2matrix				_3x3submatrix(const t_3x3matrix m, int not_row,
							int col_to_delete);
t_bool					tuples_neq(const t_tuple result, const t_tuple expected,
							int len);
t_bool					_3x3matrices_eq(t_3x3matrix a, t_3x3matrix b);
t_bool					_2x2matrices_eq(t_2x2matrix a, t_2x2matrix b);
t_3x3matrix				_4x4submatrix(const t_matrix m, int not_row,
							int not_col);
float					_3x3minor(const t_3x3matrix m, int row, int col);
float					_3x3cofactor(const t_3x3matrix m, int row, int col);
float					_3x3determinant(const t_3x3matrix m);
float					_4x4determinant(const t_matrix m);
float					_3x3minor(const t_3x3matrix m, int row, int col);
float					_4x4minor(const t_matrix m, int row, int col);
float					_3x3cofactor(const t_3x3matrix m, int row, int col);
float					_4x4cofactor(const t_matrix m, int row, int col);
t_bool					is_invertible(const t_matrix m);
t_matrix				invert_matrix(const t_matrix m);
t_matrix				create_4x4_matrix(t_matrix *m);
t_3x3matrix				create_3x3_matrix(t_3x3matrix *m);
t_2x2matrix				create_2x2_matrix(t_2x2matrix *m);
t_matrix				create_translation_matrix(t_tuple point);
t_matrix				create_matrix_of_cofactors(const t_matrix m);
t_matrix				create_x_rotation_matrix(float r);
t_matrix				create_y_rotation_matrix(float r);
t_matrix				create_z_rotation_matrix(float r);
t_matrix				create_scaling_matrix(const float x, const float y,
							const float z);
t_matrix				create_shearing_matrix(t_shearer shearer);
t_matrix				chain_transformations(const t_matrix *matrices[]);
void					translate_coordinate(t_tuple point, t_canvas *canvas,
							t_tuple res);
void					get_point_from_distance(t_ray ray, float distance,
							t_tuple _result);
t_ray					create_ray(t_tuple origin, t_tuple direction);
t_sphere				create_sphere(void);
t_bool					tuples_eq(const t_tuple result, const t_tuple expected);
t_intersection			create_intersection(t_sphere s, t_ray r);
float					discriminant(t_tuple sphere_to_ray, t_ray r);
t_node 					*intersection(float point, void *obj);
t_intersection			create_intersections(t_node *x, t_node *y);

#endif
