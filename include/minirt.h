/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:09:38 by vcedraz-          #+#    #+#             */
/*   Updated: 2024/03/24 17:35:30 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libs/libft.h"
# include "../libs/libft_bonus.h"
# include <math.h>
# include <stdint.h>
# include <stdio.h>

# define CYAN "\033[36m"
# define EPSILON 1e-5
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

# define DEFAULT -1
# define AMBIENT 0
# define DIFFUSE 1
# define SPECULAR 2
# define SHININESS 3

# define ROW1 0
# define ROW2 1
# define ROW3 2
# define ROW4 3

# define SIZEH 500
# define SIZEW 500

typedef double			t_four_doubles[4];
typedef double			t_3x3_row[3];
typedef double			t_2x2_row[2];
typedef _Bool			t_bool;
typedef unsigned short	t_short;
typedef					void(t_parse_table)(char *, t_node *);

typedef enum e_num
{
	SPHERE,
	PLANE,
	CYLINDER,
}						t_enum;

typedef struct s_tuple
{
	float				x;
	float				y;
	float				z;
	short				w;
}						t_tuple;

typedef struct s_canvas
{
	unsigned short		width;
	unsigned short		height;
	unsigned short		size;
	t_four_doubles		**pixels;
}						t_canvas;

typedef struct s_matrix
{
	t_tuple				row_1;
	t_tuple				row_2;
	t_tuple				row_3;
	t_tuple				row_4;
	double				*rows[4];
}						t_matrix;

typedef struct s_2x2matrix
{
	t_2x2_row			row_1;
	t_2x2_row			row_2;
	double				*rows[2];
}						t_2x2matrix;

typedef struct s_3x3matrix
{
	t_3x3_row			row_1;
	t_3x3_row			row_2;
	t_3x3_row			row_3;
	double				*rows[3];
}						t_3x3matrix;

typedef struct s_hearer
{
	double				x_to_y;
	double				x_to_z;
	double				y_to_x;
	double				y_to_z;
	double				z_to_x;
	double				z_to_y;
}						t_shearer;

typedef struct s_ray
{
	t_tuple				origin;
	t_tuple				direction;
}						t_ray;

typedef struct s_point_light
{
	t_tuple				position;
	t_tuple				intensity;
}						t_point_light;

typedef struct s_material
{
	double				ambient;
	double				diffuse;
	double				specular;
	double				shininess;
	t_tuple				color;
}						t_material;

typedef struct s_colors
{
	t_tuple				diffuse;
	t_tuple				reflectv;
	t_tuple				true_colr;
	t_tuple				lightv;
	t_tuple				ambient;
	t_tuple				specular;
}						t_colors;

typedef struct s_lighting
{
	t_material			material;
	t_point_light		light;
	t_tuple				position;
	t_tuple				eye_vec;
	t_tuple				normal_vec;
	t_bool				in_shadow;
}						t_lighting;

typedef struct s_intersect
{
	t_node				*head;
	t_short				count;
}						t_intersection;

typedef struct s_shape
{
	unsigned short		id;
	int					type;
	t_tuple				origin;
	t_matrix			_t;
	t_matrix			inverse_t;
	t_matrix			transposed_inverse_t;
	t_material			material;
	double				min;
	double				max;
	t_bool				closed;
	t_ray				r;
}						t_shape;

typedef struct s_phere
{
	unsigned short		id;
	int					type;
	t_tuple				origin;
	t_matrix			_t;
	t_matrix			inverse_t;
	t_matrix			transposed_inverse_t;
	t_material			material;
	double				min;
	double				max;
	t_bool				closed;
	t_ray				r;
}						t_sphere;

typedef struct s_plane
{
	unsigned short		id;
	int					type;
	t_tuple				origin;
	t_matrix			_t;
	t_matrix			inverse_t;
	t_matrix			transposed_inverse_t;
	t_material			material;
	double				min;
	double				max;
	t_bool				closed;
	t_ray				r;
}						t_plane;

typedef struct s_cylinder
{
	unsigned short		id;
	int					type;
	t_tuple				origin;
	t_matrix			_t;
	t_matrix			inverse_t;
	t_matrix			transposed_inverse_t;
	t_material			material;
	double				min;
	double				max;
	t_bool				closed;
	t_ray				r;
}						t_cylinder;

typedef struct s_world
{
	t_shape				*objs;
	t_point_light		*light;
	int					count;
}						t_world;

typedef struct s_baskara
{
	double				a;
	double				b;
	double				c;
	double				t0;
	double				t1;
}						t_baskara;

typedef struct s_comp
{
	double				t;
	t_shape				*object;
	t_tuple				over_point;
	t_tuple				point;
	t_tuple				eyev;
	t_tuple				normalv;
	t_bool				inside;
}						t_prep_comps;

typedef struct s_camera
{
	double				hsize;
	double				vsize;
	double				half_width;
	double				half_height;
	double				field_of_view;
	t_matrix			transform;
	double				pixel_size;
	double				xoffset;
	double				yoffset;
	double				world_x;
	double				world_y;
}						t_camera;

typedef t_intersection	(*t_intersect_function)(t_shape **, t_tuple);
typedef void			(*t_normal_at_function)(const t_shape *, const t_tuple,
				t_tuple);

t_tuple					create_point(float x, float y, float z);
t_tuple					create_vector(float x, float y, float z);
t_tuple					create_tuple(float x, float y, float z, short w);
t_bool					doubles_eq(double a, double b);
t_tuple					add_tuples(const t_tuple a, const t_tuple b);
t_tuple					subtract_tuples(const t_tuple a, const t_tuple b);
t_tuple					negate_tuple(const t_tuple a);
t_tuple					multiply_tuple_by_scalar(const t_tuple a, const double scalar);
void					multiply_tuple_by_matrix(const t_tuple row, t_matrix m, t_tuple res);
void					multiply_colors(const t_tuple c1, const t_tuple c2,
							t_tuple result);
t_bool					doubles_eq(double a, double b);
double					magnitude(const t_tuple vec);
short					normalize(const t_tuple vec, t_tuple result);
short					cross(const t_tuple a, const t_tuple b,
							t_tuple cross_product);
t_canvas				create_canvas(unsigned short height,
							unsigned short width);
void					write_pixel(t_canvas *canvas, int y, int x,
							const t_four_doubles pixel);
char					*canvas_to_ppm(const t_canvas *canvas);
void					destroy_canvas(const t_canvas *canvas);
t_matrix				mult_matrices(t_matrix a, t_matrix b);
t_bool					matrices_eq(t_matrix a, t_matrix b);
double					dot(const t_tuple a, const t_tuple b);
t_matrix				mult_by_identity(t_matrix a);
t_matrix				transpose_matrix(t_matrix a);
double					_2x2determinant(const t_2x2matrix m);
t_2x2matrix				_3x3submatrix(const t_3x3matrix m, int row_to_delete,
							int col_to_delete);
t_bool					tuples_neq(const double *result, const double *expected,
							int len);
t_bool					_3x3matrices_eq(t_3x3matrix a, t_3x3matrix b);
t_bool					_2x2matrices_eq(t_2x2matrix a, t_2x2matrix b);
t_3x3matrix				_4x4submatrix(const t_matrix m, int not_row,
							int not_col);
double					_3x3minor(const t_3x3matrix m, int row, int col);
double					_3x3cofactor(const t_3x3matrix m, int row, int col);
double					_3x3determinant(const t_3x3matrix m);
double					_4x4determinant(const t_matrix m);
double					_3x3minor(const t_3x3matrix m, int row, int col);
double					_4x4minor(const t_matrix m, int row, int col);
double					_3x3cofactor(const t_3x3matrix m, int row, int col);
double					_4x4cofactor(const t_matrix m, int row, int col);
t_bool					is_invertible(const t_matrix m);
t_matrix				invert_matrix(const t_matrix m);
t_matrix				create_4x4_matrix(t_matrix *m);
t_3x3matrix				create_3x3_matrix(t_3x3matrix *m);
t_2x2matrix				create_2x2_matrix(t_2x2matrix *m);
t_matrix				create_translation_matrix(t_tuple point);
t_matrix				create_matrix_of_cofactors(const t_matrix m);
t_matrix				create_x_rotation_matrix(double r);
t_matrix				create_y_rotation_matrix(double r);
t_matrix				create_z_rotation_matrix(double r);
t_matrix				create_scaling_matrix(const double x, const double y,
							const double z);
t_matrix				create_shearing_matrix(t_shearer shearer);
t_matrix				chain_transformations(t_matrix *matrices[]);
void					translate_coordinate(t_four_doubles point,
							t_canvas *canvas, t_four_doubles res);
void					get_position(t_ray ray, double distance,
							t_tuple _result);
t_ray					create_ray(t_tuple origin, t_tuple direction);
t_sphere				create_sphere(void);
t_bool					tuples_eq(const t_tuple result, const t_tuple expected);
t_intersection			create_intersection(void *shape, t_ray r);
t_intersection			link_intersection_nodes(t_node *arr[]);
t_node					get_hit(t_intersection i);
t_matrix				create_identity_matrix(void);
t_ray					transform_ray(t_ray ray, t_matrix matrix);
void					set_transform(t_shape *s, t_matrix t);
void					sphere_normal_at(const t_shape *sphere, const t_tuple p,
							t_tuple res);
void					plane_normal_at(const t_shape *sphere, const t_tuple p,
							t_tuple res);
void					cylinder_normal_at(const t_shape *cyl, const t_tuple p,
							t_tuple res);
void					reflect(t_tuple vector, t_tuple normal,
							t_tuple _return);
t_material				create_material(void);
void					calculate_lighting(t_lighting *obj, t_tuple result);
t_constr				make_aslib_test(void);
t_world					create_world(void);
t_world					default_world(void);
void					set_material(t_tuple reflections, t_tuple color,
							t_material *m);
t_intersection			intersect_world_with_ray(t_world *w, t_ray *r);
t_prep_comps			prepare_computations(t_node *intersection, t_ray ray);
void					shade_hit(t_world *world, t_prep_comps *comps,
							t_tuple result);
void					init_tuple(const t_tuple tuple, t_tuple res);
void					color_at(t_world *world, t_ray *ray, t_tuple color);
t_matrix				view_transform(t_tuple from, t_tuple forward,
							t_tuple up);
t_camera				create_camera(int hsize, int vsize,
							double field_of_view);
t_ray					ray_for_pixel(t_camera c, int x, int y);
t_canvas				render(t_camera camera, t_world world);
t_intersection			intersect_sphere(t_shape **obj, t_tuple dist);
t_intersection			intersect_plane(t_shape **obj, t_tuple dist);
t_intersection			intersect_cylinder(t_shape **obj,
							t_tuple obj_dist_to_ray);
t_plane					create_plane(void);
t_cylinder				create_cylinder(void);
double					discriminant(t_tuple obj_dist_ray, t_ray ray,
							t_baskara *bask);
void					set_cyl_min_max(t_cylinder *cyl, double min,
							double max);
void					load_objs_into_world(mlx_image_t *image,
							t_camera camera, t_world *world);
mlx_image_t				**get_image_to_render(mlx_t *mlx);
void					render_a_default_world(mlx_t *mlx);
int						endwith(char *str, char *end);
void					parse_sphere(char *str, t_node *head);
void					parse_plane(char *str, t_node *head);
void					parse_light(char *str, t_node *head);
void					parse_cylinder(char *str, t_node *head);
t_parse_table			**get_parser_table(void);
void					parse_ambient_lightning(char *str, t_node *head);
void					parse_camera(char *str, t_node *head);
int						parse_file(char *file);
void					intersect_caps(const t_cylinder *cyl, const t_ray r,
							t_node **head);
t_node					*intersection(double point, t_shape **obj);
void					add_three_tuples(t_tuple ambient, t_tuple diffuse,
							t_tuple specular, t_tuple result);
t_bool					is_shadowed(t_world *w, t_tuple p);
void					add_object(t_world *w, t_shape *new_obj, int index);
t_material				create_plane_material(void);

static inline void	print_tuple(const t_tuple a)
{
	printf("X: %f, Y: %f, Z: %f, W: %d\n", a.x, a.y, a.z, a.w);
}

static inline void	print_4x4matrix(const t_matrix a)
{
	print_tuple(a.row_1);
	print_tuple(a.row_2);
	print_tuple(a.row_3);
	print_tuple(a.row_4);
}

#endif
