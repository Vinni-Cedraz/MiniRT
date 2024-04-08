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

# define ROW1 0
# define ROW2 1
# define ROW3 2
# define ROW4 3

# define COL1 0
# define COL2 1
# define COL3 2
# define COL4 3

# define ROW 0
# define COL 1

# define END_MATRIX -__INT_MAX__
# define ERROR -42

# define DEFAULT -1
# define AMBIENT 0
# define DIFFUSE 1
# define SPECULAR 2
# define SHININESS 3
# define SIZEH 500
# define SIZEW 500
# define CYAN "\033[36m"
# define RED "\033[31m"
# define RESET "\033[0m"

typedef double			t_four_doubles[4];
typedef double			t_3x3_row[3];
typedef double			t_2x2_row[2];
typedef _Bool			t_bool;
typedef unsigned short	t_short;
typedef					void(t_parse_table)(char *, t_node *);

typedef enum e_enum
{
	SPHERE,
	PLANE,
	CYLINDER,
}						t_type;

typedef struct s_tuple
{
	double				x;
	double				y;
	double				z;
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
	double				grid[4][4];
	short				size;
}						t_matrix;

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
}						t_intersections;

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
	t_tuple				dis_to_ray;
	t_tuple				origin;
	_Bool 				radius;
	int					id;
	t_type				type;
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

typedef t_intersections	(*t_intersect_function)(t_shape **, t_tuple);
typedef void			(*t_normal_at_function)(const t_shape *, const t_tuple,
				t_tuple);

t_tuple					create_point(float x, float y, float z);
void					tuple_to_arr(t_tuple a, double arr[4]);
t_tuple					create_vector(float x, float y, float z);
t_tuple					create_tuple(float x, float y, float z, short w);
t_bool					doubles_eq(double a, double b);
t_tuple					add_tuples(const t_tuple a, const t_tuple b);
t_tuple					subtract_tuples(const t_tuple a, const t_tuple b);
t_tuple					negate_tuple(const t_tuple a);
t_tuple					multiply_tuple_by_scalar(const t_tuple a,
							const double scalar);
// this implementation my create an issue in the future
t_tuple					multiply_tuple_by_matrix(t_tuple a, t_matrix b);
void					multiply_colors(const t_tuple c1, const t_tuple c2,
							t_tuple result);
t_bool					doubles_eq(double a, double b);
double					magnitude(const t_tuple vec);
t_tuple					normalize(const t_tuple vec);
short					is_point(short w);
t_bool					is_invertible(t_matrix m);
t_matrix				invert_matrix(t_matrix m);
t_tuple					cross(const t_tuple a, const t_tuple b);
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
double					_determinant(const t_matrix m);
t_bool					tuples_neq(const double *result, const double *expected,
							int len);
t_matrix				create_translation_matrix(t_tuple point);
// ALWAYS USE END_MATRIX WITH THE create_matrix FUNCTION!!!!!!!!!!!!!!!!!
t_matrix				create_matrix(double arr_mat[]);
t_matrix				create_x_rotation_matrix(double r);
t_matrix				create_y_rotation_matrix(double r);
t_matrix				create_z_rotation_matrix(double r);
t_matrix				_submatrix(const t_matrix m, int row_to_del,
							int col_to_del);
double					_minor(const t_matrix m, int row, int col);
t_matrix				create_scaling_matrix(const double x, const double y,
							const double z);
t_matrix				chain_transformations(t_matrix trix[]);
void					translate_coordinate(t_four_doubles point,
							t_canvas *canvas, t_four_doubles res);
t_tuple					_intersection_coordinates(t_ray ray, double t);
t_ray					create_ray(t_tuple origin, t_tuple direction);
t_sphere				create_sphere(void);
t_bool					tuples_eq(const t_tuple result, const t_tuple expected);
t_intersections			intersect_sphere(t_sphere *obj, t_ray r);
t_intersections			link_intersection_nodes(t_node *arr[]);
t_node					get_hit(t_intersections i);
t_matrix				create_identity_matrix(void);
t_ray					transform_ray(t_ray ray, t_matrix matrix);
void					set_transform(t_shape *s, t_matrix t);
double					_cofac(const t_matrix m, int row, int col);
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
t_intersections			intersect_world_with_ray(t_world *w, t_ray *r);
t_prep_comps			prepare_computations(t_node *intersection, t_ray ray);
void					shade_hit(t_world *world, t_prep_comps *comps,
							t_tuple result);
void					init_tuple(const t_tuple tuple, t_tuple res);
void					color_at(t_world *world, t_ray *ray, t_tuple color);
t_matrix				view_transform(t_tuple from, t_tuple forward,
							t_tuple up);
t_camera				create_camera(int hsize, int vsize,
							double field_of_view);
t_matrix				create_mat(double arr[]);

t_ray					ray_for_pixel(t_camera c, int x, int y);
t_canvas				render(t_camera camera, t_world world);
// t_intersection			intersect_sphere(t_sphere *obj, t_tuple obj_dist_ray);
t_intersections			intersect_plane(t_shape **obj, t_tuple dist);
t_intersections			intersect_cylinder(t_shape **obj,
							t_tuple obj_dist_to_ray);
t_plane					create_plane(void);
t_cylinder				create_cylinder(void);
double					_discriminant(t_tuple obj_dist_ray, t_ray ray,
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
t_matrix				tuple_to_matrix(t_tuple tuple);

static inline void	print_tuple(const t_tuple a)
{
	printf("X: %f, Y: %f, Z: %f, W: %d\n", a.x, a.y, a.z, a.w);
}

static inline void	print_matrix(t_matrix mat)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < mat.size)
	{
		j = -1;
		while (++j < mat.size)
			printf("%f ", mat.grid[i][j]);
		printf("\n");
	}
}

#endif
