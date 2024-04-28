/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:09:38 by vcedraz-          #+#    #+#             */
/*   Updated: 2024/04/20 19:30:57 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libs/libft.h"
# include "../libs/libft_bonus.h"
# include <float.h>
# include <math.h>
# include <stdio.h>

static const char			types[6][20] = {"AMBIENT", "CAMERA", "LIGHT",
				"SPHERE", "PLANE", "CYLINDER"};

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
# define NUM_THREADS 10

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

# define END_MATRIX -DBL_MAX
# define ERROR -42

# define SIZEH 900
# define SIZEW 1280
# define CYAN "\033[36m"
# define RED "\033[31m"
# define RESET "\033[0m"

typedef double				t_four_doubles[4];
typedef double				t_3x3_row[3];
typedef double				t_2x2_row[2];
typedef _Bool				t_bool;
typedef unsigned short		t_short;

typedef enum e_typ
{
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
}							t_type;

typedef struct s_tuple
{
	double					x;
	double					y;
	double					z;
	double					w;
}							t_tuple;

typedef struct s_token
{
	t_type					type;
	char					args[5][30];
}							t_token;

typedef struct s_checker
{
	t_type					identifier;
	short					counters[3];
	t_split					*splitted;
	char					*line;
	int						fd;
}							t_checker;

typedef struct s_tokenizer
{
	t_split					*splitted;
	char					*line;
	int						fd;
	t_token					*tokens;
}							t_tokenizer;

typedef struct s_matrix
{
	double					grid[4][4];
	short					size;
}							t_matrix;

typedef struct s_ray
{
	t_tuple					origin;
	t_tuple					direction;
}							t_ray;

typedef struct s_point_light
{
	t_tuple					position;
	t_tuple					intensity;
}							t_point_light;

typedef struct s_material
{
	double					ambi;
	double					dffse;
	double					specular;
	double					shiny;
	t_tuple					color;
}							t_material;

typedef struct s_colors
{
	t_tuple					diffuse;
	t_tuple					reflectv;
	t_tuple					true_colr;
	t_tuple					lightv;
	t_tuple					ambient;
	t_tuple					specular;
}							t_colors;

typedef struct s_lighting
{
	t_material				material;
	t_point_light			light;
	t_tuple					point;
	t_tuple					eye_vec;
	t_tuple					normal_vec;
	t_tuple					wrld_ambien;
	t_bool					in_shadow;
}							t_lighting;

typedef struct s_types_of_lighting
{
	t_tuple					a;
	t_tuple					d;
	t_tuple					s;
	double					light_dot_normal;
	double					reflect_dot_eye;
	double					factor;
	t_tuple					effective_color;
	t_tuple					lightv;
	t_tuple					reflectv;
}							t_type_light;

typedef struct s_intersections
{
	t_node					*head;
	t_short					count;
}							t_intersections;

typedef t_intersections		(*t_intersect_function)(const t_shape *,
			const t_ray *, const t_tuple);
typedef t_tuple				(*t_normal_at_function)(const t_shape *,
					const t_tuple);

typedef struct s_shape
{
	t_matrix				_t;
	t_matrix				inverse_t;
	t_matrix				trans_inv;
	t_type					type;
	t_tuple					origin;
	t_material				material;
	double					min;
	double					max;
	t_bool					closed;
	t_ray					r;
	_Bool					radius;
	t_intersect_function	intersect;
	t_normal_at_function	normal_at;
}							t_shape;

typedef struct s_baskara
{
	double					a;
	double					b;
	double					c;
}							t_bhaskara;

typedef struct s_comp
{
	double					t;
	const t_shape			*shape;
	t_tuple					over_point;
	t_tuple					point;
	t_tuple					eyev;
	t_tuple					normalv;
	t_bool					inside;
}							t_prep_comps;

typedef struct s_camera
{
	int						vsize;
	int						hsize;
	double					half_width;
	double					half_height;
	double					field_of_view;
	t_matrix				transform;
	t_matrix				cam_inv_trans;
	double					pixel_size;
	double					xoffset;
	double					yoffset;
	double					world_x;
	double					world_y;
	t_tuple					up;
}							t_camera;

typedef struct s_world
{
	t_shape					*shapes;
	t_point_light			lights[4];
	t_camera				camera;
	t_tuple					parser_ambient;
	int						fixed_count;
	int						moving_idx;
	short					nb_of_lights;
	mlx_image_t				*image;
}							t_world;

typedef struct s_task
{
	int			id;
	int			start_idx;
	int			end_idx;
	t_world		*world;
	t_camera	camera;
	mlx_image_t	*image;
	pthread_mutex_t	mutex;
}				t_task;

typedef						int(t_parse_table)(t_token token, t_world *);

t_tuple						create_point(double x, double y, double z);
void						tuple_to_arr(t_tuple a, double arr[4]);
t_tuple						create_vector(double x, double y, double z);
t_tuple						create_tuple(double x, double y, double z,
								double w);
t_bool						doubles_eq(double a, double b);
t_tuple						add_tuples(const t_tuple a, const t_tuple b);
t_tuple						subtract_tuples(const t_tuple a, const t_tuple b);
t_tuple						negate_tuple(const t_tuple a);
t_tuple						multiply_tuple_by_scalar(const t_tuple a,
								const double scalar);
// this implementation my create an issue in the future
t_tuple						multiply_tuple_by_matrix(t_tuple a, t_matrix b);
t_tuple						multiply_colors(const t_tuple a, const t_tuple b);
t_bool						doubles_eq(double a, double b);
double						magnitude(const t_tuple vec);
t_tuple						normalize(const t_tuple vec);
uint32_t					normalized_color_to_int(t_tuple color);
short						is_point(short w);
t_bool						is_invertible(t_matrix m);
t_matrix					invert_matrix(t_matrix m);
t_tuple						cross(const t_tuple a, const t_tuple b);
t_matrix					mult_matrices(t_matrix a, t_matrix b);
t_bool						matrices_eq(t_matrix a, t_matrix b);
double						dot(const t_tuple a, const t_tuple b);
t_matrix					mult_by_identity(t_matrix a);
t_matrix					transpose_matrix(t_matrix a);
double						_determinant(const t_matrix m);
t_bool						tuples_neq(const double *result,
								const double *expected, int len);
t_matrix					create_translation_matrix(t_tuple point);
// ALWAYS USE END_MATRIX WITH THE create_matrix FUNCTION!!!!!!!!!!!!!!!!!
t_matrix					create_matrix(double arr_mat[]);
t_matrix					create_x_rotation_matrix(double r);
t_matrix					create_y_rotation_matrix(double r);
t_matrix					create_z_rotation_matrix(double r);
t_matrix					_submatrix(const t_matrix m, int row_to_del,
								int col_to_del);
double						_minor(const t_matrix m, int row, int col);
t_matrix					create_scaling_matrix(const double x,
								const double y, const double z);
t_matrix					chain_transformations(t_matrix trix[]);
t_tuple						_intersection_coordinates(t_ray ray, double t);
t_ray						create_ray(t_tuple origin, t_tuple direction);
t_shape						create_sphere(void);
t_bool						tuples_eq(const t_tuple result,
								const t_tuple expected);
void						link_intersection_nodes(t_node *head1,
								t_node *head2);
t_node						_hit(t_intersections intersections);
t_matrix					create_identity_matrix(void);
t_ray						transform_ray(const t_ray *ray, t_matrix matrix);
void						set_transform(t_shape *s, t_matrix t);
double						_cofac(const t_matrix m, int row, int col);
t_tuple						sphere_normal_at(const t_shape *sphere,
								const t_tuple world_point);
t_tuple						plane_normal_at(const t_shape *sphere,
								const t_tuple p);
void						cylinder_normal_at(const t_shape *cyl,
								const t_tuple p, t_tuple res);
t_tuple						reflect(t_tuple vector, t_tuple normal);
t_material					create_material(void);
t_tuple						calculate_lighting(t_lighting l);
t_constr					make_aslib_test(void);
t_world						create_world(void);
t_world						default_world(void);
void						set_material(t_tuple reflections, t_tuple color,
								t_material *m);
t_intersections				intersect_world_with_ray(t_world *w, const t_ray *r);
t_prep_comps				prepare_computations(const t_node *intersection,
								t_ray ray);
t_tuple						shade_hit(t_world *world, t_prep_comps *comps);
void						init_tuple(const t_tuple tuple, t_tuple res);
t_tuple						color_at(t_world *w, const t_ray *r);
t_matrix					view_transform(t_tuple from, t_tuple forward,
								t_tuple up);
t_camera					create_camera(int hsize, int vsize,
								double field_of_view);
t_matrix					create_mat(double arr[]);

t_ray						ray_for_pixel(t_camera c, int idx);
void						render(t_world world);
t_intersections				intersect_plane(const t_shape *obj,
								const t_ray *trans_ray, const t_tuple d);
t_intersections				intersect_cylinder(const t_shape *obj,
								const t_ray *transformed_ray, const t_tuple d);
t_intersections				intersect_sphere(const t_shape *obj,
								const t_ray *transformed_ray, const t_tuple d);
t_shape						create_plane(void);
t_shape						create_cylinder(void);
void						set_cyl_min_max(t_shape *cyl, double min,
								double max);
void						load_objs_into_world(mlx_image_t *image,
								t_camera camera, t_world *world);
mlx_image_t					*create_image(mlx_t *mlx);
void						render_a_default_world(mlx_t *mlx);
int							endwith(char *str, char *end);
int							parse_ambient(t_token token, t_world *w);
int							parse_sphere(t_token token, t_world *w);
int							parse_plane(t_token token, t_world *w);
int							parse_light(t_token token, t_world *w);
int							parse_cylinder(t_token token, t_world *w);
int							parse_camera(t_token token, t_world *w);
t_parse_table				**parse_functions(void);
int							parse_file(char *file);
void						intersect_caps(const t_shape *cyl, const t_ray r,
								t_node **head);
t_tuple						add_three_tuples(t_tuple a, t_tuple d, t_tuple s);
t_bool						is_shadowed(t_world *w, t_tuple p, t_point_light light);
void						add_object(t_world *w, t_shape *new_obj, int index);
t_material					create_plane_material(void);
t_matrix					tuple_to_matrix(t_tuple tuple);
void						check_unique_type_identifiers(t_checker *c);
void						check_type_identifiers(t_checker *checker);
void						free_and_exit_error(char *line, t_split *splitted,
								int fd);
int							open_file(char *file);
t_token						*tokenizer(int fd, int number_of_tokens);
void						validate_line(char *line, t_split *splitted,
								int fd);
// this function validates the file AND returns the number of lights in the file
short						file_validation(int fd, int *valid_lines);
void						parse_tokens_into_world(t_token *tokens,
								int nb_of_tokens, t_world *w);
t_tuple						parse_tuple(char *str, short type);
int							is_a_normalized_vector(t_tuple result);
double						parse_double(char *str, _Bool is_fov);
t_bool						low_precision_doubles_eq(double a, double b);
t_tuple						normalize_color(const t_tuple a);
double						_discriminant(t_tuple obj_dist_ray,
								const t_ray *ray, t_bhaskara *bask);
t_intersections				intersect_shape(const t_shape *obj, const t_ray *r);
t_matrix					plane_view_transform(t_tuple from, t_tuple up);
void						ft_mlx_draw_pixel(uint8_t *pixel, uint32_t color);

static inline void	print_tuple(const t_tuple a)
{
	printf("X: %f, Y: %f, Z: %f, W: %f\n", a.x, a.y, a.z, a.w);
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
